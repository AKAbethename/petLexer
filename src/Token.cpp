#include "Token.h"
#include <iostream>
#include <vector>

Token::Token(std::string title, TableNote definition) : title(title),
                            definition(definition) {}

void print_token(const Token& t){
    if(t.definition.value != "id" && t.definition.value != "number"){
        std::cout << "<" << t.title << ">" << ' ';
        std::cout << t.definition.line_number << ' ' << t.definition.symbol_number << '\n';
    }
    else if(t.definition.value == "number"){
        std::cout << "<" << t.definition.value << ", " << t.title << ">" << ' ';
        std::cout << t.definition.line_number << ' ' << t.definition.symbol_number << '\n';
    }
    else if(t.definition.value == "id"){
        std::cout << "<" << t.definition.value << ", " << t.title << ">" << ' ';
        std::cout << t.definition.line_number << ' ' << t.definition.symbol_number << '\n';
    }
}


void print_tokens(const std::vector<Token>& v){
    std::cout << "Tokens' stream\n";
    for(auto x: v){
        print_token(x);
    }
    std::cout << "\n";
}
