#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char str[50];
    int len;

    strcpy(str, "This is a test!");

    len = strlen(str);
    printf("Length of |%s| is |%d|\n", str, len);

    printf("\n\n");
    system("pause");
    return(0);
}
