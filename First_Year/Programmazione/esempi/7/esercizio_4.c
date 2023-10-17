#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numero, numeroCasuale;
    int i;

    printf("Indovina il numero!\n");

    /*
    il % 100 serve fare in modo che il numero da indovinare non sia maggioare di 100
    */
    numeroCasuale = ((rand()+time(NULL)) % 100) + 1; //per avere un numero tra 1 e 100.
	printf("\nIl numero da indovinare e\': %d\n",numeroCasuale);

	for (i = 1; i <= 3; i++)
	{
		printf("\nTentativo %d: ", i);

		scanf("%d", &numero);
		fflush(stdin);

		if (numero == numeroCasuale)
		{
		    printf("\nIndovinato!");
		    break;
		}
		else
		{
			printf(" Sbagliato!");
			if (numero > numeroCasuale)
				printf(" Il numero da indovinare e\' piu\' piccolo di quello inserito!");
			else
				printf(" Il numero da indovinare e\' piu\' grande di quello inserito!");
		}
	}
	if (i > 3)
		printf("\n\nTentativi esauriti!\n\n");

    printf("\n\n");
    system("pause");
    return 0;
}


