#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <string>
#include <sstream>

#include "../structures/file_struct.hpp"
#include "../file_io/file_reader.hpp"

class CSVParser {
    private:
        std::string filePath;
        bool header;
        char delimiter;

        std::vector<DataColumn> parseColumn();
        std::vector<std::string> splitStringVector(std::string line);

    public:
        CSVParser(const std::string& filePath, bool header, char delimiter);
        std::unique_ptr<DataFile> dataFrame();
};

#endif