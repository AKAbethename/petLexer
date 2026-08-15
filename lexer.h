#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <fstream>

extern std::vector<std::string> types;

extern std::vector<std::string> keyWords;

extern std::vector<std::string> ops;

extern std::vector<std::string> punctSigns;

class Token;

void f();

void scan_code(const std::string& file_name );

void handle_line(const std::string&);

Token create_token(const std::string& cur_word);

bool isID(const std::string&);

// void scan_code("file.c") -- функция, проводящая лексический анализ и 
//                       создающая файл с потоком токенов

// bool isKey(<слово>) -- true, если это ключевое слово, иначе false 
// нужна обработка main(), знака @
// нужно следить за областью видимости: 1 -- глобальная, 2 -- влож, 3 -- влож влож, и тд

// bool close_single_quotes = true ''
// bool close_double_quotes = true ""
// bool close_comment = true /* */
// если что-то из них -- false, то ошибка


// void handle_int("строка") -- обработка числа int (не должно быть лишних символов)






#endif