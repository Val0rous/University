#include <stdio.h>
#include <stdlib.h>

int main()
{
    char valore;

    printf(" inserire una lettera: ");
    scanf("%c",&valore);
    fflush(stdin);

    printf("\n\n la lettera inserita e\': %c",valore);

/*
provare ad inserire i seguenti valori:
    - una sola lettera, ad esempio la F e premere INVIO, noterete che il sistema
    legge e memorizza correttamente il valore
    - una parola, ad esempio GATTO e premere INVIO, noterete che il sistema
    legge e memorizza SOLO LA PRIMA LETTERA in quanto con il carattere di conversione
    %c diciamo al sistema di leggere UN CARATTERE
    - se inserite dei numeri, il sistema legge solo il primo carattere
*/

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
