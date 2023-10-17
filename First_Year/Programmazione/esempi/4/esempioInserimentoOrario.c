#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i1, i2;
	char c1;

	puts("Inserire un orario in formato hh:mm:");
	scanf("%2d%c%2d", &i1, &c1, &i2);
    fflush(stdin);

	printf("l\'orario inserito e\': %02d:%02d.\n", i1, i2);

	return 0;
}

