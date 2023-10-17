/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/10/23

Scrivere un programma C che LEGGA N numeri INTERI da tastiera e li memorizzi in un VETTORE.
Il programma deve generare un SECONDO VETTORE compattando i numeri contenuti nel primo vettore.

In particolare:
    ogni numero che compare RIPETUTO nel PRIMO vettore, deve comparire UNA SOLA VOLTA nel SECONDO vettore
    ogni numero uguale a ZERO presente nel primo vettore NON DEVE COMPARIRE nel SECONDO vettore

Prevedere anche la versione in cui i NUMERI sono GENERATI RANDOM.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#define MAX_INDEX 100                //define the maximum size of the array

int main()
{
    //Array index of an element, input by user
    int indexA1 = 0;

    //Repeats until user inputs a valid number
    while(1)
    {
        //Asks the user how many numbers he wants
        printf("Choose how many numbers do you want to insert in the array (max %d):\n", MAX_INDEX);
        //Gets user input
        fflush(stdin);
        scanf("%d", &indexA1);
        //Clears keyboard buffer
        fflush(stdin);
        //When input is a number in a legal range,get out of the loop
        if(indexA1<=MAX_INDEX && indexA1>0)
            break;
        //Else, print an error message and repeat the loop
        printf("ERROR: The number must be <= %d\n", MAX_INDEX);
    }

    //Creating array of user chosen size
    int array1[indexA1+1];

    //Filling the array
    while(1)
    {
        printf("Do you want to choose the numbers? y\\n If not, I'll generate them randomly! \n", MAX_INDEX);
        char answer01;
        fflush(stdin);
        //If only one char is typed in
        if(scanf("%c", &answer01) == 1)
            {
                //User wants to generate numbers randomly
                if(answer01=='n')
                {
                    while(1)
                    {                                           //Generating random numbers to fill array
                        int MIN_RAND=0;
                        int MAX_RAND=0;
                        printf("Type the range! min-max\n");
                        fflush(stdin);
                        //If range is valid
                        if(scanf("%d-%d", &MIN_RAND, &MAX_RAND)==2 && MIN_RAND<=MAX_RAND)
                        {
                            fflush(stdin);
                            for(int i=0; i<indexA1; i++)
                            {
                                array1[i]= MIN_RAND + (rand()+time(NULL))%(MAX_RAND+1-MIN_RAND);
                            }
                            //Get out of the loop
                            break;
                        }
                        printf("invalid input\n");

                    }
                    //Get out of the loop
                    break;
                }
                //User wants to type in numbers himself
                else if(answer01=='y')
                {
                    //Filling the array
                    for(int i=0; i<indexA1; i++)
                    {

                        //Declaring temporary variable to fill index

                        do
                        {  int val='\0';
                            //Asks user for
                            printf("Type the number of the array in the %d index:",i);
                            //Gets user input
                            //If only one value is typed in
                            fflush(stdin);
                            if(scanf("%d", &val)==1)
                            {
                                fflush(stdin);
                                array1[i]=val;
                                break;
                            }                                           //closing each loop evaluating invalid inputs

                            else printf("It must be a number\n");
                        }
                        while(1);
                    }
                break;
                }
                //If any other input
                else
                {
                    fflush(stdin);
                    printf("invalid input\n");
                }
            }

        //If more than one character is typed in
        else
        {
            fflush(stdin);
            printf("invalid input\n");
        }
    }

                                        //Prints original array
    printf("\nOriginal array:\n");
    for(int i=0; i<indexA1; i++)
    {
        printf("%d\n",array1[i]);
    }



                            //removing duplicates

    for(int i=0; i<indexA1; i++)                  //check each value
    {
        for(int j=i+1; j<indexA1; j++)  //compare to all the orhers
        {
                                                //If any duplicate found
            if(array1[i] == array1[j])
            {
                                                //Delete the current duplicate element shifting evrithing left
                for(int k=j; k<indexA1; k++)
                {
                    array1[k] = array1[k + 1];
                }

                                                    //Decrement size after removing duplicate element
                indexA1--;

                                            //If shifting of elements occur then don't increment j
                j--;
            }
        }
    }

    //removing zeros
    for(int j=0; j<indexA1; j++)
    {                  //check each value
        if(array1[j]==0)
        {
            for(int k=j; k<indexA1; k++)            //if zero, shift everithing left
            {
                array1[k] = array1[k + 1];
            }
            indexA1--;          //Decrement size after removing duplicate element
            j--;                //If shifting of elements occur then don't increment j
        }
    }


    //Prints cleaned array (with neither duplicates nor zeros)
    printf("\nCleaned array:\n");
    for(int i=0; i<indexA1; i++)
    {
        printf("%d\n",array1[i]);
    }

    getchar();
    return 0;
}
