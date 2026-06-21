#ifndef COLUMN_STRUCT_HPP
#define COLUMN_STRUCT_HPP

#include <string>
#include <vector>

namespace ne_pp::pp {
enum class CellType {
    Numeric,
    Text,
    Null
};

struct CSVDataColumn {
    std::string header;
    CellType type;
    std::vector<std::string> data;
    std::vector<int> nullPosition;
};
}

#endif // COLUMN_STRUCT