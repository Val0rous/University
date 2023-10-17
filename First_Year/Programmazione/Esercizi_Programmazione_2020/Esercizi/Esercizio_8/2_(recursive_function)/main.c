/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/12/04
Realizzare un programma che risolva tramite una funzione ricorsiva (FATTORIALE)
un qualche problema scelto dagli studenti;
il programma deve stampare le variabili locali e i parametri
di ogni chiamata alla funzione ricorsiva.
In particolare, per ogni chiamata ricorsiva,
deve visualizzare l’output su una riga separata e aggiungere un livello di rientro.
Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
L’obiettivo è quello di progettare e implementare un formato dell’output
che aiuti l'utente a comprendere il meccanismo della ricorsione.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FACT 13

long int factorial(int number, int request)
{
    long int result = 1; //create variable

    if (number == 0 || number == 1) //define small problem, we know the solution
    {

        for (int i = 0; i < request-1; ++i) //indent accordingly
        {
            printf("\t");
        }
        printf("We know that factorial of 1 is 1\n");
        return 1;
    }

    else
    {

        //To tabulate the result in such a way that it allows us to see the recursive mechanism in action
        for (int i = 0; i < request - number; ++i)
        {
            printf("\t");
        }
        printf("Call # %d, %d*fact(%d) \n", request - number + 1, number, number - 1);

        //calculate result using previous factorial
        result = number * factorial(number - 1, request);

        //print result
        for (int i = 0; i < request - number; ++i)
        {
            printf("\t");
        }
        printf("result # %d, %d*%d = %d\n", request - number + 1, number, result / number, result);
    }
    return result;//return to the previous call the result
}

int main()
{
    int number;   //request and store the number of the factorial
    while (1)
    {
        printf("Type a number and I'll calculate its factorial! (max %d)> ",MAX_FACT-1);
        scanf("%d", &number);
        fflush(stdin);

        if (number < MAX_FACT && number >= 0)
            break;
        else if (number < 0)
        {
            printf("Factorial is not defined for negative numbers!\a\nPlease try again");
            continue;
        }
        printf("OMG my bits can't handle it: the result would be too large!!!\a\nPlease try again\n\n");
    }

    //start the recursive function with the stored number (two parameters to keep track of the target for indentation purposes)
    long int fact = factorial(number, number);
    //print result
    printf("\nThe factorial of your number is %ld", fact);

    printf("\nPress any key to continue...");

    getchar();

    return 0;
}
