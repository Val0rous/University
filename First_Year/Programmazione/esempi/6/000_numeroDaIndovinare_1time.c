/*
Indovina numero,
il programma utilizza esclusivamente
istruzioni if

viene dato 1 tentativo all'utente
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int numero, numeroDaIndovinare;

	numeroDaIndovinare = 1 + (rand()+time(NULL)) % 100; // Genera numeri tra 1 e 100

	printf("INDOVINA NUMERO\n\n");
	printf("inserisci un numero da 1 a 100 (tentativo 1): ");
	scanf("%d",&numero);
	fflush(stdin);
	if (numero == numeroDaIndovinare)
		printf("\nINDOVINATO!");
	else
	{
		if (numero < numeroDaIndovinare){
			printf("\nIl numero inserito e' piu' piccolo di quello da indovinare!");
		}
		else{
			printf("\nIl numero inserito e' piu' grande di quello da indovinare!");
        }
        printf("\n\nIl numero da indovinare era: %d", numeroDaIndovinare);
	}

	printf("\n\n");
    system("PAUSE");
    return 0;
}
