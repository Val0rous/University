#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numero, numeroCasuale;
    int i=1, verifica;

    printf("Indovina il numero!\n");

    /*
    il % 100 serve fare in modo che il numero da indovinare non sia maggioare di 100
    */
    numeroCasuale = ((rand()+time(NULL)) % 100) + 1; //per avere un numero tra 1 e 100.
	printf("\nIl numero da indovinare e\': %d\n",numeroCasuale);

	while(i <= 3)
	{
		printf("\nTentativo %d: ", i);
		verifica = scanf("%d", &numero);
		fflush(stdin);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }

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
		i++;
	}
	if (i > 3)
		printf("\n\nTentativi esauriti!\n\n");

    printf("\n\n");
    system("pause");
    return 0;
}


