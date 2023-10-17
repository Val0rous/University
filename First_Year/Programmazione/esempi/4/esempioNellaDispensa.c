#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i1, i2;
	long l1;
	double d1;

	char buf1[80], buf2[80];

	/*uso del modificatore l per interi long e double*/

	puts("Inserire un intero e un numero in virgola mobile.");
	scanf("%ld %lf", &l1, &d1);
	fflush(stdin);
	printf("Hai inserito %ld e %lf.\n", l1, d1);
	/* La stringa di formato di scanf() ha utilizzato il modificatore l per memorizzare l input di un tipo long e un tipo double */


	/*Utilizza la dimensione del campo per suddividere l段nput*/

	puts("inserire un numero di 5 cifre (ad esempio 54321)");
	scanf("%2d%3d", &i1, &i2);
	fflush(stdin);
	/* Si noti che l段ndicatore dell誕mpiezza di campo nella stringa di formato di scanf() suddivide l段nput in due valori */

	puts("inserire il nome e il cognome separati da uno spazio. ");
	scanf("%[^ ]%s", buf1, buf2);
	fflush(stdin);

	printf("\n il nome e\': %s\n", buf1);
	printf("\n il cognome e\': %s\n", buf2);
	/* Si noti che [^ ] nella stringa scanf(), escludendo il carattere  Spazio, ha causato la suddivisione dell段nput */

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}

