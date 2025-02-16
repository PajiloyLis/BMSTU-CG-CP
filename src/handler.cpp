#include "handler.h"

TaskHandler::TaskHandler() : scene() {}

void TaskHandler::SetScene(const Scene &scene_to_set) {
    scene = scene_to_set;
}

void TaskHandler::DrawScene() {
    scene.DrawFigures();
}

void TaskHandler::ClearScene() const {
    scene.ClearScene();
}

void TaskHandler::LoadModel(const string &filepath) {
    scene.AddFigure(figure({{(1, 0, 0}, {{50, 43.55, 37.96},
                                         {50, 43.55, 37.96}, {50, 43.55, 37.96}}}}));
    scene.AddFigure(figure(read_stl(filepath)));
}

vector<triangle> TaskHandler::read_stl(const string &filename) {
    ifstream in(filename, ios_base::in | ios_base::binary);
    uint32_t n;
    in.seekg(80, ios_base::beg);
    in.read((char *) &n, sizeof(n));
    cout << n << '\n';

    vector<triangle> triangles(n);
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
        triangles[i].setN({x, y, z});

        for (int j = 0; j < 3; ++j) {
            in.read((char *) &x, sizeof(x));
            in.read((char *) &y, sizeof(y));
            in.read((char *) &z, sizeof(z));
            vertices[j].setX(x), vertices[j].setY(y), vertices[j].setZ(z);
        }
        triangles[i].setVertices(vertices);
        in.seekg(2, ios_base::cur);
    }
    cout << "readed " << cnt << '\n';
    in.close();
    float max_x, min_x, max_y, min_y, max_z, min_z;
    max_x = max_y = max_z = -1e9;
    min_x = min_y = min_z = 1e9;
    for (auto &triangle: triangles) {
        for (auto &p: triangle.getVertices()) {
            max_x = std::max(max_x, p.getX()), min_x = std::min(min_x, p.getX());
            max_y = std::max(max_y, p.getY()), min_y = std::min(min_y, p.getY());
            max_z = std::max(max_z, p.getZ()), min_z = std::min(min_z, p.getZ());
        }
    }
    cout << max_x << " " << max_y << " " << max_z << " " << min_x << " " << min_y << " " << min_z << '\n';
    if (!normal) {
        cout << "calculate normals\n";
//        float max_x, min_x, max_y, min_y, max_z, min_z;
//        max_x = max_y = max_z = -1e9;
//        min_x = min_y = min_z = 1e9;
//        for (auto &triangle: triangles) {
//            for (auto &p: triangle.getVertices()) {
//                max_x = std::max(max_x, p.getX()), min_x = std::min(min_x, p.getX());
//                max_y = std::max(max_y, p.getY()), min_y = std::min(min_y, p.getY());
//                max_z = std::max(max_z, p.getZ()), min_z = std::min(min_z, p.getZ());
//            }
//        }
//        cout << max_x << " " << max_y << " " << max_z << " " << min_x << " " << min_y << " " << min_z << '\n';
        my_vec3f center((max_x - min_x) / 2, (max_y - min_y) / 2, (max_z - min_z) / 2);
        fstream out(filename, ios_base::out | ios_base::in | ios_base::binary);
        out.seekp(0);
        out.seekp(84, ios_base::beg);
        for (auto &triangle: triangles) {
            vertices = triangle.getVertices();
//            my_vec3f center_1 = vertices[0] - center,
//                    center_2 = vertices[1] - center,
//                    center_3 = vertices[2] - center;
            my_vec3f a = vertices[1] - vertices[0], b = vertices[2] - vertices[0];
            my_vec3f v_n = a.cross(b);
            v_n.normalize();
            triangle.setN(v_n);
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

void TaskHandler::AddCamera(const camera &cam) {
    scene.AddCamera(cam);
}

void TaskHandler::RotateCurCameraLeft() {
    scene.RotateCurCameraLeft();
}

void TaskHandler::RotateCurCameraRight() {
    scene.RotateCurCameraRight();
}

void TaskHandler::RotateCurCameraUp() {
    scene.RotateCurCameraUp();
}

void TaskHandler::RotateCurCameraDown() {
    scene.RotateCurCameraDown();
}

void TaskHandler::MoveCamera(const move_t &move) {
    scene.MoveCamera(move);
}

void TaskHandler::ScaleCamera(float &k) {
    scene.ScaleCamera(k);
}

