#ifndef FILE_STRUCT_HPP
#define FILE_STRUCT_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include "column_struct.hpp"

namespace ne_pp::pp {
enum CorpusType {
    CSV,
    JSON,
    Text
};

struct CSVDataFile {
    std::string filePath;
    std::vector<CSVDataColumn> columns;
    std::unordered_map<std::string, size_t>headerIndex;
};
}
#endif