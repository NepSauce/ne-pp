#include "../../../../../include/ne_pp/pp/utils/csv_utils/csv_parser.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"
#include "../../../../../include/ne_pp/pp/utils/token_utils/infer_type.hpp"

namespace ne_pp::pp {
CSVParser::CSVParser(
    const std::string& filePath, 
    bool header, 
    char delimiter, 
    size_t explicitRowLength, 
    size_t explicitColumnLength
)
    : filePath(filePath), 
    header(header), 
    delimiter(delimiter), 
    explicitRowLength(explicitRowLength),
    explicitColumnLength(explicitColumnLength) {}

std::vector<CSVDataColumn> CSVParser::parseColumn() {
    FileReader fileReader(this->filePath);
    const std::vector<std::string>& corpusBody = fileReader.getCorpusBodyVector();
    size_t rowLength = getRowLength(corpusBody);
    size_t columnLength = getColumnLength(corpusBody);
    std::vector<CSVDataColumn> parsedColumns(rowLength);
    size_t startRow = 0;

    if (this->header) {
        std::vector<std::string> headerVector = StringPP(corpusBody[0]).split(this->delimiter);

        for (size_t i = 0; i < rowLength; i++) {
            parsedColumns[i].header = headerVector[i];
        }
        startRow = 1;
    }
    size_t expectedRows = columnLength - startRow;

    for (size_t j = 0; j < rowLength; ++j) {
        parsedColumns[j].data.reserve(expectedRows);
    }

    try {
        for (size_t i = startRow; i < columnLength; ++i) {
            std::vector<std::string> line = StringPP(corpusBody[i]).split(this->delimiter);
            size_t currentDataRowIndex = i - startRow;

            for (size_t j = 0; j < rowLength; ++j) {
                if (j < static_cast<size_t>(line.size())) {
                    if (StringPP(line[j]).trim().toString().empty()) {
                        parsedColumns[j].nullPosition.push_back(currentDataRowIndex);
                    }
                    parsedColumns[j].data.push_back(std::move(line[j]));
                } 
                else {
                    parsedColumns[j].nullPosition.push_back(currentDataRowIndex);
                    parsedColumns[j].data.push_back("");
                }
            }
        }
    } catch (const std::out_of_range& e) {
        throw LengthMismatchException("Length mismatch error");
    } 

    return parsedColumns;
}

std::unique_ptr<CSVDataFile> CSVParser::dataFrame() {
    auto foundFile = std::make_unique<CSVDataFile>();
    foundFile->filePath = this->filePath;
    foundFile->columns = this->parseColumn();

    return foundFile;
}

size_t CSVParser::getRowLength(const std::vector<std::string>& corpusBody) const {
    if (this->explicitRowLength != 0) {
        return explicitRowLength;
    }

    else if (header) {
        return StringPP(corpusBody[0]).split(this->delimiter).size();
    }

    throw InvalidCSVStructureException("Parser Error: Missing row length");
}

size_t CSVParser::getColumnLength(const std::vector<std::string>& corpusBody) const {
    size_t columnLength = corpusBody.size();

    if (this->explicitColumnLength != 0) {
        return explicitColumnLength;
    }

    return columnLength;
}
}