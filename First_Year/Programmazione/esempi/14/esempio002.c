#include <stdio.h>
#include <stdlib.h>

void per_valore(int a, int b, int c);
void per_riferimento(int *a, int *b, int *c);

int main()
{
	int x, y, z;
	int *p_x, *p_y, *p_z;

	x = 2; y = 4; z = 6;
	printf("\nValori iniziali, x= %d, y = %d, z = %d.\n",x,y,z);

	x = 2; y = 4; z = 6;
	per_valore(x,y,z);
	printf("\nIn caso di chiamata di per_valore, x= %d, y = %d, z = %d.\n",x,y,z);

	x = 2; y = 4; z = 6;
    per_riferimento(&x, &y, &z);
	printf("\nIn caso di chiamata di per_riferimento (passando valori nella forma &x), x= %d, y = %d, z = %d.\n",x,y,z);

	x = 2; y = 4; z = 6;
	p_x = &x; p_y = &y; p_z = &z;
    per_riferimento(p_x, p_y, p_z);
	printf("\nIn caso di chiamata di per_riferimento (passando valori nella forma p_x), x= %d, y = %d, z = %d.\n",x,y,z);

	system("pause");
	return 0;
}


void per_valore(int a, int b, int c)
{
	a = 0;
	b = 0;
	c = 0;
}


void per_riferimento(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}
