#include <stdio.h>

int main()
{
    int x, a, b;

    a = 5;
    b = 3;
    x = 0;

    printf("| It: 01 | a = %04d | b = %04d | x = %04d |\n", a, b, x);
    x = (a++, b++); // a=6 b=4 x=3
    printf("| It: 02 | a = %04d | b = %04d | x = %04d |\n", a, b, x);
    x = a++, b++;   // a=7 b=5 x=6 ATTENZIONE: qui non ci sono le parentesi quindi x=a.
    printf("| It: 03 | a = %04d | b = %04d | x = %04d |\n", a, b, x);
    x = (b++, a++); // a=8 b=6 x=7
    printf("| It: 03 | a = %04d | b = %04d | x = %04d |\n", a, b, x);

    return 0;
}
