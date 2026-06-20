#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"

namespace ne_pp::pp {
StringPP::StringPP(std::string str)
    : value(std::move(str)) {}
    
std::string StringPP::trimLeft() const {
    auto it = std::find_if(this->value.begin(), this->value.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    
    return std::string(it, this->value.end());
}

std::string StringPP::trimRight() const {
    auto it = std::find_if(this->value.rbegin(), this->value.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    });

    return std::string(this->value.begin(), it.base());
}

std::string StringPP::trim() const {
    std::string leftTrimmed = this->trimLeft();

    return StringPP(leftTrimmed).trimRight();
}
}