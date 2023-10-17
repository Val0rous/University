#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define LUNGHEZZA_MAX 100

int main(void){

    //Variabili
    int i, dim_frase;
    char frase[LUNGHEZZA_MAX];

    //In questa fase del programma emorizzo la frase
    printf("Inserisci frase da modificare (la frase non deve contenere numeri: ");

    //Prendere frase
    scanf("%[^0123456789\n]", frase);
    fflush(stdin);
    dim_frase = strlen(frase);

    //Tramite la funzione toupper() converto la frase in maiuscolo
    for(i=0; i<dim_frase; i++){
        if (!isspace(frase[i]) && !ispunct(frase[i])){
            if (frase[i]==(char)0x8A || frase[i]==(char)0x85 || frase[i]==(char)0x8D || frase[i]==(char)0x95 || frase[i]==(char)0x97){
                frase[i] = frase[i];
            } else {
                frase[i] = toupper(frase[i]);
            }
        }
    }
    printf("\n\nLa frase in stampatello maiuscolo e': \n%s\n", frase);

    //Tramite la funzione tolower() converto la frase in minuscolo
    for(i=0; i<dim_frase; i++){
        if (!isspace(frase[i]) && !ispunct(frase[i])){
            if (frase[i]==(char)0x8A || frase[i]==(char)0x85 || frase[i]==(char)0x8D || frase[i]==(char)0x95 || frase[i]==(char)0x97){
                frase[i] = frase[i];
            } else {
                frase[i] = tolower(frase[i]);
            }
        }
    }
    printf("\n\nLa frase in minuscolo e': \n%s\n", frase);

    printf("\n\n");
    system("pause");
    return 0;
}


