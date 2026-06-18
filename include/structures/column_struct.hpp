#ifndef COLUMN_STRUCT_HPP
#define COLUMN_STRUCT_HPP

#include <string>
#include <vector>

enum class DataType {
    Numeric,
    Text,
    Null
};

struct DataColumn {
    std::string header;
    DataType type;
    std::vector<std::string> data;
    std::vector<int> nullPosition;
};

#endif // COLUMN_STRUCT