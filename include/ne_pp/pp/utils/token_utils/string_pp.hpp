#ifndef STRING_PP_HPP
#define STRING_PP_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>
#include <typeinfo>

namespace ne_pp::pp {
class StringPP {
    private:
    std::string value;

    public:
    explicit StringPP(std::string str);

    StringPP& trimRight();
    StringPP& trimLeft();
    StringPP& trim();
    StringPP& toLower();
    StringPP& toUpper();
    StringPP& capitalize();
    std::vector<std::string> split(char delimiter) const;
    int find(char c);

    std::string toString() const;
};    
}

#endif