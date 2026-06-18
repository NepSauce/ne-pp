#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

namespace ne_pp::pp {
class StringPP {
    private:

    public:
    StringPP(const std::string &ref);
    std::string trimRight();
    std::string trimLeft();
    std::string trimAll();
};    
}