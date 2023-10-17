#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valore;

    printf(" inserire un numero decimale: ");
    scanf("%f",&valore);
    fflush(stdin);

    printf("\n\n il numero decimale inserito e\': %f",valore);

/*
come per gli esempi con i numeri interi, solo che si utilizza un tipo di dato differente,
utilizzare il . (punto)  come separatore per i decimali!
*/

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
