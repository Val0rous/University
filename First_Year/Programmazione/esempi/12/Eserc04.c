#include <stdio.h>
#include <stdlib.h>

int main(){
	int elenco[5] = {1,1,1,1,1};
	int valori[5] = {2,2,2,2,2};
	int i;
	int *ptr;
    ptr = valori;

	printf("\n\nPrima di modificare:\n");
	for (i=0; i<5; i++){
		printf("\t%d \t%d\n",elenco[i],valori[i]);
	}


	for (i=0; i<5; i++){
        //valori[i]= i*2;
        //*(valori+i) = i*2;
        //*ptr++ = i*2;
		*(ptr + i) = i*2;
	}

	printf("\n\nDopo la modifica:\n");
	for (i=0; i<5; i++){
		printf("\t%d \t%d\n",elenco[i],valori[i]);
	}

    printf("\n\n");
	system("pause");
	return 0;
}

