#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../core/exceptions.hpp"
namespace ne_pp::pp {
class FileReader {
    private:
        std::string filePath;
        std::vector<std::string> corpusBody;

    public:
        FileReader(std::string filePath);
        std::vector<std::string> getCorpusBodyVector();
};
}
#endif