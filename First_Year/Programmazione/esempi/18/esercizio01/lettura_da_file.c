#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    double numeroDaScrivere, numeroLetto;

    numeroDaScrivere = 7.4325;
    if ((fp = fopen("test.txt","w")) == NULL)
        exit(1);
    fprintf(fp,"%f",numeroDaScrivere);
    fclose(fp);

    if ((fp = fopen("test.txt","r")) == NULL)
        exit(1);
    fscanf(fp,"%lg",&numeroLetto);
    fclose(fp);
    printf(" il numero letto: %f \n",numeroLetto);
    printf("\n\n");

    system("pause");
    return 0;
}
