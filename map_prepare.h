#ifndef CP_CG_MAP_PREPARE_H
#define CP_CG_MAP_PREPARE_H

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cmath>
#include "point.h"
#include <set>
#include "triangle.h"
#include <algorithm>

using namespace std;

#define ROWS_CNT_STRING 8
#define COLS_CNT_STRING 9
#define VALUE_POS 25
#define METERS_PER_POINT 30

vector<point> read_map(const string &map_filename, const string &map_info_file);

vector<triangle> read_stl(const string &filename);

set<set<int>> stupid_delaunay_triangulate(vector<point> &points);

#endif //CP_CG_MAP_PREPARE_H
