/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/11/11

Scrivere un programma C dove sono inizializzate una variabile di tipo
int,
una di tipo float,
una di tipo double,
una di tipo char,
ed un array di 5 interi (precisamente con i valori 10, 20, 30, 40, 50).
Inizializzare un puntatore per ciascuna di queste variabili.
Assegnare ad ogni variabile un valore tramite l'utilizzo della funzione scanf.
Visualizzare il valore di ogni variabile in due modi: prima tramite accesso diretto alla variabile e a seguito tramite l'utilizzo del suo puntatore (accesso indiretto).
Visualizzare la posizione in memoria della variabile tramite l'utilizzo diretto della variabile e tramite il suo puntatore.
Visualizzare la posizione in memoria del puntatore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   //Initializing variables
    int i = 0;
    float f = 0;
    double d = 0;
    char c = 0;
    int a[] = {10, 20, 30, 40, 50};

    //initializing pointer
    int *pI = &i;
    float *pF = &f;
    double *pD = &d;
    char *pC = &c;
    int *pA = a;

    //scanf int
    while (1)
    {
        printf("Type the int value:\n");
        fflush(stdin);
        int good = scanf("%d", pI); //flag value: if match is true, set value to 1
        if (good == 1)break;        //and exits
        printf("Invalid input, try again!\a\n");    //else invalid input, continue cycle
    }

    printf("Int is now equal to: %d\n", i);

    //scanf float
    while (1)                                           //same methods
    {
        printf("Type the Float value (use \'.\'):\n");
        fflush(stdin);
        int good = scanf("%f", &f);
        if (good == 1)
            break;
        printf("Invalid input, try again!\a\n");
    }
    printf("Float is now equal to: %f\n", *pF);

    //scanf double
    while (1)
    {
        printf("Type the Double value (use \'.\'):\n");
        fflush(stdin);
        int good = scanf("%lf", &d);
        if (good == 1)
            break;
        printf("Invalid input, try again!\a\n");
    }
    printf("Double is now equal to: %lf\n", d);

    //scanf char
    while (1)
    {
        printf("Type the Char value:\n");
        fflush(stdin);
        int good = scanf("%c", &c);
        if (good == 1)
            break;
        printf("Invalid input, try again!\a\n");
    }
    printf("Char is now equal to: \'%c\'\n", c);

    //scanf array
    printf("Do you want to change the values of the array? (y,n)\n");

    while (1)                   //get answer
    {
        char ch = getch();
        if (ch == 'y')                  //if yes
        {
            for (int i = 0; i < 5; i++) //for each value
            {

                while (1)               //change corresponding value
                {
                    printf("Type the array int value in %d position:\n", i);
                    fflush(stdin);
                    int good = scanf("%d", &a[i]);
                    if (good == 1)
                        break;
                    printf("Invalid input, try again!\a\n");
                }
                printf("the array int value in %d position is now equal to:%d\n", i, a[i]);
            }
            break;
        }

        if (ch == 'n')
            break;

        printf("Invalid input, try again!\a\n");
    }
    sleep(1);

    printf("\n\n");

    //visualizing for each type of variable direct,indirect access and pointer address'
    printf("Type\tdirect vl: \tnot direct vl:\tdirect ad:\tnot direct ad:\tad ptr:\n");
    printf("Int\t%d\t\t%d\t\t%x\t\t%x\t\t%x\n", i, *pI, &i, pI, &pI);
    printf("Float\t%f\t%f\t%x\t\t%x\t\t%x\n", f, *pF, &f, pF, &pF);
    printf("Double\t%lf\t%lf\t%x\t\t%x\t\t%x\n", d, *pD, &d, pD, &pD);
    printf("Char\t%c\t\t%c\t\t%x\t\t%x\t\t%x\n", c, *pC, &c, pC, &pC);
    printf("Arr int\t");

    //print array direct
    printf("{");
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
            printf("%d", a[i]);
        else
            printf("%d ", a[i]);
    }
    printf("}");
    //print array not direct
    printf("{");
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
            printf("%d", *(pA + i));
        else
            printf("%d ", *(pA + i));
    }
    printf("}");

    //print addresses
    printf("%x\t\t%x\t\t%x\n", a, pA, &pA);
    //wait for user input to close
    fflush(stdin);
    getchar();

    return 0;
}
