#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero, somma, media;
    int i, verifica;

    somma = 0;
    i = 0;
	while(i <= 4)
	{
		printf("Inserire valore %02d: ", i+1);
		verifica = scanf("%f", &numero);
        fflush(stdin);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
		}
		somma += numero;
		i++;
	}
	printf("\n\nIl numero di valori inseriti e\': %d: ", i);
	media = somma / ((float)i);
	printf("\n\nLa media dei valori inseriti e\': %.2f \n",media);

    printf("\n\n");
    system("pause");
    return 0;
}


