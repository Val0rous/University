#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valore1, valore2;

    printf(" inserire un numero intero: ");
    scanf("%d",&valore1);
    fflush(stdin);

    printf("\n\n il numero intero inserito e\': %d",valore1);

    printf("\n\n inserire un secondo numero intero: ");
    scanf("%d",&valore2);
    fflush(stdin);

    printf("\n\n il numero intero inserito e\': %d",valore2);

    /*
    nel testare il programma provate i seguenti casi:
        - inserire il numero 56 (o qualsiasi numero intero) e premere INVIO
          noterete che il sistema legge e memmorizza corretamente il numero inserito
          nella variabile valore1; successivamente inserire il numero 345 (o qualsiasi numero intero) e premere INVIO
          noterete che il sistema legge e memmorizza corretamente il numero inserito
          nella variabile valore2
        - inserire il numero 56 (o qualsiasi numero intero) seguito da uno spazio e il numero
          534 e premere INVIO noterete che il sistema legge e memmorizza entrambi i valori, il primo
          nella variabile valore1 e il secondo nella variabile valore2; NOTARE CHE PER IL SECONDO SCANF
          IL PROGRAMMA NON SI BLOCCA
          LA STESSA COSA ACCADE SE INVECE DELLO SPAZIO INSERITE UN QUALSIASI ALTRO CARATTERE TRA I DUE
          NUMERI, L'UNICA COSA E' CHE NELLA VARIABILE2 VENGONO MEMORIZZATE DELLE COSE STRANE
    */

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
