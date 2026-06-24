#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <string>
#include <sstream>
#include <typeinfo>

#include "../../structures/file_struct.hpp"
#include "../../file_io/file_reader.hpp"

namespace ne_pp::pp {
class CSVParser {
    private:
        std::string filePath;
        bool header;
        char delimiter;

        std::vector<CSVDataColumn> parseColumn();

    public:
        CSVParser(const std::string& filePath, bool header, char delimiter);
        std::unique_ptr<CSVDataFile> dataFrame();
};
}

#endif