#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	float data[5];
	int count;
	char filename[1000];

	puts("\nInserire cinque numeri decimali (premere ENTER dopo ogni numero inserito):");
	for (count = 0; count < 5; count++)
    {
        scanf("%f",&data[count]);
        fflush(stdin);
    }

	puts("\nInserire il nome del file (compresa l\'estensione .txt):");
	gets(filename);

	if ((fp = fopen(filename,"w")) == NULL)
    {
        fprintf(stderr,"Errore nell’apertura del file %s", filename);
        system("pause");
        exit(1);
    }

    /*scrive i dati su file e su stdout*/
    for (count = 0; count < 5; count++)
    {
        fprintf(fp, "\ndata[%d] = %f", count, data[count]);
        fprintf(stdout, "\ndata[%d] = %f", count, data[count]);
    }
    fclose(fp);
    printf("\n\n");
    system("pause");
    return 0;
}
