#include "file_io/file_reader.hpp"

FileReader::FileReader(std::string filePath, CorpusType corpusType)
    : filePath(filePath), corpusType(corpusType) {}

std::vector<std::string> FileReader::getCorpusBodyVector() {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        throw FileNotFoundException("File path error: " + this->filePath);
    }

    while (std::getline(file, line)) {
        this->corpusBody.push_back(line);
    }

    file.close();
    return this->corpusBody;
}