#include "../../include/csv_utils/csv_parser.hpp"

CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<DataColumn> CSVParser::parseColumn() {
    std::vector<std::string> corpusBody;
    std::vector<std::string> headerVector;
    FileReader fileReader(this->filePath, CSV);
    corpusBody = fileReader.getCorpusBodyVector();

    if (this->header == true) {
        headerVector = splitStringVector(corpusBody[0]);
    }

    for (const std::string& line : corpusBody) {
        std::cout << line << std::endl;
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