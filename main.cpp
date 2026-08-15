#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include "lexer.h"


int main(){
    scan_code("input.c");

    if(isID("_k3")) std::cout << "yeeeeee\n\n";

}
