#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variabileInt;
    int lunghezza;

    variabileInt = 123;
    lunghezza = 0;

    lunghezza = printf("VariabileInt: %d", variabileInt);
    printf("\n(sono stati stampati %d caratteri)", lunghezza);

    printf("\n\n");
    system("pause");
    return 0;
}
