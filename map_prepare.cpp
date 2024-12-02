#include "map_prepare.h"

vector<int> compute_convex_hull(vector<my_vec3f> &points);

vector<my_vec3f> read_map(const string &map_filename, const string &map_info_file) {
    ifstream info_in(map_info_file);
    if (!info_in.is_open()) {
        throw exception();
    }
    string rows_cnt_string, cols_cnt_string;
    for (int i = 0; i < ROWS_CNT_STRING; ++i)
        getline(info_in, rows_cnt_string);
    getline(info_in, cols_cnt_string);
    string cnt_rows_str = rows_cnt_string.substr(VALUE_POS), cnt_cols_str = cols_cnt_string.substr(VALUE_POS);
    int cnt_rows = stoi(cnt_rows_str), cnt_cols = stoi(cnt_cols_str);
    cout << cnt_rows << " " << cnt_cols << '\n';
    vector<my_vec3f> map(cnt_rows * cnt_cols);
    ifstream map_in(map_filename, ios::in | ios::binary);
    if (!map_in.is_open())
        throw exception();
    float height;
    for (int i = 0; i < cnt_rows; ++i)
        for (int j = 0; j < cnt_cols; ++j) {
            map_in.read((char *) &height, sizeof(float));
            map[i * cnt_cols + j].setX(j * METERS_PER_POINT);
            map[i * cnt_cols + j].setY(i * METERS_PER_POINT);
            map[i * cnt_cols + j].setZ(height);
        }
    return map;
}

vector<textured_triangle> read_stl(const string &filename) {
//    set<float> xs, ys, zs;

    ifstream in(filename, ios_base::in | ios_base::binary);
    uint32_t n;
    in.seekg(80, ios_base::beg);
    in.read((char *) &n, sizeof(n));
    cout << n << '\n';

    vector<textured_triangle> triangles(n);
    array<my_vec3f, 3> vertices;
    float x, y, z;
    bool normal = false;
    int cnt = 0;

    for (int i = 0; i < n; ++i, ++cnt) {
        in.read((char *) &x, sizeof(x));
        in.read((char *) &y, sizeof(y));
        in.read((char *) &z, sizeof(z));
        if (x != 0 || y != 0 || z != 0) {
            normal = true;
        }
        triangles[i].t.n = {x, y, z};

        for (int j = 0; j < 3; ++j) {
            in.read((char *) &x, sizeof(x));
            in.read((char *) &y, sizeof(y));
            in.read((char *) &z, sizeof(z));
            vertices[j].setX(x), vertices[j].setY(y), vertices[j].setZ(z);
//            xs.insert(x), ys.insert(y), zs.insert(z);
        }
        const_cast<triangle &>(triangles[i].getT()).setVertices(vertices);
        in.seekg(2, ios_base::cur);
    }
    cout << "readed " << cnt << '\n';
    cout << "cnt x " << xs.size() << "\ncnt y " << ys.size() << "\ncnt z " << zs.size() << "\n";
    in.close();

    if (!normal) {
        cout << "calculate normals\n";
        float max_x, min_x, max_y, min_y, max_z, min_z;
        max_x = max_y = max_z = -1e9;
        min_x = min_y = min_z = 1e9;
        for (auto &triangle: triangles) {
            for (auto &p: triangle.t.getVertices()) {
                max_x = max(max_x, p.getX()), min_x = min(min_x, p.getX());
                max_y = max(max_y, p.getY()), min_y = min(min_y, p.getY());
                max_z = max(max_z, p.getZ()), min_z = min(min_z, p.getZ());
            }
        }
        my_vec3f center((max_x - min_x) / 2, (max_y - min_y) / 2, (max_z - min_z) / 2);
//    in.close();
        fstream out(filename, ios_base::out | ios_base::in | ios_base::binary);
        out.seekp(0);
        out.seekp(84, ios_base::beg);
        for (auto &triangle: triangles) {
            vertices = triangle.t.getVertices();
            my_vec3f center_1 = vertices[0] - center,
                    center_2 = vertices[1] - center,
                    center_3 = vertices[2] - center;
            my_vec3f a = vertices[1] - vertices[0], b = vertices[2] - vertices[0];
            my_vec3f v_n = a.cross(b);
//            if (bool(v_n.dot(center_1) > 0) + bool(v_n.dot(center_2) > 0) + bool(v_n.dot(center_3) > 0) < 2)
//                v_n = b.cross(a);
            v_n.normalize();
            triangle.t.setN(v_n);
            float n_x = v_n.getX(), n_y = v_n.getY(), n_z = v_n.getZ();
            out.write((char *) &n_x, sizeof(n_x));
            out.write((char *) &n_y, sizeof(n_y));
            out.write((char *) &n_z, sizeof(n_z));
            out.seekp(38, ios_base::cur);
        }
        out.seekp(0, ios_base::end);
        out.close();
    }
    return triangles;
}


set<set<int>> stupid_delaunay_triangulate(vector<my_vec3f> &points) {
    set<set<int>> triangles;
    for (int i = 0; i < points.size() - 2; ++i) {
        int min_d_ind = i + 1, s_min_d_ind = i + 2;
        float min_d = points[i].distance(points[min_d_ind]), s_min_d = points[i].distance(points[s_min_d_ind]), tmp;
        for (int j = 0; j < points.size() - 1; ++j) {
            if (j != i) {
                tmp = points[i].distance(points[j]);
                if (tmp < min_d) {
                    min_d = tmp, min_d_ind = j;
                }
            }
        }
        for (int j = 0; j < points.size(); ++j) {
            if (j != i && j != min_d_ind) {
                tmp = points[i].distance(points[j]);
                if (tmp < s_min_d) {
                    s_min_d = tmp;
                    s_min_d_ind = j;
                }
            }
        }
        triangles.insert({i, min_d_ind, s_min_d_ind});
    }
    return triangles;
}