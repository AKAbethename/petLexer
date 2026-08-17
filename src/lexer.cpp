#include "lexer.h"
#include "Token.h"
#include <algorithm>
#include <stack>
#include <regex>

std::vector<std::string> types{"int"};

std::vector<std::string> keyWords{"if", "else", "while", "break", "return", 
                        "switch", "case", "default", "sizeof"};

std::vector<std::string> ops{"+", "-", "*", "/", "%", "&&", "||",
                            "=", "==", "!=", "<", "<=", ">", ">="};

std::vector<std::string> punctSigns = {"{", "}", "[", "]", "(", ")", ";", ",", "\"", "'"};                            

static int line_num = 0;

static int symb_num = 0;

static int close_single_quotes = 0;

static int close_double_quotes = 0;

static int level_scope = 1;

static bool close_comment = true;

static bool close_figure_bracket = true;

static bool close_square_bracket = true;

static bool close_circle_bracket = true;

static std::stack<std::string> brackets;


void f(){
    std::cout << types[0] << "\n";
}

void split_line(std::string& line){
    std::string new_line;
    std::string symbs = "(){}[];,";
    int sz = line.length();
    for(int i = 0; i < sz; ++i){
        if(std::find(symbs.begin(), symbs.end(), line[i]) != symbs.end()){
            new_line.push_back(' ');
            new_line.push_back(line[i]);
            new_line.push_back(' ');
        }
        else
            new_line.push_back(line[i]);
    }
    line = new_line;
}

void scan_code(const std::string& file_name){
    std::vector<Token> token_stream;
    std::ifstream file(file_name);
    std::string line;
    while(std::getline(file, line)){
//        std::cout << line << "\n";
        split_line(line);
        handle_line(line, token_stream);
    }

    print_tokens(token_stream);

}


bool find_type(const std::string& word){
    if(std::find(types.begin(), types.end(), word) != types.end()){
        return true;
    }
    return false;
}

bool find_keyWord(const std::string& word){
    if(std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end()){
        return true;
    }
    return false;
}

bool find_op(const std::string& word){
    if(std::find(ops.begin(), ops.end(), word) != ops.end()){
        return true;
    }
    return false;
}

bool find_puncSign(const std::string& word){
    if(std::find(punctSigns.begin(), punctSigns.end(), word) != punctSigns.end()){
        return true;
    }
    return false;
}


bool isID(const std::string& cur_word){
    std::regex pattern(R"([A-Za-z_]\w*)");
    if(std::regex_match(cur_word, pattern)){
        return true;
    }
    return false;
}

bool isNumber(const std::string& cur_word){
    std::regex pattern(R"(0|([1-9]+[0-9]*))");
    if(std::regex_match(cur_word, pattern)){
        return true;
    }
    return false;
}


Token create_token(const std::string& cur_word){
    if(find_keyWord(cur_word) || find_type(cur_word) || find_op(cur_word)){
        TableNote tn{line_num, symb_num};
        Token t(cur_word, tn);
        symb_num += cur_word.length() + 1;
        return t;
    }
    if(find_puncSign(cur_word)){
        if(cur_word == "{" || cur_word == "(" || cur_word == "["){
            brackets.push(cur_word);
        }
        else if(cur_word == "}" || cur_word == ")" || cur_word == "]"){
            brackets.pop();
        }
        else if(cur_word == "'"){
            close_single_quotes++;
        }
        else if(cur_word == "\""){
            close_double_quotes++;
        }    
        TableNote tn{line_num, symb_num};
        Token t(cur_word, tn);
/*         std::cout << "i'ma here\t" << cur_word << "\n"; */
        symb_num += cur_word.length() + 1;
        return t;
    }

    if(isID(cur_word)){
        TableNote tn{line_num, symb_num, "id", "", level_scope};
        Token t(cur_word, tn);
        symb_num += cur_word.length() + 1;
        return t;
    }

    if(isNumber(cur_word)){
        TableNote tn{line_num, symb_num, "number", "", level_scope};
        Token t(cur_word, tn);
        symb_num += cur_word.length() + 1;
        return t;
    }

    return Token("", {});
}

void handle_line(const std::string& line, std::vector<Token>& tokens){
    if(!close_comment) return;
    std::string cur_word;
    char ch = '1';
    int size = line.length();
    for(int i = 0; i < size; ++i){
        if(line[i] == ' ' && cur_word.empty()) continue;
        if(line[i] == ' '){
            // проверить, является ли это словом синтаксиса (ключевое, или знак)
/*             std::cout << cur_word << " is cur_word\n"; */
            if(cur_word == "/*"){
                if(close_comment) close_comment = false;
                else close_comment = true;
                continue;
            }
            Token t = create_token(cur_word);
            tokens.push_back(t);
            cur_word.clear();
        }
        else{
            cur_word.push_back(line[i]);
        }
    }
    
}
