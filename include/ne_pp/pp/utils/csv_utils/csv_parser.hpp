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
        int explicitRowLength;
        int explicitColumnLength;

        std::vector<CSVDataColumn> parseColumn();
        int getRowLength();
        int getColumnLength();

    public:
        CSVParser(const std::string& filePath, 
            bool header, 
            char delimiter, 
            int explicitRowLength = 0,
            int explicitColumnLength = 0);
        std::unique_ptr<CSVDataFile> dataFrame();
};
}

#endif