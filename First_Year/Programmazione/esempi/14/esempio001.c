#include <stdio.h>

void fun1(int);
int fun2(void);

int pippo; // Variabile globale
extern paperino; // Variabile esterna

int main(){
    int j; //variabile locale
    int i = 2; //variabile locale
    printf("pippo (all\'inizio): %d\n",pippo);
    printf("paperino (all\'inizio): %d\n",paperino);
    fun1(i);
    printf("pippo (dopo fun1): %d\n",pippo);
    printf("paperino (dopo fun1): %d\n",paperino);
    j = fun2();
    printf("pluto (dopo primo fun2): %d\n",j);
    j = fun2();
    printf("pluto (dopo secondo fun2): %d\n",j);

    return 0;
}

int paperino = 10;
void fun1(int i){
    pippo = paperino + i; // pippo variabile globale
}

int fun2(){
    static int pluto; // pluto è inizializzato solo alla prima chiamata a f2
    pluto = pluto + 1;
    return pluto;
}
