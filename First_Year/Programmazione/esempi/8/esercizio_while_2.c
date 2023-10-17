#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero, somma;
    int numeroValori, i, verifica;

    somma = 0;

	printf("Quanti valori vuoi sommare: ");
	verifica = scanf("%d", &numeroValori);
	fflush(stdin);
    if (verifica!=1){
        printf("\nError: wrong input value! Program closing.\n");
        exit(1);
    }

	if (numeroValori <= 0)
	{
        printf("\n\nErrore! Numero non valido!");
        exit(1);
	}

	i = 1;
	while(i <= numeroValori)
	{
		printf("Inserire valore %d: ", i);
		verifica = scanf("%f", &numero);
		fflush(stdin);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
		somma += numero;
		i++;
	}

	printf("\n\nLa somma dei %d valori inseriti: %f \n.", numeroValori, somma);

    printf("\n\n");
    system("pause");
    return 0;
}


