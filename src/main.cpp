#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include "lexer.h"
#include "Token.h"
#include <regex>


bool isNumber1(const std::string& cur_word){
    std::regex pattern(R"([1-9]+[0-9]*)");
    if(std::regex_match(cur_word, pattern)){
        return true;
    }
    return false;
}

bool isID1(const std::string& cur_word){
    std::regex pattern(R"([A-Za-z_]\w*)");
    if(std::regex_match(cur_word, pattern)){
        return true;
    }
    return false;
}

int main(){
    scan_code("tests/input.c");

/*     Token t{"if", {3, 4}};

    print_token(t);

    std::string str = "1";
    if(isNumber1(str)) std::cout << "aba\n\n";
    if(isID1(str)) std::cout << "abaebiomat\n\n"; */

//    if(isID("_k3")) std::cout << "yeeeeee\n\n";

}
