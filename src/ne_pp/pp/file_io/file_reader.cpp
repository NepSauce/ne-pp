#include "../../../../include/ne_pp/pp/file_io/file_reader.hpp"

namespace ne_pp::pp {
FileReader::FileReader(std::string filePath)
    : filePath(filePath) {}

const std::vector<std::string>& FileReader::getCorpusBodyVector() {
    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open()) {
        throw FileNotFoundException("File path error: " + this->filePath);
    }

    if (file.peek() == std::ifstream::traits_type::eof()){
        throw EOFException("File empty or invalid error");
    }

    while (std::getline(file, line)) {
        this->corpusBody.push_back(line);
    }

    file.close();
    return this->corpusBody;
}
}