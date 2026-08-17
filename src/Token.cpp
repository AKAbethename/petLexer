#include "Token.h"
#include <iostream>
#include <vector>

Token::Token(std::string title, TableNote definition) : title(title),
                            definition(definition) {}

void print_token(const Token& t){
    if(t.definition.value != "id")
        std::cout << "<" << t.title << ">" << ' ';
    else
        std::cout << "<" << t.definition.value << ", " << t.title << ">" << ' ';
}

void print_tokens(const std::vector<Token>& v){
    std::cout << "Tokens' stream\n";
    for(auto x: v){
        print_token(x);
    }
    std::cout << "\n";
}
