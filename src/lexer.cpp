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

static int line_num = 1;

static int symb_num = 0;

static int close_single_quotes = 0;

static int close_double_quotes = 0;

static int level_scope = 1;

static bool close_comment = true;

static bool close_figure_bracket = true;

static bool close_square_bracket = true;

static bool close_circle_bracket = true;

static std::stack<std::string> brackets;


std::string get_split_line(const std::string& line){
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
    return new_line;
}

void scan_code(const std::string& file_name){
    std::vector<Token> token_stream;
    std::ifstream file(file_name);
    std::string line;
    while(std::getline(file, line)){
        std::string split_line = get_split_line(line);
        handle_line(split_line, line, token_stream); // "line" for finding symb_num 
    }
    print_tokens(token_stream);
}


bool find_type(const std::string& word){
    if(std::find(types.begin(), types.end(), word) != types.end()) return true;
    return false;
}

bool find_keyWord(const std::string& word){
    if(std::find(keyWords.begin(), keyWords.end(), word) != keyWords.end())
        return true;
    return false;
}

bool find_op(const std::string& word){
    if(std::find(ops.begin(), ops.end(), word) != ops.end()) return true;
    return false;
}

bool find_puncSign(const std::string& word){
    if(std::find(punctSigns.begin(), punctSigns.end(), word) != punctSigns.end()) 
        return true;
    return false;
}


bool isID(const std::string& cur_word){
    std::regex pattern(R"([A-Za-z_]\w*)");
    if(std::regex_match(cur_word, pattern)) return true;
    return false;
}

bool isNumber(const std::string& cur_word){
    std::regex pattern(R"(0|([1-9]+[0-9]*))");
    if(std::regex_match(cur_word, pattern)) return true;
    return false;
}


Token create_token(const std::string& cur_word, const std::string& orig_line, 
                                                int last_symb_num){
    for(int i = last_symb_num; i < orig_line.length(); ++i){
        if(orig_line[i] == cur_word[0]) {symb_num = i+1; break;}
    }
    if(find_keyWord(cur_word) || find_type(cur_word) || find_op(cur_word)){
        TableNote tn{line_num, symb_num};
        Token t(cur_word, tn);
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
        return t;
    }

    if(isID(cur_word)){
        TableNote tn{line_num, symb_num, "id", "", level_scope};
        Token t(cur_word, tn);
        return t;
    }

    if(isNumber(cur_word)){
        TableNote tn{line_num, symb_num, "number", "", level_scope};
        Token t(cur_word, tn);
        return t;
    }
    return Token("", {});
}

void handle_line(const std::string& line, std::string& orig_line, std::vector<Token>& tokens){
    if(!close_comment) return;
    std::string cur_word;
    int size = line.length();
    for(int i = 0; i < size; ++i){
        if(line[i] == ' ' && cur_word.empty()) continue;
        else if(line[i] == ' '){
            if(cur_word == "/*"){
                if(close_comment) close_comment = false;
                else close_comment = true;
                continue;
            }
            Token t = create_token(cur_word, orig_line, symb_num);
            tokens.push_back(t);
            cur_word.clear();
        }
        else cur_word.push_back(line[i]);
    }
    symb_num = 0; ++line_num; 
}
