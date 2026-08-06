#include "lexer.h"

std::vector<std::string> types{"int"};

std::vector<std::string> keyWords{"if", "else", "while", "break", "return", 
                        "switch", "case", "sizeof"};

std::vector<std::string> ops{"+", "-", "*", "/", "%", "&&", "||",
                            "=", "==", "!=", "<", "<=", ">", ">="};

std::vector<std::string> punctSigns = {"{", "}", "[", "]", "(", ")", ";", ",", "\""};                            

void f(){
    std::cout << types[0] << "\n";
}
