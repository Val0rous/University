/*
preso in ingresso una lettera dall'utente il sistema indica il tipo di carattere inserito
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char lettera;

    printf("Inserire una lettera e premere INVIO: ");
    scanf("%c", &lettera);
    fflush(stdin);
    switch(lettera) {
        case 'a'...'z':
            printf("hai inserito una lettera in minuscolo\n");
            break;
        case 'A'...'Z':
            printf("hai inserito una lettera in maiuscolo\n");
            break;
        case '0'...'9':
            printf("hai inserito una cifra\n");
            break;
        default:
            printf("hai inserito un carattere che non corrisponde ne ad una lettera ne ad un numero\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
