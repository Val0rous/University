#include <stdio.h>
#include <stdlib.h>

int main()
{

	char buf1[80], buf2[80];

	puts("inserire il nome e i vari cognomi separati da uno spazio. ");
	scanf("%[^ ] %[^\n]", buf1, buf2);
	//scanf("%[^ ] %[^\n]s", buf1, buf2); //In questo modo lo spazio bianco prima del primo cognome viene eliminato di default.
	fflush(stdin);

	printf("\n il nome    e\': %s\n", buf1);
	printf("\n il cognome e\': %s\n", buf2);

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

