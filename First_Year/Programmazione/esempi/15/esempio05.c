#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

int main()
{
	char ch;
    char buffer[MAX+1];
	int x;

	/* getchar, putchar */
	printf("\n\n Step1 - Scrivi una frase (per terminare CTRL+Z poi ENTER):\n");
	while ((ch=getchar())!=EOF)
    {
        if (ch=='p')
        {
            printf("\n\n Hai inserito una p!\n\n");
        }
        putchar(ch);
    }

    /* getchar, printf */
    printf("\n\n Step2 - Scrivi una frase (per terminare CTRL+Z poi ENTER):\n");
    x = 0;
    while (((ch=getchar())!=EOF) && x<MAX)
    {
        if (ch=='p')
        {
            printf("\n\n Hai inserito una p!\n\n");
        }
        buffer[x++] = ch;
    }
    buffer[x] = '\0';
    printf("%s\n",buffer);

    /* getch, putchar */
    printf("\n\n Step3 - Scrivi una frase (per terminare digitare %d caratteri):\n", MAX+1);
    x = 0;
    while (((ch=getch())!=EOF) && x<MAX)
    {
        if (ch=='p')
        {
            printf("\n\n Hai inserito una p!\n\n");
        }
        putchar(ch);
        x++;
    }

    /* getch, printf */
    printf("\n\n Step4 - Scrivi una frase (per terminare digitare %d caratteri):\n", MAX+1);
    x = 0;
    while (((ch=getch())!=EOF) && x<MAX)
    {
        if (ch=='p')
        {
            printf("\n\n Hai inserito una p!\n\n");
        }
        buffer[x++] = ch;
    }
    buffer[x] = '\0';
    printf("%s\n",buffer);


    printf("\n\n");
    system("pause");
    return 0;
}
