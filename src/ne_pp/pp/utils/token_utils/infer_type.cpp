#include "../../../../../include/ne_pp/pp/utils/token_utils/infer_type.hpp"

namespace ne_pp::pp {
DataType InferType::infer(std::string_view token) {
    std::string trimmedToken = StringPP(std::string(token)).trim().toString();
    
    if (trimmedToken.empty()) {
        return DataType::Null;
    }

    if (isInteger(trimmedToken)) {
        return DataType::Integer;
    }

    if (isFloat(trimmedToken)) {
        return DataType::Float;
    }

    return DataType::String;
}

bool InferType::isInteger(std::string& token) {
    size_t start = 0;

    if (token[0] == '-' || token[0] == '+') {
        if (token.size() == 1){
            return false; 
        }
        start = 1;
    }

    return std::all_of(token.begin() + start, token.end(), [](unsigned char ch) {
        return std::isdigit(ch);
    });
}

bool InferType::isFloat(std::string& token) {
    bool decimalPointFound = false;
    size_t start = 0;

    if (token[0] == '-' || token[0] == '+') {
        if (token.size() == 1){
            return false;
        }   
        start = 1;
    }

    for (size_t i = start; i < token.size(); ++i) {
        if (token[i] == '.') {
            if (decimalPointFound){
                return false; 
            }
            decimalPointFound = true;
        } else if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
            return false;
        }
    }

    return true;
}
}