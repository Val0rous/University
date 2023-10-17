#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valore1, valore2;

    printf(" inserire un numero intero: ");
    scanf("%d %d",&valore1, &valore2);
    fflush(stdin);

    printf("\n\n i valori inseriti sono: %d %d",valore1,valore2);

    /*
        simile all'esempio 2, in questo caso se inserite un solo numero e premete INVIO
        il sistema attende anche l'inserimento del secondo valore
    */

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
