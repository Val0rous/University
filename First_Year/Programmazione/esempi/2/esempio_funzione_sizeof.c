#include <stdio.h>

int main()
{

    printf("\n numero intero (int) byte: %d", sizeof(int));
    printf("\n numero intero lungo (long int) byte: %d", sizeof(long int));
    printf("\n numero carattere (char) byte: %d", sizeof(char));
    printf("\n numero con virgola (float) byte: %d", sizeof(float));
    printf("\n numero con virgola (double) byte: %d", sizeof(double));
    printf("\n numero con virgola (long double) byte: %d", sizeof(long double));

    return 0;
}
