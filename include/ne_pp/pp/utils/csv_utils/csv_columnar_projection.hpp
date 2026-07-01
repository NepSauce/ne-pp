#ifndef CSV_COLUMNAR_PROJECTION_HPP
#define CSV_COLUMNAR_PROJECTION_HPP

#include "csv_parser.hpp"

namespace ne_pp::pp {
class CSVColumnarProjection {
    private:
        std::unique_ptr<CSVDataFile> dataFile;
        std::vector<size_t> columnIndices;

    public:
        CSVColumnarProjection(std::unique_ptr<CSVDataFile> dataFile, const std::vector<size_t>& columnIndices);
        std::unique_ptr<CSVDataFile> project();
};
}
#endif