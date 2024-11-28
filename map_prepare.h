#ifndef CP_CG_READ_BINARY_H
#define CP_CG_READ_BINARY_H

#include <iostream>
#include <fstream>
#include <array>
#include<vector>

using namespace std;

#define ROWS_CNT_STRING 8
#define COLS_CNT_STRING 9
#define VALUE_POS 25

vector<vector<float>> read_map(const string &map_filename, const string &map_info_file);


#endif //CP_CG_READ_BINARY_H
