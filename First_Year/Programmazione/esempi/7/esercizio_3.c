#include <stdio.h>

int main()
{
    int numero;
    int i;

	for (i = 1; i <= 10; i++)
	{
		printf("\nInserire un numero intero %d: ",i);
		scanf("%d", &numero);
		fflush(stdin);

		if ((numero % 2) == 1)
			printf("Il numero inserito e': dispari");
		else
			printf("Il numero inserito e': pari");
	}

    printf("\n\n");
    system("pause");
    return 0;
}


