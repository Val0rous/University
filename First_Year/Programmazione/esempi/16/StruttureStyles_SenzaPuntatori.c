#include <stdio.h>
#include <stdlib.h>


struct StyleA{
	int num1;
	char string1;
};


struct{
	int num1;
	char string1;
} StyleB_istanza1;


typedef struct StyleC{
	int num1;
	char string1;
}StyleC;



int main()
{

	struct StyleA StyleA_istanza1;
	StyleC StyleC_istanza1;


	printf("\nInserisci un numero per StyleA_istanza1:    ");
	scanf("%d",&StyleA_istanza1.num1);
	fflush(stdin);

	printf("\nInserisci un carattere per StyleA_istanza1: ");
	scanf("%c",&StyleA_istanza1.string1);
    fflush(stdin);

	printf("\nInserisci un numero per StyleB_istanza1:    ");
	scanf("%d",&StyleB_istanza1.num1);
	fflush(stdin);

	printf("\nInserisci un carattere per StyleB_istanza1: ");
	scanf("%c",&StyleB_istanza1.string1);
    fflush(stdin);

    printf("\nInserisci un numero per StyleC_istanza1:    ");
	scanf("%d",&StyleC_istanza1.num1);
	fflush(stdin);

	printf("\nInserisci un carattere per StyleC_istanza1: ");
	scanf("%c",&StyleC_istanza1.string1);
    fflush(stdin);


	printf("I numeri salvati sono:    %d (StyleA)\t %d (StyleB)\t %d (StyleC).\n", StyleA_istanza1.num1, StyleB_istanza1.num1, StyleC_istanza1.num1);
    printf("I caratteri salvati sono: %c (StyleA)\t %c (StyleB)\t %c (StyleC).\n", StyleA_istanza1.string1, StyleB_istanza1.string1, StyleC_istanza1.string1);

	return 0;
}

