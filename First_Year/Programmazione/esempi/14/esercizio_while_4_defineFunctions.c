#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PULISCI system("cls");
#define FERMATI system("pause");
#define CASUALE_1_100 (1 + (rand()+time(NULL))%(100+1-1));

int main()
{
    int numero, numeroCasuale;
    int i=1;

    printf("Indovina il numero!\n");

    numeroCasuale = CASUALE_1_100;
	printf("\nIl numero da indovinare e\': %d\n",numeroCasuale);

	printf("\n");
	FERMATI
	PULISCI

	while(i <= 3)
	{
		printf("\nTentativo %d: ", i);

		scanf("%d", &numero);
		fflush(stdin);

		if (numero == numeroCasuale)
		{
		    printf("\nIndovinato!\n");
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

	return 0;
}


