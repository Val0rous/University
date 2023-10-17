#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Verificare il funzionamento delle sequenze di escape
	printf("Esempio01: Forza Cesena!\n");
	printf("Esempio02: Forza\b Cesena!\n");
	printf("Esempio03: Forza\bCesena!\n");
	printf("Esempio04: Forza \bCesena!\n");
	printf("Esempio05: Forza Cesena!\a\n"); // Abilitare l'audio per sentire il segnale acustico

	printf("\n"); // Riga vuota

	int numeroAnni = 19;
    printf("Esempio06: Ho\b%d anni.\n", numeroAnni);
	printf("Esempio07: Ho \b%d anni.\n", numeroAnni);
	printf("Esempio08: Ho %d\b anni.\n", numeroAnni);
	printf("Esempio09: Ho %d\banni.\n", numeroAnni);
	printf("Esempio10: Ho %d \banni.\n", numeroAnni);

	system("pause");
	return 0;
}
