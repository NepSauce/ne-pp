#include <iostream>

#include "../include/ne_pp/pp/utils/token_utils/string_pp.hpp"
#include <ne_pp/pp/utils/csv_utils/csv_parser.hpp>

int main() {
    std::string testStr = "  six seven  ";
    std::cout << ne_pp::pp::StringPP(testStr).trimLeft().toString() << std::endl;    
    std::cout << ne_pp::pp::StringPP(testStr).trimRight().toString() << std::endl;
    std::cout << ne_pp::pp::StringPP(testStr).trim().toString() << std::endl;
    
    ne_pp::pp::CSVParser parser("../corpus/csv/comma_delimiter.csv", true, ',', 2);
    std::unique_ptr<ne_pp::pp::CSVDataFile> myFrame = parser.dataFrame();

    for (size_t j = 0; j < myFrame->columns.size(); ++j) {
        const auto& col = myFrame->columns[j];
        std::cout << col.header << " (Nulls: " << col.nullPosition.size() << ")\n";
    }
    size_t totalRows = myFrame->columns[0].data.size();

    for (size_t i = 0; i < totalRows; ++i) {
        for (size_t j = 0; j < myFrame->columns.size(); ++j) {
            std::cout << myFrame->columns[j].data[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}