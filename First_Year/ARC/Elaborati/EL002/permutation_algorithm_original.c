// C program to print all permutations using
// Heap's algorithm
#include <stdio.h>
#include <stdlib.h>

//! original Heap's Algorithm I've found on the internet. DO NOT TOUCH!

// Prints the array
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf(" ");
    }
    printf("\n");
}

// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n) //size == n (at the beginning)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
        printArr(a, n);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        heapPermutation(a, size - 1, n);

        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
        {
            //*swap(a[0], a[size - 1]);

            int temp = a[0];
            a[0] = a[size - 1];
            a[size - 1] = temp;
        }

        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
        {
            //*swap(a[i], a[size - 1]);
            int temp = a[i];
            a[i] = a[size - 1];
            a[size - 1] = temp;
        }
    }
}

// Driver code
int main()
{
    int a[] = {1, 2, 3, 4};
    int n = sizeof a / sizeof a[0];
    heapPermutation(a, n, n);
    return 0;
}