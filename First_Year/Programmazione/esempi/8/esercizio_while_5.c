#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero = 1, primo;
	int i, verifica;

	printf("Numeri primi!\n\n");

	while (numero <= 100)
	{
		if (numero < 3)
			printf("%d\n", numero);
		else
		{
			if ((numero % 2) == 1)
			{
				primo = 1;
				i = 3;
				while (i < numero)
				{
					if ((numero % i) == 0)
					{
						primo = 0;
						break;
					}
					i++;
				}
				if (primo == 1)
					printf("%d\n", numero);
			}
		}
		numero++;
	}

	printf("\n\n");
	system("pause");
	return 0;
}
