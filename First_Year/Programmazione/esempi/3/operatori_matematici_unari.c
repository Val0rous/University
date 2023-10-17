#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;

	a = 7;
	b = 7;
	a = 1;
	a = a++ + (++a);
	printf("%d  \n",a);
	printf("%d  %d\n",a--,--b);
	printf("%d  %d\n",a--,--b);
	printf("%d  %d\n",a--,--b);
	printf("%d  %d\n",a--,--b);
	printf("%d  %d\n",a--,--b);
    system("pause");
	return 0;
}


