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

    if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u') {
        printf("hai inserito una vocale minuscola");
    }
    else if (lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U')
          {printf("Hai inserito una vocale maiuscola");}
    else {
        printf("hai inserito una consonante");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
