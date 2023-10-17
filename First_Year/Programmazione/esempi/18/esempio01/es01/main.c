#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	char filename[1000], mode[4], ch;

	while(1)
	{
		/*legge il nome del file e il modo*/

		printf("\n Inserire il nome del file (compresa l'estensione): ");
		gets(filename);
		printf("\n Inserire il modo (max 3 caratteri): ");
		gets(mode);

		/*Apertura del file*/

		if ((fp = fopen(filename,mode)) != NULL)
		{
			printf("\n OK: il file \'%s\' e\' aperto in modo \'%s\'!\n",filename,mode);
			fprintf(fp, "OK: il file \'%s\' e\' aperto in modo \'%s\'!\n",filename,mode);
			fclose(fp);
		}
		else
        {
            printf("\n Il file '%s' non esiste o il modo '%s' non e\' tra quelli eseguibili.",filename,mode);
        }

        puts("\n Premere \'x\' per uscire, un altro tasto per proseguire.\n");
        if ((ch = getc(stdin)) == 'x')
        {
            break;
        }
	}
    return 0;
}
