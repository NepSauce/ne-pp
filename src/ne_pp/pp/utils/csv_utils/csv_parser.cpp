#include "../../../../../include/ne_pp/pp/utils/csv_utils/csv_parser.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/infer_type.hpp"

namespace ne_pp::pp {
CSVParser::CSVParser(const std::string& filePath, bool header, char delimiter)
    : filePath(filePath), header(header), delimiter(delimiter) {}

std::vector<CSVDataColumn> CSVParser::parseColumn() {
    FileReader fileReader(this->filePath);
    const std::vector<std::string>& corpusBody = fileReader.getCorpusBodyVector();

    int rowLength = StringPP(corpusBody[0]).split(this->delimiter).size();
    int columnLength = corpusBody.size();

    std::vector<CSVDataColumn> parsedColumns(rowLength);

    int startRow = 0;

    if (this->header) {
        std::vector<std::string> headerVector = StringPP(corpusBody[0]).split(this->delimiter);

        for (int i = 0; i < rowLength; i++) {
            parsedColumns[i].header = headerVector[i];
        }
        
        startRow = 1;
    }

    int expectedRows = columnLength - startRow;

    for (int j = 0; j < rowLength; ++j) {
        parsedColumns[j].data.reserve(expectedRows);
    }

    try {
        for (int i = startRow; i < columnLength; ++i) {
            std::vector<std::string> line = StringPP(corpusBody[i]).split(this->delimiter);

            if (line.size() != static_cast<size_t>(rowLength)) {
                throw LengthMismatchException("Malformed data row at line " + std::to_string(i));
            }

            for (int j = 0; j < rowLength; ++j) {
                parsedColumns[j].data.push_back(std::move(line[j]));
            }
        }
    } catch (const std::out_of_range& e) {
        throw LengthMismatchException("Length mismatch error");
    } 

    return parsedColumns;
}
}