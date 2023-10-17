/*
Siano dati DUE VETTORI di INTERI di lunghezza DIFFERENTE i cui valori sono INSERITI da tastiera.
Scrivere un programma C che generi un TERZO VETTORE contenente l'INTERSEZIONE tra i due vettori di input.
Se un ELEMENTO è COMUNE ai due vettori e PRESENTE PIU' VOLTE in un vettore farlo comparire anche nel vettore risultato.

Implementare la variante in cui le RIPETIZIONI NON SONO PRESENTI nel risultato.

Implementare inoltre anche l'INSERIMENTO RANDOM dei VALORI nei vettori.
*/

//THIS PROGRAM IS DEPRECATED. PLEASE DON'T EVEN BOTHER CHANGING IT, YOU'D JUST WASTE YOUR TIME

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#define MAX_INDEX 500
//#define MAX_RAND  51      THIS IS JUST SOME LEGACY
//#define MIN_RAND  20      STUFF PLEASE IGNORE 

int main()
{
    //Array index of an element, chosen by user
    int indexA1 = 0;

    //Repeats until user inputs a valid number
    while(1)
    {
        //Asks the user how many numbers he wants
        printf("Choose how many numbers you want to insert in the first array (max %d):\n", MAX_INDEX);
        //Gets user input
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

    //Dealing with FIRST ARRAY
    while(1)
    {
        printf("Do you want to choose the numbers? y\\n If not, I'll generate them randomly! \n");
        char answer01;

        //If only one char inserted
        if(scanf("%c", &answer01) == 1)
        {   
            //Clears keyboard cache
            fflush(stdin);

            //User chose to generate random numbers to fill array
            if(answer01=='n')
            {
                while(1)
                {
                    //Declaring variables for range extremes
                    int MIN_RAND=0;
                    int MAX_RAND=0;

                    printf("Type in the number range! min-max\n");

                    //If exactly two values are input and if they are legal
                    if(scanf("%d-%d", &MIN_RAND, &MAX_RAND)==2 && MIN_RAND<=MAX_RAND)
                    {
                        //Clears keyboard cache
                        fflush(stdin);

                        //Generate random numbers in that range filling the entire array
                        for(int i=0; i<indexA1; i++)
                        {
                            array1[i]= MIN_RAND + (rand() + time(NULL)) % (MAX_RAND+1-MIN_RAND);
                        }

                        //Get out of the inner while loop
                        break;

                    }
                    
                    //If input is NOT valid, repeat this value-getting loop
                    else
                    {
                        printf("invalid input\n");
                        //Clears keyboard cache
                        fflush(stdin);
                    }
                }

                //Get out of the outer while loop
                break;
            }

            //User chose to input values himself
            else if(answer01=='y')
            {
                //Filling the array with user-chosen values
                for(int i=0; i<indexA1; i++)
                {
                    //Declaring temporary variable (as NULL value) to fill array index
                    int val='\0';

                    do
                    {
                        //Asks user to input n-th number in the list
                        printf("Type the number of the first array in the %d index:",i);
                        //Gets user input
                        if(scanf("%d", &val)==1)
                        {
                            //Clears keyboard cache
                            fflush(stdin);
                            //Assigns user input to n-th place in the array (n+1 tbh, but it sounds worse so we're gonna keep it that way)
                            array1[i]=val;

                            //Get out of the do-while loop
                            break;
                        }

                        else
                        {
                            printf("It must be a number\n");
                            //Clears keyboard cache
                            fflush(stdin);
                        }
                    }
                    //Repeats until all values are correctly inserted
                    while(1);
                }
            
                //Get out of the outer while loop
                break;
            }

            //User pressed any other key
            else
            {
                //Clears keyboard buffer
                fflush(stdin);
                printf("invalid input\n");
            }
        }

        //If more than one char is typed in
        else
        {
            printf("invalid input");
            //Clears keyboard buffer
            fflush(stdin);
        }

    }

    //Prints first array...
    printf("\nFirst array:\n");
    //...using a for loop
    for(int i=0; i<indexA1; i++)
    {
        printf("%d\n",array1[i]);
    }

    //Dealing with SECOND ARRAY

	//Array index of an element, input by user
    int indexA2 = 0;

    //Repeats until user inputs a valid number
    while(1)
    {
        //Asks the user how many numbers he wants
        printf("Choose how many numbers you want to insert in the second array (max %d):\n",MAX_INDEX);
        //Gets user input
        scanf("%d",&indexA2);
        //Clears keyboard buffer
        fflush(stdin);
        //When input is a number in a legal range,get out of the loop
        if(indexA2<=MAX_INDEX && indexA2>0)
            break;
        //Else, print an error message and repeat the loop
        printf("ERROR: The number must be <= %d\n", MAX_INDEX);
    }

    //Creating array of user-chosen size
    int array2[indexA2+1];

    //Filling second array
    while(1)
    {
        printf("Do you want to choose the numbers for the second array? y\\n If not, I'll generate them randomly! \n");
        char answer03;

            //User input only one character
            if(scanf("%c", &answer03) == 1)
            {
                fflush(stdin);
               

                //User chose the random way
                if(answer03=='n')
                {
                    
                    //Filling the array with random numbers
                    while(1)
                    {
                        int MIN_RAND=0;
                        int MAX_RAND=0;

                            printf("Type in the number range! min-max\n");
                            //If range is legal
                            if(scanf("%d-%d", &MIN_RAND, &MAX_RAND)==2 && MIN_RAND<=MAX_RAND)
                            {
                                fflush(stdin);

                                for(int i=0; i<indexA1; i++)
                                {
                                    array2[i]= MIN_RAND + (rand() + time(NULL)) % (MAX_RAND+1-MIN_RAND);
                                }

                                break;
                            }
                            //If range is illegal
                            else
                            {
                                printf("invalid input\n");
                                fflush(stdin);
                            }

                    }
                //Get out of the loop            
                break;
            }

            //User chose to type in values himself
            else if(answer03=='y')
            {
                //Filling the array
                for(int i=0; i<indexA2; i++)
                {

                    //Declaring temporary variable to fill index
                    int val='\0';
                    do
                    {
                        //Asks user for
                        printf("Type the number of the first array in the %d index:",i);
                        //Gets user input
                        //If input is legal
                        if(scanf("%d", &val)==1)
                        {
                            fflush(stdin);

                            array2[i]=val;
                            break;
                        }
                        //If input is illegal
                        else
                        {
                            printf("It must be a number\n");
                            fflush(stdin);
                        }
                    }
                    while(1);
                }
                //Get out of the loop
                break;
            }

            //If user chose any other letter
            else
            {
                fflush(stdin);
                printf("invalid input\n");
            }
        }
        //If user typed in more than one char
        else
        {
            printf("invalid input");
            fflush(stdin);
        }

    }

    //Printing second array
    printf("\nSecond array:\n");
    for(int i=0;i<indexA1;i++)
    {
        printf("%d\n",array2[i]);
    }

    //Gets user input
    //Asks user if he wants to display duplicate results in the merged array
    while (1)
    {
        printf("Do you want to include duplicate results? y\\n\n");
        char answer02;

        if(scanf("%c", &answer02) == 1)
        {   
            fflush(stdin);
            //Duplicates are displayed only once
            if(answer02=='n')
            {
                //Removing duplicates from first array
                for(int i=0; i<indexA1; i++)
                {
                    for(int j=i+1; j<indexA1; j++)
                    {
                        //If any duplicate found
                        if(array1[i] == array1[j])
                        {
                            //Delete current duplicate element
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




                //Removing duplicates from second array
                for(int i=0; i<indexA2; i++)
                {
                    for(int j=i+1; j<indexA2; j++)
                    {
                        //If any duplicate found
                        if(array2[i] == array2[j])
                        {
                            //Delete the current duplicate element
                            for(int k=j; k<indexA2; k++)
                            {
                                array2[k] = array2[k + 1];
                            }

                            //Decrement size after removing duplicate element
                            indexA2--;

                            //If shifting of elements occur then don't increment j
                            j--;
                        }
                    }
                }

                break;
            }

            else if(answer02=='y'){                                 //To avoid array 3 moltiplication results cleans the first array
                 for(int i=0; i<indexA1; i++)
                {
                    for(int j=i+1; j<indexA1; j++)
                    {
                        //If any duplicate found
                        if(array1[i] == array1[j])
                        {
                            //Delete the current duplicate element
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







                    break;}
            else
            {
            fflush(stdin);
            printf("invalid input\n");
            }
        }

        else {printf("invalid input\n");
        fflush(stdin);}
    }


    printf("\n\n\n\n");
/*
    printf("\nFirst array:\n");
	for(int i=0; i<indexA1; i++)
    {
        printf("%d\n",array1[i]);
    }

    printf("\n\n\n\n");

    printf("\nSecond array:\n");
    for(int i=0; i<indexA2; i++)
    {
        printf("%d\n",array2[i]);
    }
*/


    printf("\n\n\n\n");

    int array3[MAX_INDEX];
    int indexA3 = 0;
    int arrayMax = 0;

    if (indexA1 > indexA2)
    {
        for (int i = 0; i < indexA1; i++)
        {
            int temp = array1[i];
            for (int i2 = 0; i2 < indexA2; i2++)
            {
                if (temp == array2[i2])
                {
                    array3[indexA3] = temp;
                    indexA3++;
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < indexA2; i++)
        {
            int temp = array2[i];
            for (int i2 = 0; i2 < indexA1; i2++)
            {
                if (temp == array1[i2])
                {
                    array3[indexA3] = temp;
                    indexA3++;
                }
            }
        }
    }


    printf("\nIntersected array:\n");
    for (int i = 0; i < indexA3; i++)
    {
    printf("%d\n", array3[i]);
    }
    fflush(stdin);
    getchar();
    return 0;
}
