#include <stdio.h>
#include <stdlib.h>

unsigned char x;

int main()
{
	for (x = 128; x <= 254; x++)
	{
		printf("Codice ASCII %3d corrisponde al carattere %c \n", x, x);
	}

    printf("\n\n");
    system("pause");
    return(0);
}
