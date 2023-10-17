#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matrice[2][3]; /* matrice non inizializzata con valori */
	int i, j;

	for (i=0; i<2; i++)
	{
		for (j=0; j<3; j++)
		{
			printf("matrice[%d][%d] = %d \n",i,j,matrice[i][j]);
		}
	}

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
