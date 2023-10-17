#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stringa1[11];
    char stringa2[11];

    printf(" inserire una stringa che non contiene le lettere: abcdef: ");
    scanf("%[^abcdef]",stringa1); /*il sistema quando si inserisce una lettera tra quelle all'interno delle parentesi quadre*/
    // scanf("%[^abcdef ]",stringa1); /*il sistema quando si inserisce una lettera tra quelle all'interno delle parentesi quadre, compreso lo spazio*/
    //scanf("%[^abcdef\n]",stringa1); /*il sistema quando si inserisce una lettera tra quelle all'interno delle parentesi quadre,o si preme ENTER*/
    //scanf("%[^abcdef \n]",stringa1); /*il sistema quando si inserisce una lettera tra quelle all'interno delle parentesi quadre, compreso lo spazio, o si preme ENTER*/
    fflush(stdin);

    printf("\n\n la parola inserita e\': %s",stringa1);

/*
il sistema considera solo le lettere CHE NON SONO presenti all'interno delle parentesi quadre
*/

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
