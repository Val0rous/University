#include <stdio.h>
#include <stdlib.h>

struct coord{
    int x;
    int y;
};

struct rettangolo{
    struct coord supsin;
    struct coord infdes;
};

struct rettangolo riq;

int main()
{
	int lung, larg, a, b, c, d;
	long area;

	printf("\nInserisci la coordinata x superiore sinistra: ");
	scanf("%d",&riq.supsin.x);
	fflush(stdin);

	printf("\nInserisci la coordinata y superiore sinistra: ");
	scanf("%d",&riq.supsin.y);
    fflush(stdin);

	printf("\nInserisci la coordinata x inferiore destra: ");
	scanf("%d",&riq.infdes.x);
    fflush(stdin);

	printf("\nInserisci la coordinata y inferiore destra: ");
	scanf("%d",&riq.infdes.y);
    fflush(stdin);

	/*calcola la lunghezza e la larghezza*/
	larg = abs(riq.infdes.x-riq.supsin.x);
	lung = abs(riq.infdes.y-riq.supsin.y);

	/*Calcola e visualizza l’area*/
	area = lung*larg;

	printf("\nL\'area e\': %d\n", area);

	return 0;
}


