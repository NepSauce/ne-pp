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
        bool isString();
        bool isInteger();
        bool isFloat();
        bool isCharacter();
        bool isBoolean();

    public:
        static DataType infer(std::string_view token);
};
}

#endif