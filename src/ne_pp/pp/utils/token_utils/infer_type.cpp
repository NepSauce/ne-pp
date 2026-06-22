#include "../../../../../include/ne_pp/pp/utils/token_utils/infer_type.hpp"

namespace ne_pp::pp {
    DataType InferType::infer(std::string_view token) {
        if (StringPP(std::string(token)).trim().toString().empty()) {
            return DataType::Null;
        }
    }
}