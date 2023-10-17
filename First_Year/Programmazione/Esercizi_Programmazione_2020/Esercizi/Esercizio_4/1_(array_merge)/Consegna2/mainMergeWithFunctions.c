/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/11/1

Siano dati DUE VETTORI di INTERI di lunghezza DIFFERENTE i cui valori sono INSERITI da tastiera.
Scrivere un programma C che generi un TERZO VETTORE contenente l'INTERSEZIONE tra i due vettori di input.
Se un ELEMENTO è COMUNE ai due vettori e PRESENTE PIU' VOLTE in un vettore farlo comparire anche nel vettore risultato.

Implementare la variante in cui le RIPETIZIONI NON SONO PRESENTI nel risultato.

Implementare inoltre anche l'INSERIMENTO RANDOM dei VALORI nei vettori.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#define MAX_INDEX 500
//#define MAX_RAND  51      PLEASE IGNORE
//#define MIN_RAND  20      THESE TWO LINES

//Filling array with random values
void fulfillWithRandom (int array[], int indexA)
{
    while(1)
    {
        int MIN_RAND=0;
        int MAX_RAND=0;

        printf("Type the range! min-max\n");
        //If only two values are typed in
        if(scanf("%d-%d", &MIN_RAND, &MAX_RAND)==2 && MIN_RAND<=MAX_RAND)
        {
            //Clear keyboard buffer
            fflush(stdin);
            //Generate random values for each array element
            for(int i=0; i<indexA; i++)
            {
                array[i]= MIN_RAND + (rand() + time(NULL)) % (MAX_RAND+1-MIN_RAND);
            }
            //Get out of the loop
            break;
        }
        //If more than two values are typed in
        else
        {
            printf("invalid input\n");
            //Clear keyboard cache
            fflush(stdin);
        }
    }
}

//Filling array with manually-input values
void fulfillManually (int array[],int indexA, char order[])
{
   for(int i=0; i<indexA; i++)
    {
        //Declaring temporary variable to fill index with NULL values
        int val='\0';

        do
        {
            //Asks user for:
            printf("Type the number of the %s array in the %d index:",order,i);
            //Gets user input
            //If only one value is typed in
            if(scanf("%d", &val)==1)
            {
                //Clear keyboard buffer
                fflush(stdin);
                //Assign input value to corresponding array element
                array[i]=val;
                //Get out of the loop
                break;
            }
            //If more than one value is typed in
            else
            {
                printf("It must be a number\n");
                //Clear keyboard buffer
                fflush(stdin);
            }
        }
        while(1);
    }
}

//Deletes duplicates
void deleteDuplicates (int array[],int *IindexA)
{   int indexA=*IindexA;
    for(int i=0; i<indexA; i++)
    {
        for(int j=i+1; j<indexA; j++)
        {
            //If any duplicate found
            if(array[i] == array[j])
            {
                //Delete current duplicate element
                for(int k=j; k<indexA; k++)
                {
                    //Basically, deletes an element and shifts all other elements one place back
                    array[k] = array[k + 1];
                }

                //Decrement size after removing duplicate element
                indexA--;

                //If shifting of elements occur then don't increment j
                j--;
            }
        }
    }
    *IindexA=indexA;
}

//Prints the entire array
void printArray (int array[],int indexA)
{
    for(int i=0; i<indexA; i++)
    {
        printf("%d\n", array[i]);
    }
}

int askIndex(char order[])
{
    //Asks for array length
    int indexA = 0;

    //Repeats until user inputs a valid number
    while(1)
    {
        //Asks the user how many numbers he wants
        printf("Choose how many numbers you want to insert in the %s array (max %d):\n", order, MAX_INDEX);
        //Gets user input
        scanf("%d", &indexA);
        //Clears keyboard buffer
        fflush(stdin);
        //When input is a number in a legal range, get out of the loop
        if(indexA<=MAX_INDEX && indexA>0)
            break;
        //Else, print an error message and repeat the loop
        printf("ERROR: The number must be <= %d\n", MAX_INDEX);
    }
    return indexA;
}

int main()
{
    //Array index of an element, input by user
    int indexA1 = askIndex("first");
    //Creating array of user chosen size
    int array1[indexA1+1];

    //Dealing with first array
    while(1)
    {
        printf("Do you want to choose the numbers? y\\n If not, I'll generate them randomly! \n");
        char answer01;

        //If only one character typed in
        if(scanf("%c", &answer01) == 1)
        {
            //Clears keyboard buffer (OK imma stop writing this every time)
            fflush(stdin);
            //Generating random numbers to fill array
            //User chose the random way
            if(answer01=='n')
            {
                fulfillWithRandom(array1,indexA1);
                //Get out of the loop
                break;
            }
            //User chose the manual way
            else if(answer01=='y')
            {
                //Filling the array
                fulfillManually (array1,indexA1, "first");
                //Get out of the loop
                break;
            }
            //If any other input
            else
            {
                fflush(stdin);
                printf("invalid input\n");
            }
        }
        //If more than one char typed in
        else
        {
            printf("invalid input");
            fflush(stdin);
        }

    }

    //Prints first array
    printf("\nFirst array:\n");
    printArray(array1, indexA1);
    int indexA2=0;
    while(1){
	//Array index of an element, input by user
    indexA2 = askIndex("second");
    if (indexA2!=indexA1)break;
    else printf("It can't be of the same lenght of the first array!\n");
    }
    //Creating array of user chosen size
    int array2[indexA2+1];

    //Dealing with second array
    while(1)
    {
        printf("Do you want to choose the numbers for the second array? y\\n If not, I'll generate them randomly! \n");
        char answer03;

        //If only one character typed in
        if(scanf("%c", &answer03) == 1)
        {
            fflush(stdin);
            //Generating random numbers to fill array
            //User chose the random way
            if(answer03=='n')
            {
                fulfillWithRandom(array2,indexA2);
                //Get out of the loop
                break;
            }
            //User chose the manual way
            else if(answer03=='y')
            {
                //Filling the array
                fulfillManually(array2,indexA2,"second");
                //Get out of the loop
                break;
            }
            //If any other input
            else
            {
                fflush(stdin);
                printf("invalid input\n");
            }
        }
        //If more than one char typed in
        else
        {
            printf("invalid input");
            fflush(stdin);
        }

    }

    //Printing second array
    printf("\nSecond array:\n");
    printArray(array2,indexA2);

    //Gets user input
    //Duplicates: yes or no?
    while (1)
    {
        printf("Do you want to include duplicate results? y\\n\n");
        char answer02;

        //If only one char typed in
        if(scanf("%c", &answer02) == 1)
        {
            fflush(stdin);
            //No duplicates
            if(answer02=='n')
            {
                deleteDuplicates(array1,&indexA1);
                deleteDuplicates(array2,&indexA2);
                //Get out of the loop
                break;
            }
            //Including duplicates
            else if(answer02=='y')
            {                                                   //To avoid array 3 multiplication results cleans the first array
                //Get out of the loop
                break;
            }
            //If any other input
            else
            {
                fflush(stdin);
                printf("invalid input\n");
            }
        }
        //If more than one char typed in
        else
        {
            printf("invalid input\n");
            fflush(stdin);
        }
    }

    //NEW LIIIIIIIINES
    printf("\n\n\n\n");

    //Prints first array
    printf("\nFirst array:\n");
	for(int i=0; i<indexA1; i++)
    {
        printf("%d\n",array1[i]);
    }

    //NEW LIIIIIIIINES
    printf("\n\n\n\n");

    //Prints second array
    printf("\nSecond array:\n");
    for(int i=0; i<indexA2; i++)
    {
        printf("%d\n",array2[i]);
    }

    //NEW LIIIIINES
    printf("\n\n\n\n");

    int array3[MAX_INDEX];
    int indexA3 = 0;

    //Checks longer array
    if (indexA1 >= indexA2)
    {
        int indexAC=0;
        int checked[MAX_INDEX*2]={'\0'};

        for (int i=0;i<indexA1;i++)           //for each value of the first array
        {
            int temp=array1[i];
            short int good=1;

            for (int k=0;k<indexAC;k++)     //check if already checked
            {
                if(temp==checked[k])
                {
                    good=0;
                }
            }

            if(good==1)                     //if not
            {
                int timesIn1=0;
                int timesIn2=0;
                checked[indexAC]=temp;
                indexAC++;

                for(int j=0;j<indexA1;j++)     //count the occurrences for each array
                {
                    if(array1[j]==temp)timesIn1++;
                }

                for(int j=0;j<indexA2;j++)
                {
                    if(array2[j]==temp)timesIn2++;
                }

                if(timesIn1<timesIn2&&timesIn1!=0&&timesIn2!=0)
                {
                    for(int i=0;i<timesIn1;i++)
                    {
                        array3[indexA3]=temp;
                        indexA3++;
                    }

                }
                else if(timesIn1>=timesIn2&&timesIn1!=0&&timesIn2!=0)
                {
                    for(int i=0;i<timesIn2;i++)
                    {
                        array3[indexA3]=temp;
                        indexA3++;
                    }
                }
            }
        }
    }
    else
    {
        int indexAC=0;
        int checked[MAX_INDEX*2]={'\0'};

        for (int i=0;i<indexA2;i++)           //for each value of the second array
        {
            int temp=array2[i];
            int good=1;

            for (int k=0;k<indexAC;k++)     //check if already checked
            {
                if(temp==checked[k])
                {
                    good=0;
                }
            }

            if(good==1)                     //if not
            {
                int timesIn1=0;
                int timesIn2=0;
                checked[indexAC]=temp;
                indexAC++;

                for (int j=0;j<indexA1;j++)     //count the occurrences for each array
                {
                    if(array1[j]==temp)timesIn1++;
                }

                for (int j=0;j<indexA2;j++)
                {
                    if(array2[j]==temp)timesIn2++;
                }

                if(timesIn1<timesIn2&&timesIn1!=0&&timesIn2!=0)
                {
                    for(int i=0;i<timesIn1;i++)
                    {
                        array3[indexA3]=temp;
                        indexA3++;
                    }

                }
                else if(timesIn1>=timesIn2&&timesIn1!=0&&timesIn2!=0)
                {
                    for(int i=0;i<timesIn2;i++)
                    {
                        array3[indexA3]=temp;
                        indexA3++;
                    }
                }
            }
        }
    }

    //Printing merged array
    printf("\nIntersected array:\n");
    printArray(array3, indexA3);
    fflush(stdin);
    getchar();
    return 0;
}
