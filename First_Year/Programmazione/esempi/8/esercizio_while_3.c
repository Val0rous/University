#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i = 1, verifica;

	while(i <= 10)
	{
		printf("\nInserire un numero intero %d: ",i);
		verifica = scanf("%d", &numero);
		fflush(stdin);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }

		if ((numero % 2) == 1)
			printf("Il numero inserito e': dispari");
		else
			printf("Il numero inserito e': pari");
        i++;
	}

    printf("\n\n");
    system("pause");
    return 0;
}


