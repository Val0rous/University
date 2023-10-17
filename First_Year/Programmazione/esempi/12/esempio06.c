#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
	double x, y, z;

	x = 2;
	y = 9;
	printf("\n x = %.2lf; y = %.2lf\n\n", x, y);

    printf("\n function: exp(x)\n");
    z = exp(x);
    printf("\texp(%.2lf) -> %.2lf\n", x, z);

    printf("\n function: sqrt(y)\n");
    z = sqrt(y);
    printf("\tsqrt(%.2lf) -> %.2lf\n", y, z);

    printf("\n function: pow(y,x)\n");
    z = pow(y,x);
    printf("\tpow(%.2lf, %.2lf) -> %.2lf\n", y, x, z);

    printf("\n\n");
    system("pause");
    return 0;
}
