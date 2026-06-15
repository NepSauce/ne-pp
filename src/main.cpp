#include <iostream>

#include "file_io/file_reader.hpp"

int main() {
    std::vector<std::string> corpusBody;
    std::string filePath = "../corpus/csv/comma_delimiter.csv";
    FileReader fileReader(filePath, CSV);
    corpusBody = fileReader.getCorpusBodyVector();

    for (const std::string& line : corpusBody) {
        std::cout << line << std::endl;
    }

    return 0;
}
