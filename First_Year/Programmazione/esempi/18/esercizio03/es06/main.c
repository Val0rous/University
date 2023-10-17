#include <stdlib.h>
#include <stdio.h>

int file_exists(char *filename);

int main()
{
	FILE *fp;
	char ch, source[81];
	int index;
	long count[127];

	printf("\n Inserire il nome del file: \n");
	scanf("%81s", source);

	if (file_exists(source))
    {
        fprintf(stderr,"\n Il file %s non esiste.\n", source);
        system("pause");
        exit(1);
    }

    if ((fp = fopen(source,"rb")) == NULL)
    {
        fprintf(stderr,"\n Errore durante apertura del file %s",source);
        system("pause");
        exit(1);
    }

    //Initializes array elements to 0
    for (index = 0; index < 127; index++)
        count[index] = 0;

    while(1)
    {
        ch = fgetc(fp);
        /*Termina se trova la fine del file*/
        if (feof(fp))
            break;
        /*Conteggio I caratteri fra 32 e 126*/
        if (ch > 31 && ch < 127)
            count[(int)ch]++;
    }

    /*visualizza i risultati*/
    printf("\n\nCarattere\tConteggio\n");
    for (index = 32; index < 127; index++)
        printf("%d\t%ld\n",index,count[index]);

    /*chiude il file e termina*/
    fclose(fp);

    return 0;
}


int file_exists(char *filename)
{
	/*La funzione restituisce 1 se il file esiste, 0 altrimenti*/

	FILE *fp;
	if ((fp = fopen(filename,"r")) == NULL)
        return 1;
    else
    {
        fclose(fp);
        return 0;
    }
}
