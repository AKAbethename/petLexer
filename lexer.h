#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>

std::vector<std::string> types{"int"};

std::vector<std::string> keyWords{"if", "else", "while", "break", "return", 
                        "switch", "case", "sizeof"};

std::vector<std::string> ops{"+", "-", "*", "/", "%", "&&", "||",
                                "=", "==", "!=", "<", "<=", ">", ">="};

std::vector<std::string> punctSigns = {"{", "}", "[", "]", "(", ")", ";", ",", "\""};

#endif