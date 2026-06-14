#include "file_io/file_reader.hpp"

class FileReader {
    private:
        std::string filePath;
        std::vector<std::string> corpusBody;
        CorpusType corpusType;

    public:
        FileReader(std::string filePath, CorpusType corpusType) 
            : filePath(filePath), corpusType(corpusType) {
        }

        std::vector<std::string> getCorpusBodyVector() {
            std::ifstream file(filePath);

            if (!file.is_open()) {
                
            }
        }
};