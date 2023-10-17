#include <stdio.h>
#include <stdlib.h>

int main(){
	int elenco[5] = {3, 14, 7, 89, 10};
	int matrice[3][2] = {1, 2, 3, 4, 5, 6};
	int i, j;
	int *p_elenco = elenco;
	int *p_matrice = matrice;

	printf("\n\n->Esercizio 3A\n\n");
	printf("%d \n", elenco); //indirizzo di memoria della prima cella
	printf("%d \n", &elenco[0]); //indirizzo di memoria della prima cella
	printf("%d \n", p_elenco); //indirizzo di memoria della prima cella
	printf("%d \n", elenco[0]); //valore della prima cella, quindi 3
	printf("%d \n", *elenco); //valore della prima cella, quindi 3
	printf("%d \n", *p_elenco); //valore della prima cella, quindi 3

	printf("\n\n->Esercizio 3B\n\n");
    for (i=0; i<5; i++){
		printf("\t%d \t%d \t%d\n", elenco[i], *p_elenco++, *(elenco+i));
    }

    printf("\n\n->Esercizio 3C\n\n");
    for (i=0; i<3; i++){
		for (j=0; j<2; j++){
			printf("\t%d\t %d\t %d\n", matrice[i][j], *p_matrice++, *(*(matrice+i)+j));
		}
    }

    printf("\n\n");
	system("pause");
	return 0;
}

