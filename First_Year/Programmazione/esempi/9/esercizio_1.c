#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
	int elenco[MAX];
	int i, temp, verifica;

	for (i = 0; i < MAX; i++)
	{
		printf("inserire valore %d: ",i);
		verifica = scanf("%d",&elenco[i]);
		fflush(stdin);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
	}

	/*inversione valore*/
	for (i = 0; i < (MAX/2); i++)
	{
		temp = elenco[i];
		elenco[i] = elenco[MAX-1-i];
		elenco[MAX-1-i] = temp;
	}


	printf("\n\nStampa del vettore invertito:");
	for (i = 0; i < MAX; i++)
		printf("\n elenco[%d] = %d",i,elenco[i]);

	printf("\n\n");
    system("PAUSE");
    return 0;
}


