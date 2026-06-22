#include "../../../../../include/ne_pp/pp/utils/token_utils/infer_type.hpp"

namespace ne_pp::pp {
    DataType InferType::infer(std::string_view token) {
        std::string trimmedToken = StringPP(std::string(token)).trim().toString();
        
        if (trimmedToken.empty()) {
            return DataType::Null;
        }
    }

    bool isInteger(std::string& token) {
        size_t start = 0;
        
        if (token[0] == '-' || token[0] == '+') {
            if (token.size() == 1) return false; 
            start = 1;
        }

        return std::all_of(token.begin() + start, token.end(), ::isdigit);
    }
}