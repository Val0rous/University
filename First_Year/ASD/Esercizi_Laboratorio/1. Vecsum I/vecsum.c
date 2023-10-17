/****************************************************************************
 *
 * vecsum.c -- maximum (sub)vector sum
 *
 * Given an array with n>0 elements, find the nonempty subarray whose
 * sum is maximal. This program implements the brute-force O(n^3)
 * algorithm.
 *
 * The array length n is passed on the command line. No error checking
 * is done.
 *
 * Compile with:
 *
 * gcc -std=c99 -Wall -Wpedantic vecsum.c -o vecsum
 *
 * Execute with:
 *
 * ./vecsum 1000
 *
 * (C) 2021 Moreno Marzolla (http://www.moreno.marzolla.name/)
 * Distributed under the CC-zero 1.0 license
 * https://creativecommons.org/publicdomain/zero/1.0/ 
 *
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Takes input from command line
int main(int argc, char *argv[])
{
    //Only accepts 2 arguments from command line
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <array length>\n", argv[0]);
        return EXIT_FAILURE;
    }

    //argv[0] is program name, innit? Then, argv[1] is the array length passed from command line
    const int n = atoi(argv[1]);
    //Dynamically allocated array
    int *v = (int *)malloc(n * sizeof(*v));
    int val = 100;
    // Fill array v[] deterministically (guess it hasn't been initialized beforehand lol)
    for (int i = 0; i < n; i++)
    {
        v[i] = val;
        val += 17;
        if (val > 100)
            val -= 200;
    }

    // Compute the maximum sum across all nonempty subvectors
    //starts measuring time
    const time_t start_t = clock();
    int smax = v[0];
    //for each array element
    for (int i = 0; i < n; i++)
    {
        //for each other element on the right of i
        for (int j = i; j < n; j++)
        {
            int s = 0;
            //elements between i and j - [i,j]
            for (int k = i; k <= j; k++)
            {
                //sum of all elements
                s += v[k];
            }
            //update smax when needed
            if (s > smax)
                smax = s;
        }
    }

    //end of time measurement
    const time_t end_t = clock();
    //prints max sum
    printf("Max sum = %d\n", smax);
    //prints elapsed time
    const double elapsed = (end_t - start_t) / (double)CLOCKS_PER_SEC;
    printf("Elapsed time: %f sec\n", elapsed);

    //bye bye block of memory
    free(v);
    system("pause");
    return EXIT_SUCCESS;
}
