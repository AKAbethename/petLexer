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

void scan_code(const std::string& file_name){
    std::vector<Token> token_stream;
    std::ifstream file(file_name);
    std::string line;
    while(std::getline(file, line)){
        std::cout << line << "\n";
    }
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

Token create_token(const std::string& cur_word){
    if(find_keyWord(cur_word) || find_type(cur_word) || find_op(cur_word)){
        TableNote tn{line_num, symb_num};
        Token t(cur_word, tn);
        symb_num += cur_word.length() + 1;
        return t;
    }
    else if(find_puncSign(cur_word)){
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
        symb_num += cur_word.length() + 1;
        return t;
    }

    if(isID(cur_word)){
        TableNote tn{line_num, symb_num, cur_word, "", level_scope};
        Token t(cur_word, tn);
        symb_num += cur_word.length() + 1;
        return t;
    }

    return Token("", {});
}

void handle_line(const std::string& line){
    std::string cur_word;
    char ch = '1';
    int size = line.length();
    for(int i = 0; i < size; ++i){
        if(line[i] == ' '){
            // проверить, является ли это словом синтаксиса (ключевое, или знак)

        }
        else{
            cur_word.push_back(line[i]);
        }

    }
    
}
