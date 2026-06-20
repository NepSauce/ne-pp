#include <iostream>

#include "../include/ne_pp/pp/utils/token_utils/string_pp.hpp"

int main() {
    std::string testStr = "  six seven  ";
    std::cout << ne_pp::pp::StringPP(testStr).trimLeft().toString() << std::endl;    
    std::cout << ne_pp::pp::StringPP(testStr).trimRight().toString() << std::endl;
    std::cout << ne_pp::pp::StringPP(testStr).trim().toString() << std::endl;
    
    return 0;
}
