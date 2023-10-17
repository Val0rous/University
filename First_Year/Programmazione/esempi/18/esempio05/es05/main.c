#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int main()
{
	FILE *fp;
	int count, array[MAX], data;
	int long offset;

	/*inizializza array*/
	printf("DATI INIZIALI:\n");
	for (count = 0; count < MAX; count++)
    {
        array[count] = 10*count;
        printf("L\'elemento in: %d ha valore: %d\n",count, array[count]);
    }
    printf("\n\nDATI FINALI:\n");


	/*apre un file*/
	if ((fp = fopen("random.dat","wb")) == NULL)
    {
        fprintf(stderr,"Errore nell\'apertura del file");
        system("pause");
        exit(1);
    }

    /*scrive l�array nel file*/
    if (fwrite(array, sizeof(int), MAX, fp) != MAX)
    {
        fprintf(stderr,"Errore nella scrittura su file");
        system("pause");
        exit(1);
    }
    fclose(fp);

    /*riapre allo stesso file per la lettura in modo binario*/
    if ((fp = fopen("random.dat","rb")) == NULL)
    {
        fprintf(stderr,"Errore nell\'apertura del file");
        system("pause");
        exit(1);
    }

    /*Chiede all�utente quale elemento leggere. Viene letto l�elemento
      e lo visualizza; termina se l�utente inserisce -1*/

    while(1)
    {
        printf("\n Inserire elemento da leggere, 0-%d, -1 per uscire: ",MAX-1);
        scanf("%ld",&offset);

        if (offset == -1)
        {
            break;
        }
        if(offset > 0 && offset < MAX)
        {
            /*Pone il segnaposto alla posizione richiesta*/
            if (fseek(fp, (offset*sizeof(int)), SEEK_SET) != 0)
            {
                fprintf(stderr,"Errore nell\'uso di fseek()");
                system("pause");
                exit(1);
            }

            /*Legge un numero intero*/
            fread(&data, sizeof(int), 1, fp);
            printf("L\'elemento in: %ld ha valore: %d", offset, data);
        }
    }

    fclose(fp);
    printf("\n\n");
    system("pause");
    return 0;
}
