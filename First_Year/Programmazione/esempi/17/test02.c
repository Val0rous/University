#include <stdlib.h>
#include <stdio.h>

int funX2(char lettera, int valore){
	printf("Funzione: %c\n", lettera);
	return valore*2;
}

int funX3(char lettera, int valore){
	printf("Funzione: %c\n", lettera);
	return valore*3;
}

int funX4(char lettera, int valore){
	printf("Funzione: %c\n", lettera);
	return valore*4;
}

int funX(char lettera, int valore, int (*f)(char, int)){
	int outVar = f(lettera, valore);
	printf("Valore input: %d\n", valore);
	printf("Valore output: %d\n", outVar);
	return outVar;
}


int main()
{
	int selezione, outputValue;

    selezione = 1;

    if (selezione==2){
        outputValue = funX('a', 2, funX2);
    } else if (selezione==3){
        outputValue = funX('b', 2, funX3);
    } else {
        outputValue = funX('c', 2, funX4);
    }

	printf("\n\n");
	system("pause");
    return 0;

}
