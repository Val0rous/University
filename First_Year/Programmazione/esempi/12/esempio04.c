#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[101];

    puts("scrivere il testo e premere INVIO:");
    gets(input);
    printf("E\' stato inserito: %s\n", input);

    printf("\n\n");
    system("pause");
    return 0;
}
