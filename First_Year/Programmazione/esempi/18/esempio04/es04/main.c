#include <stdlib.h>
#include <stdio.h>

#define SIZE 20

int main()
{
	FILE *fp;
	int count, array1[SIZE], array2[SIZE];

	/*inizializza array1[]*/
	for (count = 0; count < SIZE; count++)
		array1[count] = 2*count;

	/*apre un file in modo binario*/
	if ((fp = fopen("direct.txt","wb")) == NULL)
    {
        fprintf(stderr,"Errore nell\’apertura del file");
        system("pause");
        exit(1);
    }

    /*salva array1[] sul file*/
    if (fwrite(array1, sizeof(int), SIZE, fp) != SIZE)
    {
        fprintf(stderr,"Errore nella scrittura su file");
        system("pause");
        exit(1);
    }
    fclose(fp);

    /*riapre lo stesso file per la lettura in modo binario*/
    if ((fp = fopen("direct.txt","rb")) == NULL)
    {
        fprintf(stderr,"Errore nell\’apertura del file");
        exit(1);
    }

    /*legge i dati in array2[]*/
    if (fread(array2, sizeof(int), SIZE, fp) != SIZE)
    {
        fprintf(stderr,"Errore di lettura del file");
        system("pause");
        exit(1);
    }
    fclose(fp);

    /*visualizza a monitor i valori di array2[]*/
    printf("array1\tarray2\n");
    for(count = 0; count < SIZE; count++)
    {
        printf("%d\t%d\n",array1[count],array2[count]);
    }

    return 0;
}
