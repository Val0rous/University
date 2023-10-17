#include <stdio.h>

int fattoriale(int num);

int main()
{
    int x, fat;
    scanf("%d",&x);
    fflush(stdin);
    fat = fattoriale(x);
    printf("fattoriale: %d", fat);
    return 0;
}

int fattoriale(int num)
{
    int ris;
    if (num == 0)
        return 1;

    ris = num * fattoriale(num - 1);
    return ris;
}
