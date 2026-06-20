#include "../../../../../include/ne_pp/pp/utils/token_utils/string_pp.hpp"

namespace ne_pp::pp {
StringPP::StringPP(std::string str)
    : value(std::move(str)) {}
    
StringPP& StringPP::trimLeft() {
    auto it = std::find_if(this->value.begin(), this->value.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    });
    
    this->value.erase(this->value.begin(), it);

    return *this;
}

StringPP& StringPP::trimRight() {
    auto it = std::find_if(this->value.rbegin(), this->value.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    });

    this->value.erase(it.base(), this->value.end());

    return *this;
}

StringPP& StringPP::trim() {
    this->trimLeft();
    this->trimRight();

    return *this;
}

std::string StringPP::toString() const {
    return this->value;
}
}