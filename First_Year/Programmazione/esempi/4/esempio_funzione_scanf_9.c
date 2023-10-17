#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringa1[11];
    char stringa2[11];

    printf(" inserire una parola (massimo 10 caratteri): ");
    scanf("%10s",stringa1);
    fflush(stdin);

    printf("\n\n la parola inserita e\': %s",stringa1);

    printf("\n\n inserire una seconda parola (massimo 10 caratteri): ");
    scanf("%10s",stringa2);
    fflush(stdin);

    printf("\n\n la seconda parola inserita e\': %s",stringa2);

/*

se si inseriscono 2 parole separate da uno spazio e si preme invio, entrambe le parole,
la prima viene memorizzata in stringa1 e la seconda in stringa2
*/


    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
