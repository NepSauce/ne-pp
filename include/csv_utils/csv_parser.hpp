#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <string>
#include "../structures/file_struct.hpp"


class CSVParser {
    private:
        std::string filePath;
        bool header;
        char delimiter;

        int* unloadCSV();
    public:
        CSVParser(std::string filePath, bool header, char delimiter);
        std::unique_ptr<DataFile> dataFrame();
};

#endif