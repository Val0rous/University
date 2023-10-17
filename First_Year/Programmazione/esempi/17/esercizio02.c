#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define FINTOCLS1 printf("\e[1;1H\e[2J")

float funSomma(int valore1, int valore2){
	printf("Funzione SOMMA\n");
	return valore1+valore2;
}

float funSottrazione(int valore1, int valore2){
	printf("Funzione SOTTRAZIONE\n");
	return valore1-valore2;
}

float funMoltiplicazione(int valore1, int valore2){
	printf("Funzione MOLTIPLICAZIONE\n");
	return valore1*valore2;
}

float funDivisione(int valore1, int valore2){
	printf("Funzione DIVISIONE\n");
	return valore1/(float)valore2;
}

float funX(int valore1, int valore2, float (*f)(int, int)){
	float outVar = f(valore1, valore2);
	printf("Valore input1: %d\n", valore1);
	printf("Valore input2: %d\n", valore2);
	printf("Valore output: %f\n", outVar);
}


int main()
{
    char opzione;
    int selezione;
    int flag_ok;
    int valoreA, valoreB;
    float outputValue;
    valoreA = 2;
    valoreB = 3;

    flag_ok = 1;
    while (flag_ok){
        system("cls");
        printf("\n\n Seleziona l\'operazione:\n");
        printf("\n 1 - Somma");
        printf("\n 2 - Differenza");
        printf("\n 3 - Moltiplicazione");
        printf("\n 4 - Divisione");
        printf("\n 5 - Esci");
        printf("\n\n > ");
        fflush(stdin);
        opzione = getch();
        selezione = atoi(&opzione);
        if (selezione>=1 & selezione<=5){
            FINTOCLS1;
            flag_ok = 0;
        }
    }

    if (selezione==1){
        outputValue = funX(valoreA, valoreB, funSomma);
    } else if (selezione==2){
        outputValue = funX(valoreA, valoreB, funSottrazione);
    } else if (selezione==3){
        outputValue = funX(valoreA, valoreB, funMoltiplicazione);
    } else if (selezione==4){
        outputValue = funX(valoreA, valoreB, funDivisione);
    } else {
        printf("\n\nNo correct operation selected!\n\n");
    }

	printf("\n\n");
	system("pause");
    return 0;

}
