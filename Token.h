#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct TableNote{
    int line_number;
    int symbol_number;
    std::string value = "";  // значение переменной, строки, и тд
    std::string type = "";  // тип переменной (для id)
    int level_scope = 0;  // место переменной в памяти (глоб - 1, лок - 2, блочная - 3, и тд)


  };

class Token{
  private:
    std::string title;
    TableNote definition;
  public:
    Token(std::string, TableNote);
};


#endif