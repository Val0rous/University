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
        case 'A'...'Z':
            printf("hai inserito una lettera dell'alfabeto\n");
            printf("la lettera inserita e' in ");
            if (lettera >= 65 && lettera <= 90) {
                printf("maiuscolo");
            }
            else {
                printf("minuscolo");
            }
            printf("\nla lettera inserita e' una ");
            if (lettera == 'a' || lettera == 'A' || lettera == 'e' || lettera == 'E'
                 || lettera == 'i' || lettera == 'I' || lettera == 'o' || lettera == 'O'
                  || lettera == 'u' || lettera == 'U') {
                printf("vocale");
            }
            else {
                printf("consonante");
            }
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
