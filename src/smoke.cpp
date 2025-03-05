//
// Created by ivan on 17.02.25.
//

#include "smoke.h"
#include <fstream>
#include <ctime>

ofstream out;

timespec start, stop, eq_start, eq_stop;

float lin_solve_time = 0;


void smoke::add_source(vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &s, float d) {
#pragma omp parallel for
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < x[i].size(); ++j) {
            for (int k = 0; k < x[i][j].size(); ++k) {
                x[i][j][k] += d * s[i][j][k];
            }
        }
    }
}

//1 - x, 2 - y, 3-z
//zxy
void smoke::set_bnd(int b, vector<vector<vector<float>>> &x) {
#pragma omp parallel for
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j <= width; ++j) {
            float tmp = x[height + 1][i][j];
            x[height + 1][i][j] = b == 3 ? x[0][i][j] : x[height][i][j];
            x[0][i][j] = b == 3 ? tmp : x[1][i][j];
        }
    }
    //left-right face
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height; ++j) {
            float tmp = x[i][j][0];
            x[i][j][0] = (b == 1 ? x[i][j][width + 1] : x[i][j][1]);
            x[i][j][width + 1] = (b == 1 ? tmp : x[i][j][width]);
        }
    }
    //front-back face
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            float tmp = x[i][0][j];
            x[i][0][j] = (b == 2 ? x[i][height + 1][j] : x[i][1][j]);
            x[i][height + 1][j] = (b == 2 ? tmp : x[i][height][j]);
        }
    }
    //edges
    for (int i = 1; i <= height; i++) {
        x[i][0][0] = 1.0 / 2.0 * (x[i][1][0] + x[i][0][1]);
        x[i][height + 1][0] = 1.0 / 2.0 * (x[i][height + 1][0] + x[i][height + 1][1]);
        x[i][0][width + 1] = 1.0 / 2.0 * (x[i][0][width] + x[i][1][width + 1]);
        x[i][height + 1][width + 1] = 1.0 / 2.0 * (x[i][height][width + 1] + x[i][height + 1][width]);
    }

    for (int i = 1; i <= height; i++) {
        x[0][i][0] = 1.0 / 2.0 * (x[1][i][0] + x[0][i][1]);
        x[height + 1][i][0] = 1.0 / 2.0 * (x[height][i][0] + x[width + 1][i][1]);
        x[0][i][width + 1] = 1.0 / 2.0 * (x[0][i][width] + x[1][i][width + 1]);
        x[height + 1][i][width + 1] = 1.0 / 2.0 * (x[height][i][width + 1] + x[height + 1][i][width]);
    }

    for (int i = 1; i <= width; i++) {
        x[0][0][i] = 1.0 / 2.0 * (x[0][1][i] + x[1][0][i]);
        x[0][height + 1][i] = 1.0 / 2.0 * (x[0][height][i] + x[1][height + 1][i]);
        x[height + 1][0][i] = 1.0 / 2.0 * (x[height][0][i] + x[height + 1][1][i]);
        x[height + 1][height + 1][i] = 1.0 / 2.0 * (x[height + 1][height][i] + x[height][height + 1][i]);
    }

    //setting corners
    x[0][0][0] = 1.0 / 3.0 * (x[1][0][0] + x[0][1][0] + x[0][0][1]);
    x[0][height + 1][0] = 1.0 / 3.0 * (x[1][height + 1][0] + x[0][height][0] + x[0][height + 1][1]);

    x[height + 1][0][0] = 1.0 / 3.0 * (x[height][0][0] + x[height + 1][1][0] + x[height + 1][0][1]);
    x[height + 1][height + 1][0] =
            1.0 / 3.0 * (x[height][height + 1][0] + x[height + 1][height][0] + x[height + 1][height + 1][1]);

    x[0][0][width + 1] = 1.0 / 3.0 * (x[1][0][width + 1] + x[0][1][width + 1] + x[0][0][width]);
    x[0][height + 1][width + 1] =
            1.0 / 3.0 * (x[1][height + 1][width + 1] + x[0][height][width + 1] + x[0][height + 1][width]);

    x[height + 1][0][width + 1] =
            1.0 / 3.0 * (x[height][0][width + 1] + x[height + 1][1][width + 1] + x[height + 1][0][width]);
    x[height + 1][height + 1][width + 1] = 1.0 / 3.0 *
                                           (x[height][height + 1][width + 1] + x[height + 1][height][width + 1] +
                                            x[height + 1][height + 1][width]);
}


void smoke::lin_solve(int b, vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, float a, float c) {
    int i, j, iter;
#pragma omp parallel for
    for (iter = 0; iter < 5; iter++) {
        for (i = 1; i <= height; i++) {
            for (j = 1; j <= height; j++) {
                for (int k = 1; k <= width; ++k) {
                    x[i][j][k] = (x0[i][j][k] + a * (x[i - 1][j][k] + x[i + 1][j][k] + x[i][j - 1][k] + x[i][j + 1][k] +
                                                     x[i][j][k - 1] + x[i][j][k + 1])) / c;

                }
            }
        }
        set_bnd(b, x);
    }
}

void smoke::diffuse(int b, vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, float diff, float d) {
    float a = d * diff * height * height * width;
    // clock_gettime(CLOCK_MONOTONIC, &eq_start);
    lin_solve(b, x, x0, a, 1 + 6 * a);
    // clock_gettime(CLOCK_MONOTONIC, &eq_stop);
    lin_solve_time += eq_stop.tv_sec - eq_start.tv_sec + (eq_stop.tv_nsec - eq_start.tv_nsec) * 1e-9;
}

void smoke::advect(int b, vector<vector<vector<float>>> &d, vector<vector<vector<float>>> &d0,
                   vector<vector<vector<float>>> &u_, vector<vector<vector<float>>> &v_,
                   vector<vector<vector<float>>> &w_,
                   float dt_) {
    int i, j, i0, j0, k0, i1, j1, k1;
    float x, y, z, s0, t0, s1, t1, dt0, u1, u0;

    dt0 = dt_ * max(height, width);
#pragma omp parallel for
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height; j++) {
            for (int k = 1; k <= width; ++k) {
                x = i - dt0 * w_[i][j][k];
                y = j - dt0 * u_[i][j][k];
                z = k - dt0 * v_[i][j][k];
                if (x < 0.5f) x = 0.5f;
                if (x > height + 0.5f) x = height + 0.5f;
                i0 = (int) x;
                i1 = i0 + 1;

                if (y < 0.5f) y = 0.5f;
                if (y > height + 0.5f) y = height + 0.5f;
                j0 = (int) y;
                j1 = j0 + 1;

                if (z < 0.5f) z = 0.5f;
                if (z > width + 0.5f) z = width + 0.5f;
                k0 = (int) z;
                k1 = k0 + 1;

                s1 = x - i0;
                s0 = 1 - s1;

                t1 = y - j0;
                t0 = 1 - t1;

                u1 = z - k0;
                u0 = 1 - u1;
                d[i][j][k] = s0 * (t0 * u0 * d0[i0][j0][k0] + t1 * u0 * d0[i0][j1][k0] + t0 * u1 * d0[i0][j0][k1] +
                                   t1 * u1 * d0[i0][j1][k1]) + s1 * (t0 * u0 * d0[i1][j0][k0] +
                                                                     t1 * u0 * d0[i1][j1][k0] +
                                                                     t0 * u1 * d0[i1][j0][k1] +
                                                                     t1 * u1 * d0[i1][j1][k1]);
            }
        }
    }
    set_bnd(b, d);
}

void
smoke::project(vector<vector<vector<float>>> &u_, vector<vector<vector<float>>> &v_, vector<vector<vector<float>>> &w_,
               vector<vector<vector<float>>> &p, vector<vector<vector<float>>> &div) {
    int i, j;
#pragma omp parallel for
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height; j++) {
            for (int k = 1; k <= width; ++k) {
                div[i][j][k] = -1.0 / 3.0 *
                               ((u_[i + 1][j][k] - u_[i - 1][j][k]) / height +
                                (v_[i][j + 1][k] - v_[i][j - 1][k]) / height +
                                (w_[i][j][k + 1] - w_[i][j][k - 1]) / width);
                p[i][j][k] = 0;
            }
        }
    }
    set_bnd(0, div);
    set_bnd(0, p);

    lin_solve(0, p, div, 1, 6);
#pragma omp parallel for
    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height; j++) {
            for (int k = 1; k <= width; ++k) {
                u_[i][j][k] -= 1.f / 3.f * height * (p[i + 1][j][k] - p[i - 1][j][k]);
                v_[i][j][k] -= 1.f / 3.f * height * (p[i][j + 1][k] - p[i][j - 1][k]);
                w_[i][j][k] -= 1.f / 3.f * width * (p[i][j][k + 1] - p[i][j][k - 1]);
            }
        }
    }
    set_bnd(1, u_);
    set_bnd(2, v_);
    set_bnd(3, w_);
}

void
smoke::dens_step(vector<vector<vector<float>>> &x, vector<vector<vector<float>>> &x0, vector<vector<vector<float>>> &u_,
                 vector<vector<vector<float>>> &v_, vector<vector<vector<float>>> &w_, float d, float diff) {
    // clock_gettime(CLOCK_MONOTONIC, &start);
    add_source(x, x0, d);
    // clock_gettime(CLOCK_MONOTONIC, &stop);
    // out << stop.tv_sec - start.tv_sec + (stop.tv_nsec - start.tv_nsec) * 1e-9 << ",";
    x0.swap(x);
    // clock_gettime(CLOCK_MONOTONIC, &start);
    diffuse(0, x, x0, diff, d);
    // out << (stop.tv_sec - start.tv_sec) - (eq_stop.tv_sec - eq_start.tv_sec) +
    //       (stop.tv_nsec - start.tv_nsec - eq_stop.tv_nsec + eq_start.tv_nsec) * 1e-9 << ",";
    // out << eq_stop.tv_sec - eq_start.tv_sec + (eq_stop.tv_nsec - eq_start.tv_nsec) * 1e-9 << ',';
    x0.swap(x);
    // clock_gettime(CLOCK_MONOTONIC, &start);
    advect(0, x, x0, u_, v_, w_, d);
    // clock_gettime(CLOCK_MONOTONIC, &stop);
    // out << stop.tv_sec - start.tv_sec + (stop.tv_nsec - start.tv_nsec) * 1e-9 << "\n";
}

void
smoke::vel_step(vector<vector<vector<float>>> &u_, vector<vector<vector<float>>> &v_, vector<vector<vector<float>>> &w_,
                vector<vector<vector<float>>> &v0, vector<vector<vector<float>>> &u0, vector<vector<vector<float>>> &w0,
                float visc, float d) {
    // clock_gettime(CLOCK_MONOTONIC, &start);
    add_source(u_, u0, d);
    add_source(v_, v0, d);
    add_source(w_, w0, d);
    // clock_gettime(CLOCK_MONOTONIC, &stop);
    // out << stop.tv_sec - start.tv_sec + (stop.tv_nsec - start.tv_nsec) * 1e-9 << ",";
//    lin_solve_time = 0;
//    clock_gettime(CLOCK_MONOTONIC, &start);
    u0.swap(u_);
    diffuse(1, u_, u0, visc, d);
    v0.swap(v_);
    diffuse(2, v_, v0, visc, d);
    w0.swap(w_);
    diffuse(3, w_, w0, visc, d);
    // clock_gettime(CLOCK_MONOTONIC, &stop);
    // out << (stop.tv_sec - start.tv_sec) +
    //   (stop.tv_nsec - start.tv_nsec) * 1e-9 - lin_solve_time << ",";
    // out << lin_solve_time << ',';
    project(u_, v_, w_, u0, v0);
    u0.swap(u_);
    v0.swap(v_);
    w0.swap(w_);
    // clock_gettime(CLOCK_MONOTONIC, &start);
    advect(1, u_, u0, u0, v0, w0, d);
    advect(2, v_, v0, u0, v0, w0, d);
    advect(3, w_, w0, u0, v0, w0, d);
    // clock_gettime(CLOCK_MONOTONIC, &stop);
    // out << stop.tv_sec - start.tv_sec + (stop.tv_nsec - start.tv_nsec) * 1e-9 << ",";
    project(u_, v_, w_, u0, v0);
}

void smoke::update() {
    // out.open("time_parallel.csv", ios_base::app);
    if (frames_counter < total_frames) {
        for (int i = static_cast<int>(source.z); i < static_cast<int>(source.z) + 1; ++i) {
            for (int j = static_cast<int>(source.x); j < static_cast<int>(source.x) + 1; ++j) {
                for (int k = static_cast<int>(source.y);
                     k < static_cast<int>(source.y) + 1; ++k) {
                    dens_prev[i][j][k] = intensity;
                }
            }
        }
        for (int i = static_cast<int>(source.z) - 1; i < static_cast<int>(source.z) + 2; ++i) {
            for (int j = static_cast<int>(source.x) - 1; j < static_cast<int>(source.x) + 2; ++j) {
                for (int k = static_cast<int>(source.y) - 1;
                     k < static_cast<int>(source.y) + 2; ++k) {
                    w_prev[i][j][k] -= v_initial;
                }
            }
        }
    }
    ++frames_counter;
    vel_step(u, v, w, v_prev, u_prev, w_prev, VISC, dt);
    dens_step(dens, dens_prev, u, v, w, dt, DIFF_COEF);
#pragma omp parallel for
    for (int i = 0; i < height + 2; ++i) {
        for (int j = 0; j < height + 2; ++j) {
            for (int k = 0; k < width + 2; ++k) {
                u_prev[i][j][k] = v_prev[i][j][k] = w_prev[i][j][k] = 0;
                dens_prev[i][j][k] = 0;
            }
        }
    }
    float max_v_vel = 0, max_u_vel = 0, max_w_vel = 0;
//#pragma omp parallel for
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j < height + 1; ++j) {
            for (int k = 1; k < width + 1; ++k) {
                max_v_vel = max(max_v_vel, abs(v[i][j][k])), max_u_vel = max(max_u_vel,
                                                                             abs(u[i][j][k])), max_w_vel = max(
                        max_w_vel, abs(w[i][j][k]));
            }
        }
    }
    cout << "max v " << max_v_vel << " max u " << max_u_vel << " max w "<<max_w_vel<<'\n';
    // out.close();
}

smoke::smoke(int grid_width, int grid_height, const glm::vec3 &crater, const glm::vec2 &wind_, float dt_,
             int frames_count, float intensity_, float vertical_speed) :
        width(grid_width / VOX_SIZE), height(grid_height / VOX_SIZE),
        source({crater.x / VOX_SIZE, crater.y / VOX_SIZE, crater.z / VOX_SIZE}), wind(wind_), dt(dt_),
        u(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        v(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        w(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        u_prev(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        v_prev(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        w_prev(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        dens(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        dens_prev(height + 2, vector<vector<float>>(height + 2, vector<float>(width + 2, 0.f))),
        total_frames(frames_count), frames_counter(0), intensity(intensity_), v_initial(vertical_speed) {
#pragma omp parallel for
    for (int i = 0; i < height + 2; ++i) {
        for (int j = 0; j < height + 2; ++j) {
            for (int k = 0; k < width + 2; ++k) {
                u_prev[i][j][k] = wind.y;
                v_prev[i][j][k] = wind.x;
                w_prev[i][j][k] = -0.5;
            }
        }
    }
}


