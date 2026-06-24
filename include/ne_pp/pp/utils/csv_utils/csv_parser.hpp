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
        size_t explicitRowLength;
        size_t explicitColumnLength;

        std::vector<CSVDataColumn> parseColumn();
        size_t getRowLength(const std::vector<std::string>& corpusBody);
        size_t getColumnLength(const std::vector<std::string>& corpusBody);

    public:
        CSVParser(const std::string& filePath, 
            bool header, 
            char delimiter, 
            size_t explicitRowLength,
            size_t explicitColumnLength = 0
        );
        std::unique_ptr<CSVDataFile> dataFrame();
};
}
#endif