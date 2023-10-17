// Author: Filippo
// Date: 20191014
// Description: In questo esercizio andremo a cercare una seconda parola dentro ad una prima parola e nel caso di presenza sostituiremo con *. L'intero esercizio e' stato risolto senza libreria string.h.

#include<stdio.h>
#include<stdlib.h>

#define CARATTERE '*'
#define MAXLENGHTSTR 101

int main(){

    // Variabili
    char str1[MAXLENGHTSTR+1], str2[MAXLENGHTSTR+1];
    int verifica, length_str1, length_str2;

    // Inizializzazione
    //memset(input_string1,'\0',size(input_string1));
    //memset(input_string2,'\0',size(input_string2));
    for(length_str1 = 0; length_str1<=MAXLENGHTSTR; length_str1++){
        str1[length_str1] = '\0';
    }
    for(length_str2 = 0; length_str2<=MAXLENGHTSTR; length_str2++){
        str2[length_str2] = '\0';
    }

    // Input
    printf("\tInserire la prima parola: ");
    verifica = scanf("%[^ \n\t]", &str1);
    fflush(stdin);
    if (verifica!=1){
        printf("Valore inserito non corretto\n");
        exit(0);
    }
    printf("\tInserire la seconda parola: ");
    verifica = scanf("%[^ \n\t]", &str2);
    fflush(stdin);
    if (verifica!=1){
        printf("Valore inserito non corretto\n");
        exit(0);
    }

    // Visualizzazione parole
    printf("\nLa prima parola e\': %s", str1);
    printf("\nLa seconda parola e\': %s", str2);

    // Stima lunghezza
    for(length_str1 = 0; str1[length_str1] != '\0'; length_str1++);
    printf("\nLunghezza stringa1 (numero di caratteri):\t %d", length_str1);

    for(length_str2 = 0; str2[length_str2] != '\0'; length_str2++);
    printf("\nLunghezza stringa2 (numero di caratteri):\t %d", length_str2);

    // Confronto lunghezze
    if (length_str1<length_str2){
        printf("\nLa prima parola e\' piu\' piccola della seconda parola!\n");
    } else if (length_str1<length_str2){
        printf("\nLa prima parola e\' piu\' grande della seconda parola!\n");
    } else {
        printf("\nLe due parole hanno la stessa lunghezza!\n");
    }

    system("pause");
    return 0;

}
