#include "stdio.h"

int main(){
    int k = 3;
    int l = k * 5;
    printf("%d\n", k + l);
    return 0;
}


/* 

<int> <main> <(><)><{>
    <int> <id> <=> <number> <;>
    <int> <id> <=> <id> <bin_op> <number> <;>
    <id> <(> <literal> <,> <id> <bin_op> <id> <)> <;>
<}>

*/