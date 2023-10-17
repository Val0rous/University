/*
preso in ingresso una lettera il programma indica se si tratta di una vocale o consonante
(si suppone che l'utente inserisca dati corretti)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char lettera;

    printf("Inserire una lettera e premere INVIO: ");
    scanf("%c", &lettera);
    fflush(stdin);

    if (lettera == 'a' || lettera == 'A' || lettera == 'e' || lettera == 'E'
         || lettera == 'i' || lettera == 'I' || lettera == 'o' || lettera == 'O'
          || lettera == 'u' || lettera == 'U') {
        printf("hai inserito una vocale");
    }
    else {
        printf("hai inserito una consonante");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
