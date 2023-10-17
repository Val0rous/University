/*
preso in ingresso una lettera il programma indica se si tratta di una vocale o consonante
(si suppone che l'utente inserisca dati corretti)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char lettera;

    printf("Inserire una lettera e premere INVIO: ");
    scanf("%c", &lettera);
    fflush(stdin);
    switch(lettera) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("hai inserito una vocale");
            break;
        default:
            printf("hai inserito una consonante");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
