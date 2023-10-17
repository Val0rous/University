#include <stdlib.h>
#include <stdio.h>

int main(int argn, char *argv[])
{
	printf("%d argomenti ricevuti\n", argn);
	printf("Nome del programma: \n\t%s\n", argv[0]);
	if (argn>1){
        for (int i =1; i<argn; i++){
            printf("Argomento %d: %s\n", i, argv[i]);
        }
	} else {
        return 1;
	}

	printf("\n\n");
	system("pause");
    return 0;
}


