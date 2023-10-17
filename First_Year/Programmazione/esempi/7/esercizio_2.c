#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero, somma;
    int numeroValori, i;

    somma = 0;

	printf("Quanti valori vuoi sommare: ");
	scanf("%d", &numeroValori);
	fflush(stdin);

	if (numeroValori <= 0)
	{
        printf("\n\nErrore! Numero non valido!");
        exit(1);
	}

	for (i = 1; i <= numeroValori; i++)
	{
		printf("Inserire valore %d: ", i);
		scanf("%f", &numero);
		somma += numero;
	}

	printf("\n\nLa somma dei %d valori inseriti: %f \n.", numeroValori, somma);

    printf("\n\n");
    system("pause");
    return 0;
}


