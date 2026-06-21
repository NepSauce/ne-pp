#ifndef INFER_TYPE_HPP
#define INFER_TYPE_HPP

#include <string_view>
#include <cctype>

namespace ne_pp::pp {
enum DataType {
    String,
    Integer,
    Float,
    Double,
    Character,
    Boolean,
    Null,
    Undefined
};

class InferType {
    public:
        static DataType infer(std::string_view token);
};
}
#endif