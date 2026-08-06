#ifndef TABLE_SYMBS.H
#define TABLE_SYMBS.H

#include <iostream>
#include <unordered_map>
#include <memory>

struct TableNote{
    int string_number;
    int symbol_number;
    std::string type = "";
};


class Table{
  private:
//    std::unordered_map<std::string, std::unique_ptr<TableNote>> table; 
    std::unordered_map<std::string, TableNote*> table;

  public:
    Table(const std::string&, TableNote*);
};

#endif