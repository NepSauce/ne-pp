#include "../../../../../include/ne_pp/pp/utils/csv_utils/csv_parser.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"

namespace ne_pp::pp {
CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<CSVDataColumn> CSVParser::parseColumn() {
    std::vector<std::string> corpusBody;
    std::vector<std::string> headerVector;
    int rowLength;
    int columnLength;
    FileReader fileReader(this->filePath);

    corpusBody = fileReader.getCorpusBodyVector();

    rowLength = StringPP(corpusBody[0]).split(this->delimiter).size();
    columnLength = corpusBody.size();
    std::vector<CSVDataColumn> parsedColumns(rowLength);

    if (this->header == true) {
        headerVector = StringPP(corpusBody[0]).split(this->delimiter);

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