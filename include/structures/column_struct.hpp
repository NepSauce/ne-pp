#ifndef COLUMN_STRUCT_HPP
#define COLUMN_STRUCT_HPP

#include <string>
#include <vector>

enum class ColumnType {
    Numeric,
    Text
};

struct DataColumn {
    std::string header;
    ColumnType type;
    std::vector<std::string> data;
    std::vector<int> nullPosition;
};

#endif // COLUMN_STRUCT