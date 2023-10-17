#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{

    float valF;
    int valI;
    char str[20];

    strcpy(str, "98.993489");
    valF = atof(str);
    printf("String value = %s, Float value = %f\n", str, valF);

    valI = atoi(str);
    printf("String value = %s, Int value = %d\n", str, valI);

    strcpy(str, "98");
    valI = atoi(str);
    printf("String value = %s, Int value = %d\n", str, valI);

    printf("\n\n");
    system("pause");
    return(0);
}
