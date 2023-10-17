#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variabileInt;

    printf("\n variabile NON inizializzata: %d", variabileInt);
    printf("\n posizione memoria variabile NON inizializzata: %d", &variabileInt);

    variabileInt = 175;

    printf("\n variabile inizializzata: %d", variabileInt);
    printf("\n posizione memoria variabile inizializzata: %d", &variabileInt);

    printf("\n\n");
    system("pause");
    return 0;
}
