#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum CorpusType {
    CSV
};

class FileReader {
    private:
     std::string filePath;
     CorpusType corpusType;

    public:
        FileReader(std::string filePath);
        std::vector<std::string> getCorpusBody();
};

#endif