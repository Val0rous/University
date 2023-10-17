#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringa1[11];
    char stringa2[11];

    printf(" inserire una stringa contenente solo le lettere: abcdef: ");
    scanf("%[abcdef]",stringa1);
    fflush(stdin);

    printf("\n\n la parola inserita e\': %s",stringa1);

/*
il sistema considera solo le lettere presenti all'interno delle parentesi quadre
*/

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
