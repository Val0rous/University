#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main()
{
	char ch, buffer[MAX+1];
	int x = 0;

    printf("\n\nScrivi una frase (per terminare 'CTRL+Z poi ENTER'):\n");
	while ((ch=getchar())!=EOF && x<MAX){
        buffer[x++] = ch;
    }
    buffer[x] = '\0'; //carattere di fine stringa
    printf("%s\n", buffer);

    printf("\n\n");
    system("pause");
    return 0;
}
