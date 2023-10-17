#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B;
	int *ptr;

	A = 10;
	B = A;
	ptr = &A;
	printf("\nPrima di modificare A:\n");
	printf("A = %d \n", A);
	printf("B = %d \n", B);
	printf("*ptr = %d \n", *ptr);

	A = 35;
	printf("\nDopo la modifica di A:\n");
	printf("A = %d \n", A);
	printf("B = %d \n", B);
	printf("*ptr = %d \n", *ptr);

	*ptr = 17;
	printf("\nDopo la modifica di *ptr:\n");
	printf("A = %d \n", A);
	printf("B = %d \n", B);
	printf("*ptr = %d \n", *ptr);

    printf("\n\n");
	system("pause");
	return 0;
}

