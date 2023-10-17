/* Primo esempio di utilizzo degli operatori matematici */
#include <stdio.h>

int main()
{
	int a, b, ris;

	a = 10;
	b = 5;
	ris = a - b;
	printf("risultato di %d - %d e\' %d\n",a,b,ris);

	a = 7;
	b = 3;
	ris = a * b;
	printf("risultato di %d * %d e\' %d\n",a,b,ris);

	a = 21;
	b = 7;
	ris = a / b;
	printf("risultato di %d / %d e\' %d\n",a,b,ris);

	a = 21;
	b = 10;
	ris = a / b;
	printf("risultato di %d / %d = %d\n",a,b,ris);

	a = 13;
	b = 5;
	ris = a % b;
	printf("risultato di %d %% %d = %d\n",a,b,ris); /*con %% viene stampato il simbolo %*/

	return 0;
}


