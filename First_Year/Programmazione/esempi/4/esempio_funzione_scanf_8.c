#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringa1[11];

    printf(" inserire una parola (massimo 10 caratteri): ");
    scanf("%10s",stringa1);
    fflush(stdin);

    printf("\n\n la parola inserita e\': %s",stringa1);


/*
Ogni volta che viene letta una stringa il sistema aggiunge in automatico un carattere
finale speciale: \0 come terminatore della stringa, per questo motivo se l'array di caratteri
(come nell'esempio sopra) viene dichiarato di 11 caratteri, quelli utili per l'iserimento della
stringa sono 10 visto che uno deve essere lasciato libero!

se si inseriscono 2 parole separate da uno spazio, il sistema legge solo la prima in quanto
lo spazio viene considerato dallo scanf come terminatore

NOTARE CHE NELLO SCANF NON VIENE INSERITO & PER LE STRINGHE
*/


    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
