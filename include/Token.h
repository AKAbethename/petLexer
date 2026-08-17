#ifndef TOKEN_H
#define TOKEN_H

/* #include <iostream> */
#include <string>
#include <vector>

struct TableNote{
    int line_number;
    int symbol_number;
    std::string value = "";  // значение переменной, строки, и тд
    std::string type = "";  // тип переменной (для id)
    int level_scope = 0;  // место переменной в памяти (глоб - 1, лок - 2, блочная - 3, и тд)
  };

/* class Token{
  private:
    std::string title;
    TableNote definition;
  public:
    Token(std::string, TableNote);
}; */

struct Token{
  std::string title;
  TableNote definition;
  Token(std::string, TableNote);
};

void print_token(const Token&);

void print_tokens(const std::vector<Token>&);


#endif