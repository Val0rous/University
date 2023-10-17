#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/* Scrive un programma che richieda in ingresso una stringa e ogni volta che
e' digitata una e esegua l'esponenziale del primo numero da 0 a 9 che viene digitato a seguito */

int main()
{
	double x, z;
	int flag = 0;
	char ch, *p_ch;

	/* getchar, putchar */
	printf("\n\nStep1 - Scrivi una frase (per terminare CTRL+Z poi ENTER):\n");
	while ((ch=getchar())!=EOF)
    {
        if (ch=='e')
        {
            flag=1;
        }
        if (flag==1 && isdigit(ch))
        {
            //p_ch = &ch;
            x = atoi(&ch);
            z = exp(x);
            printf("\texp(%.2lf) -> %.2lf\n", x, z);
            flag = 0;
        }
    }

    printf("\n\n");
    system("pause");
    return 0;
}
