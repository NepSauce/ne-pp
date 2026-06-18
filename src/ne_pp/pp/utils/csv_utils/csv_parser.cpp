#include "../../../../../include/ne_pp/pp/utils/csv_utils/csv_parser.hpp"

namespace ne_pp::pp {
CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<DataColumn> CSVParser::parseColumn() {
    std::vector<std::string> corpusBody;
    std::vector<std::string> headerVector;
    int rowLength;
    int columnLength;
    FileReader fileReader(this->filePath, CSV);

    corpusBody = fileReader.getCorpusBodyVector();

    rowLength = splitStringVector(corpusBody[0]).size();
    columnLength = corpusBody.size();
    std::vector<DataColumn> parsedColumns(rowLength);

    if (this->header == true) {
        headerVector = splitStringVector(corpusBody[0]);

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

std::vector<std::string> CSVParser::splitStringVector(std::string line) {
    std::vector<std::string> stringVector;
    std::string word;
    std::stringstream ss(line);

    while (std::getline(ss, word, this->delimiter)) {
        stringVector.push_back(word);
    }

    return stringVector;
}

DataType CSVParser::findDataType(std::string token) {
    if (token.empty()) return DataType::Null;
    return;
}
}