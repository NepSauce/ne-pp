#ifndef FILE_STRUCT_HPP
#define FILE_STRUCT_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include "column_struct.hpp"

enum CorpusType {
    CSV,
    JSON,
    Text
};

struct CSVDataFile {
    std::string filePath;
    std::vector<DataColumn> columns;
    std::unordered_map<std::string, int> headerIndex;
};

#endif