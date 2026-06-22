#ifndef INFER_TYPE_HPP
#define INFER_TYPE_HPP

#include "string_pp.hpp"

#include <string_view>
#include <cctype>

namespace ne_pp::pp {
enum DataType {
    String,
    Integer,
    Float,
    Character,
    Boolean,
    Null,
    Undefined
};

class InferType {
    private:
        static bool isInteger(std::string& token);
        static bool isFloat(std::string& token);

    public:
        static DataType infer(std::string_view token);
};
}

#endif