#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valore;

    while(1)
    {
        puts(" Inserire un numero intero (per terminare inserire -1): ");
        scanf("%d", &valore);
        fflush(stdin);

        if (valore==-1)
        {
            break;
        }

        printf("\n\n il numero intero inserito e\': %d",valore);

        /*
        nel testare il programma provate i seguenti casi:
            - inserire il numero 56 (o qualsiasi numero intero) e premere INVIO
              noterete che il sistema legge e memmorizza corretamente il numero inserito
              nella variabile valore
            - inserire il numero 56.943 (o qualsiasi numero decimale) e premere INVIO
              noterete che il sistema legge SOLO LA PARTE INTERA e la memmorizza nella variabile
            - inserire il numero 56pippo (o qualsiasi numero seguito da lettere) e premere INVIO
              noterete che il sistema legge SOLO IL NUMERO e la memmorizza nella variabile
        */

        printf("\n\n");

    }

	printf("\n\n");
    system("PAUSE");
    return 0;
}
