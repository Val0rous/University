#include <stdio.h>

int main()
{
    float numero, somma, media;
    int i;

    somma = 0;
	for (i = 0; i <= 4; i++)
	{
		printf("Inserire valore %02d: ", i+1);
		scanf("%f", &numero);
		fflush(stdin);
		somma += numero;
	}
	printf("\n\nIl numero di valori inseriti e\': %d: ", i);
	media = somma / ((float)i);
	printf("\n\nLa media dei valori inseriti e\': %.2f \n",media);

    printf("\n\n");
    system("pause");
    return 0;
}


