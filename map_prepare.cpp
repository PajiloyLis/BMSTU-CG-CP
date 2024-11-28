#include "map_prepare.h"

vector<int> compute_convex_hull(vector<point> &points);

vector<point> read_map(const string &map_filename, const string &map_info_file) {
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
    vector<point> map(cnt_rows * cnt_cols);
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

vector<vector<point>> read_stl(const string &filename) {
    ifstream in(filename, ios::in | ios::binary);
    uint32_t n;
    in.seekg(80, ios_base::beg);
    in.read((char *) &n, sizeof(n));
    cout << n << '\n';
    vector<vector<point>> triangles(n, vector<point>(3));
    float x, y, z;
    for (int i = 0; i < n; ++i) {
        in.seekg(4 * 3, ios_base::cur);
        for (int j = 0; j < 3; ++j) {
            in.read((char *) &x, sizeof(x));
            in.read((char *) &y, sizeof(y));
            in.read((char *) &z, sizeof(z));
            triangles[i][j].setX(x), triangles[i][j].setY(y), triangles[i][j].setZ(z);
        }
        in.seekg(2, ios_base::cur);
    }
    return triangles;
}

set<set<int>> stupid_delaunay_triangulate(vector<point> &points) {
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