#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	double f1,f2,f3,f4,f5;

	if ((fp = fopen("input.txt","r")) == NULL)
    {
        fprintf(stderr,"Errore nell\'apertura del file");
        system("pause");
        exit(1);
    }

    fscanf(fp, "%lf %lf %lf %lf %lf" , &f1, &f2, &f3, &f4, &f5);
    printf("I valori sono: \n %lf, \n %lf, \n %lf, \n %lf, \n %lf\n", f1, f2, f3, f4, f5);

    fclose(fp);
    printf("\n\n");
    system("pause");
    return 0;
}
