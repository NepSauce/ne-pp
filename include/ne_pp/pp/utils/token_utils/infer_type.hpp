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
        bool isInteger(std::string& token) const;
        bool isFloat(std::string& token) const;
        bool isCharacter(std::string& token) const;
        bool isBoolean(std::string& token) const;

    public:
        static DataType infer(std::string_view token);
};
}

#endif