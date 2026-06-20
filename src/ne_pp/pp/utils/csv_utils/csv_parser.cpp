#include "../../../../../include/ne_pp/pp/utils/csv_utils/csv_parser.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"

namespace ne_pp::pp {
CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<CSVDataColumn> CSVParser::parseColumn() {
    FileReader fileReader(this->filePath);
    const std::vector<std::string>& corpusBody = fileReader.getCorpusBodyVector();

    // to-do: correct error type
    if (corpusBody.empty()) {
        throw EmptyStringException("Empty corpus error");
    }

    int rowLength = StringPP(corpusBody[0]).split(this->delimiter).size();
    int columnLength = corpusBody.size();
    
    std::vector<CSVDataColumn> parsedColumns(rowLength);

    int startRow = 0;

    if (this->header) {
        std::vector<std::string> headerVector = StringPP(corpusBody[0]).split(this->delimiter);

        for (int i = 0; i < rowLength; i++) {
            parsedColumns[i].header = headerVector[i];
        }
    }

    try {
        for (int i = 0; i < columnLength; i++) {
            if (this->header == true && i == 0) {
                continue;
            } 

            std::vector<std::string> line = splitStringVector(corpusBody[i]);

            for (int j = 0; j < rowLength; j++) {
                parsedColumns[j].data.push_back(line[j]);
            }
        }
    } catch (const std::out_of_range& e) {
        throw LengthMismatchException("Length mismatch error");
    } 

    return parsedColumns;
}

DataType CSVParser::findDataType(std::string token) {
    if (token.empty()) return DataType::Null;
}
}