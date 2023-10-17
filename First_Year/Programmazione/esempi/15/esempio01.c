#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
    printf("\n\nScrivi una frase (per terminare 'CTRL+Z poi ENTER'):\n");
	while ((ch=getchar())!=EOF)    {
        putchar(ch);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
