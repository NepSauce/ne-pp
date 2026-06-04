#include <iostream>
#include <vector>

#include "structures/column_struct.hpp"

using namespace std;

struct DataColumn {
    string header;
    ColumnType type;
    vector<string> data;
    vector<int> nullPosition;
};