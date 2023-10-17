#include <stdio.h>

void funzione1(void);

int main(){
    int conta;
    for (conta = 0; conta < 10; conta++){
        printf("Alla iterazione %d: ", conta);
        funzione1();
    }
    return 0;
}

void funzione1(){
    static int x = 0;
    int y = 0;
    printf("x = %d, y = %d\n", x++, y++);
}
