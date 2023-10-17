#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(){

    /*dichiaro e inizializzo un array di interi ed un puntatore associato*/
    int iarray[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p_iarray;
    p_iarray = iarray;

    /*dichiaro e inizializzo un array di float ed un puntatore associato*/
    float farray[MAX] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    float *p_farray;
    p_farray = farray;

    /* altre variabili utili*/
    int i;

    /*guardo lo spazio occupato da int e float*/
    printf("\n sizeof(int) = %d\n", sizeof(int));
    printf("\n sizeof(float) = %d\n", sizeof(float));

    /*Stampo gli elementi degli array*/
    printf("\nARRAY DI FLOAT\n");
    for (i=0; i<MAX; i++){
        printf("Posizione: %d | Valore (diretto) = %d | Valore (indiretto) = %d| Posizione memoria (diretto) = %d | Posizione memoria (indiretto) = %d\n", i, iarray[i], *p_iarray, &iarray[i], p_iarray);
        p_iarray++;
    }

    /*Stampo gli elementi degli array*/
    printf("\nARRAY DI FLOAT\n");
    for (i=0; i<MAX; i++){
        printf("Posizione: %d | Valore (diretto) = %1.1f | Valore (indiretto) = %1.1f | Posizione memoria (diretto) = %d | Posizione memoria (indiretto) = %d\n", i, farray[i], *p_farray, &farray[i], p_farray);
        p_farray++;
    }

    printf("\n\n");
	system("pause");
	return 0;
}
