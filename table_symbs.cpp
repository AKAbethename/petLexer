#include "table_symbs.h"

Table::Table(const std::string& tokenName, TableNote* note = nullptr) :
    table(std::unordered_map<std::string, TableNote*> {{tokenName, note}}) {}

