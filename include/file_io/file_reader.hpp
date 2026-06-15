#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../core/exceptions.hpp"

enum CorpusType {
    CSV
};

class FileReader {
    private:
     std::string filePath;
     std::vector<std::string> corpusBody;
     CorpusType corpusType;

    public:
        FileReader(std::string filePath, CorpusType corpusType);
        std::vector<std::string> getCorpusBodyVector();
};

#endif