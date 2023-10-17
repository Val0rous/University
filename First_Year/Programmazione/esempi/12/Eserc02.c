#include <stdio.h>
#include <stdlib.h>

int main(){
	int A;
	int *ptr;

	A = 10;
	ptr = &A;

	printf("%d \n", A); //valore presente dentro alla variabile A
	printf("%d \n", &A); //indirizzo di memoria della variabile A
	printf("%d \n", ptr); //contenuto della variabile ptr, (indirizzo di A)
	printf("%d \n", *ptr); /*valore presente all’interno della cella con indirizzo in ptr, quindi il valore di A*/
	printf("%d \n", &ptr); //indirizzo di memoria della variabile ptr

    printf("\n\n");
	system("pause");
	return 0;
}

