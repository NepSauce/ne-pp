#ifndef STRING_PP_HPP
#define STRING_PP_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

namespace ne_pp::pp {
class StringPP {
    private:
    std::string value;

    public:
    explicit StringPP(std::string str);

    StringPP& trimRight();
    StringPP& trimLeft();
    StringPP& trim();

    std::string toString() const;
};    
}

#endif