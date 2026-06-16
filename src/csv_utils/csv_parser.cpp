#include "../../include/csv_utils/csv_parser.hpp"

CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<DataColumn> CSVParser::parseColumn() {
    std::vector<std::string> corpusBody;
    std::vector<std::string> headerVector;
    int rowLength;
    int columnLength;
    FileReader fileReader(this->filePath, CSV);
    corpusBody = fileReader.getCorpusBodyVector();

    if (this->header == true) {
        headerVector = splitStringVector(corpusBody[0]);
    }

    rowLength = splitStringVector(corpusBody[0]).size();
    columnLength = corpusBody.size();
    std::vector<DataColumn> parsedColumns(rowLength);

    for (int i = 0; i < columnLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            if (this->header == true) {
                parsedColumns[j].header = this->header;
            }
        }
    }
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