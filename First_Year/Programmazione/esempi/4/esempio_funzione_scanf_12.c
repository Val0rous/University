#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringa1[41];
    char stringa2[41];

    printf(" inserire una stringa (anche con spazi): ");
    scanf("%[^\n]",stringa1);
    fflush(stdin);

    printf("\n\n la parola inserita e\': %s",stringa1);

/*
il sistema legge qualsiasi tipo di frase incusi gli spazi
*/

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
