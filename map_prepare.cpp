#include "read_binary.h"

vector<vector<float>> read_map(const string &map_filename, const string &map_info_file)
{
    ifstream info_in(map_info_file);
    if(!info_in.is_open())
    {
        throw exception();
    }
    string rows_cnt_string, cols_cnt_string;
    for(int i = 0; i < ROWS_CNT_STRING; ++i)
        getline(info_in, rows_cnt_string);
    getline(info_in, cols_cnt_string);
    string cnt_rows_str = rows_cnt_string.substr(VALUE_POS), cnt_cols_str = cols_cnt_string.substr(VALUE_POS);
    int cnt_rows = stoi(cnt_rows_str), cnt_cols = stoi(cnt_cols_str);
    cout<<cnt_rows<<" "<<cnt_cols<<'\n';
    vector<vector<float>> map(cnt_rows, vector<float> (cnt_cols));
    ifstream map_in(map_filename, ios::in|ios::binary);
    if(!map_in.is_open())
        throw exception();
    for(int i = 0; i < cnt_rows; ++i)
        for(int j = 0; j < cnt_cols; ++j)
            map_in.read((char*)&map[i][j], sizeof(float));
    return map;
}