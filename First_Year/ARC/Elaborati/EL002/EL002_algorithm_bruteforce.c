// C program to print all permutations using
// Heap's algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//NOW, IT WORKS

//TODO: translate this program to assembly code - on VS community

//* making these guys global just for the C blueprint
int N = 4;
int Num;
int counter = 0;        //* this is gonna be ECX
int BASE;

int factorial(int N)
{
    //* caso base
    if (N == 1)
        return 1;

    //* chiamata ricorsiva
    return (N * factorial(N - 1));
}

// Prints the array
//* this is gonna put elements in the array
void addToArr(int Perm[], int N, int dividend)
{
    counter += N;
    int remainder = 0;
    for (int i = 0; i < N; i++)
    {
        remainder = dividend % 10;
        dividend /= 10;

        counter--;
        Perm[counter] = remainder;
        ////counter--;
    }
    counter += N;
}

// Driver code
int main()
{
    clock_t begin = clock();
    
    //* Variabili
    //int N = 4;      // numero di interi (provare con valori <=6)
    int Perm[4326]; // array permutazioni: la dimensione è sufficiente per N<=6
    //int Num;        // Alla fine deve contenere il numero di permutazioni generate
    //* calcolo fattoriale di N (da salvare in Num)
    int Num = factorial(N);

    //* EAX = N * Num = BASE (moltiplicato per 4 perchè siamo in assembly e usiamo gli INT)
    BASE = N * Num;

    //! ********************************************

    //starts adding elements from counter
    counter = N;

    //* mette i primi N numeri all'inizio del vettore Perm
    //inizializzo array con N numeri di partenza nelle prime N posizioni
    for (int i = 0; i < N; i++)
    {
        Perm[i] = i + 1;
    }

    //runner is bruteforcing variable
    int runner = 0;
    int mul = 1;

    //inizializza contatore (123456)
    for (int i = N; i > 0; i--)
    {
        runner = runner + (i * mul);
        mul *= 10;
    }

    //max is max number of list (654321)
    int max = 0;
    for (int i = N; i > 0; i--)
    {
        mul /= 10;
        max = max + (i * mul);
    }

    //? da qui, good luck!

    //runs through elements and eventually adds them to array
    for (runner = runner + 1; runner <= max; runner++)
    {
        //initialize last elements of array, after BASE, to 0 (digit counters)
        for (int i = 0; i < N; i++)
        {
            Perm[BASE + i] = 0;
        }

        int dividend = runner;
        int remainder = 0;
        ////int div = 10;
        //for each digit
        for (int i = 0; i < N; i++)
        {
            remainder = dividend % 10;
            dividend /= 10;
            //div *= 10;
            //check if all N digits are the ones we want
            for (int i = 0; i < N; i++)
            {
                //if they're right
                if (remainder==(i+1))
                {
                    //increment counter
                    (Perm[BASE + i])++;
                    break;
                }
            }
        }
        //all elements need to be equal to 1 in order to add to array
        int product = 1;
        for (int i = 0; i < N; i++)
        {
            product *= Perm[BASE + i];
        }
        //adds correct number to array
        if (product == 1)
        {
            addToArr(Perm, N, runner);
        } 
    }

        //! ********************************************
        //* Stampa su video
        //i : n° di permutazioni (Num)	--> da calcolare con fattoriale o con tabella già determinata
        //j : n° di cifre per ogni permutazione (N)
        //k : indice per scorrere l'array (k = N*i + j)
        int i, j, k;
    printf("Permutazioni dei primi %d numeri naturali\n", N);
    //printf("%d", Num);
    for (i = k = 0; i < Num; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%3d", Perm[k++]);
        }
        printf("\n");
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%lf", time_spent);

    return 0;
}