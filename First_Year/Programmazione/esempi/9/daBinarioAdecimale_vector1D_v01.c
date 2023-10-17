/* Convert from a binary number to a decimal one */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LENGTHVECTOR 8

int main()
{

    int binaryVector[LENGTHVECTOR];
    int binaryInput, decimalInput, i, j, verifica;

    /* Vector initialization */
    for (i=0; i<LENGTHVECTOR; i++)
    {
        binaryVector[i]=0;
    }

    /* Ask the binary number to the user */
    printf("\nInsert a binary number with %d characters:\n", LENGTHVECTOR);
    for (i=0; i<LENGTHVECTOR; i++)
    {
        verifica = scanf("%1d", &binaryInput);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
        binaryVector[i] = binaryInput;
    }
    fflush(stdin);

    /* Show vector */
    system("cls");
    printf("\nBinary number: ");
    for (i=0; i<LENGTHVECTOR; i++)
    {
        binaryInput = binaryVector[i];
        if (binaryInput>1)
        {
            system("cls");
            printf("\nWRONG INPUT VALUE!\n\n", LENGTHVECTOR);
            system("pause");
            exit(1);
        }
        printf("%d",binaryVector[i]);
    }

    /* Convert binary input into decimal number */
    decimalInput = 0;
    for (i=LENGTHVECTOR-1, j=0; i>=0; i--, j++)
    {
        binaryInput = binaryVector[i];
        decimalInput = decimalInput + (binaryInput*pow(2,j));
    }

    /* Show decimal */
    printf(" -> Decimal number: %d\n", decimalInput);

	printf("\n\n");
    system("PAUSE");
    return 1;
}
