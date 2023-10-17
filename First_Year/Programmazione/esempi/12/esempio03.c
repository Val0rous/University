 #include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main()
{
	char ch;
	int x = 0;

    printf("\n\nScrivi una frase (per terminare 'CTRL+Z poi ENTER'):\n");
	while ((ch=getch())!=EOF && x<MAX){
        putchar(ch);
        x++;
    }

    printf("\n\n");
    system("pause");
    return 0;
}
