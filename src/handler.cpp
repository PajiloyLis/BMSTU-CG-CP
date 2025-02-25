#include "handler.h"

TaskHandler::TaskHandler() : scene() {}

void TaskHandler::SetScene(const Scene &scene_to_set) {
    scene = scene_to_set;
}

void TaskHandler::DrawScene() {
    scene.ClearScene();
    scene.DrawFigures();
//    scene.DrawSmoke();
    scene.Show();
}

void TaskHandler::ClearScene() const {
    scene.ClearScene();
}

void TaskHandler::LoadModel(const string &filepath) {
    // Add mount
    scene.AddFigure(figure(read_stl(filepath)));
    // Add smoke
    scene.AddSmoke();
}

vector<triangle> TaskHandler::read_stl(const string &filename) {
    ifstream in(filename, ios_base::in | ios_base::binary);
    uint32_t n;
    in.seekg(80, ios_base::beg);
    in.read((char *) &n, sizeof(n));
    cout << n << '\n';

    vector<triangle> triangles(n);
    array<glm::vec3, 3> vertices;
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
        triangles[i].setN({x, y, z});

        for (int j = 0; j < 3; ++j) {
            in.read((char *) &x, sizeof(x));
            in.read((char *) &y, sizeof(y));
            in.read((char *) &z, sizeof(z));
            vertices[j].x = x, vertices[j].y = y, vertices[j].z = z;
        }
        triangles[i].setVertices(vertices);
        in.seekg(2, ios_base::cur);
    }
    cout << "readed " << cnt << '\n';
    in.close();
//    float max_x, min_x, max_y, min_y, max_z, min_z;
//    max_x = max_y = max_z = -1e9;
//    min_x = min_y = min_z = 1e9;
//    for (auto &triangle: triangles) {
//        for (auto &p: triangle.getVertices()) {
//            max_x = std::max(max_x, p.x), min_x = std::min(min_x, p.x);
//            max_y = std::max(max_y, p.y), min_y = std::min(min_y, p.y);
//            max_z = std::max(max_z, p.z), min_z = std::min(min_z, p.z);
//        }
//    }
//    cout << max_x << " " << max_y << " " << max_z << " " << min_x << " " << min_y << " " << min_z << '\n';
    if (!normal) {
        cout << "calculate normals\n";
        float max_x, min_x, max_y, min_y, max_z, min_z;
        max_x = max_y = max_z = -1e9;
        min_x = min_y = min_z = 1e9;
        for (auto &triangle: triangles) {
            for (auto &p: triangle.getVertices()) {
                max_x = std::max(max_x, p.x), min_x = std::min(min_x, p.x);
                max_y = std::max(max_y, p.y), min_y = std::min(min_y, p.y);
                max_z = std::max(max_z, p.z), min_z = std::min(min_z, p.z);
            }
        }
        cout << max_x << " " << max_y << " " << max_z << " " << min_x << " " << min_y << " " << min_z << '\n';
        glm::vec3 center((max_x - min_x) / 2, (max_y - min_y) / 2, (max_z - min_z) / 2);
        fstream out(filename, ios_base::out | ios_base::in | ios_base::binary);
        out.seekp(0);
        out.seekp(84, ios_base::beg);
        for (auto &triangle: triangles) {
            vertices = triangle.getVertices();
            glm::vec3 a = vertices[1] - vertices[0], b = vertices[2] - vertices[0];
            glm::vec3 v_n = glm::cross(a, b);
            v_n = glm::normalize(v_n);
            triangle.setN(v_n);
            float n_x = v_n.x, n_y = v_n.y, n_z = v_n.z;
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

void TaskHandler::AddCamera(const camera &cam) {
    scene.AddCamera(cam);
}

void TaskHandler::RotateCurCamera(const float &dx, const float &dy) {
    scene.RotateCurCamera(dx, dy);
}


void TaskHandler::MoveCamera(const Camera_Movement &move, float &delta_time) {
    scene.MoveCamera(move, delta_time);
}

void TaskHandler::ScaleCamera(float &k) {
    scene.ScaleCamera(k);
}

void TaskHandler::StartSimulation() {
    scene.StartSimulation();
}

void TaskHandler::UpdateWind(int speed, int angle) {
    scene.UpdateWind({cos(M_PI / 180. * (180 - angle)) * speed / 20., sin(M_PI / 180. * (180 - angle)) * speed / 20.});
}

void TaskHandler::UpdateSimSpeed(int x) {
    scene.UpdateSimSpeed(0.05f * x);
}

void TaskHandler::SmokeTimerElapsed() {
    scene.SmokeTimerElapsed();
}

