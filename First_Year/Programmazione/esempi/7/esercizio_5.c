#include <stdio.h>

int main()
{
    int numero, primo;
    int i;

    printf("Numeri primi!\n\n");

	for (numero = 1; numero <= 100; numero++)
	{
		if (numero < 3)
			printf("%d\n",numero);
		else
		{
			if ((numero % 2) == 1)
			{
			    primo = 1;
				for (i = 3; i < numero; i++)
				{
					if ((numero % i) == 0)
					{
					    primo = 0;
              			break;
					}
				}
				if (primo == 1)
				    printf("%d\n",numero);
			}
		}
	}

    printf("\n\n");
    system("pause");
    return 0;
}


