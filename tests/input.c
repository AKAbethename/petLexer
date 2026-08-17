#include "stdio.h"

int main(){
    int k = 3;
    int l = k * 5;
    return 0;
}


/* 

<int, {3, 1, "", ""}> <main, {3, 5, "", ""}> <(, {3, 9, "", ""}> <), {3, 10, "", ""}> <{, {3, 11, "", ""}>
    <int, {4, 5, "", ""}> <id, {4, 9, "k", ""}> <=, {4, 11, "", ""}> <number, > <;>
    <int> <id> <=> <id> <bin_op> <number> <;>
    <id> <(> <literal> <,> <id> <bin_op> <id> <)> <;>
<}>

<id, "cnt">
<+, {number_line, number_symbol}>
<=, {}>

*/