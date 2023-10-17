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
void addToArr(int Perm[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Perm[counter] = Perm[BASE + i];
        counter++;
    }
}

// Generating permutation using Heap Algorithm
void heapPermutation(int Perm[], int size, int N)  //size == n (at the beginning)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
        addToArr(Perm, N);
        return;
    }

    heapPermutation(Perm, size - 1, N);

    for (int i = 0; i < size; i++)
    {
        //* DISPARI
        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
        {
            //*swap(a[0], a[size - 1]);

            int temp = Perm[BASE + 0];
            Perm[BASE + 0] = Perm[BASE + size - 1];
            Perm[BASE + size - 1] = temp;
        }

        //* PARI
        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
        {
            //*swap(a[i], a[size - 1]);
            int temp = Perm[BASE + i];
            Perm[BASE + i] = Perm[BASE + size - 1];
            Perm[BASE + size - 1] = temp;
        }

        heapPermutation(Perm, size - 1, N);
    }
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
    
    //* mette i primi N numeri nel vettore Perm, dopo tutte le possibili permutazioni
    //inizializzo array con N numeri originali nelle ultime N posizioni
    for (int i = 0; i < N; i++)
    {
        Perm[BASE + i] = i + 1;
    }

    //* algoritmo di Heap per calcolo permutazioni
    heapPermutation(Perm, N, N);
    /*
    int a[] = {1, 2, 3};
    int n = sizeof a / sizeof a[0];
    heapPermutation(a, n, n);
    */


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