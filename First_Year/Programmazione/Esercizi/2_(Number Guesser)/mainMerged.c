/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

            Let us know if it's over or under commented, thanks for understendig!

DATE: 2020/10/11

Pensa a un numero.

L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.

L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max).
Se i valori inseriti non rispettano il vincolo 0<min≤max, l’operazione di lettura va ripetuta.
L’utente pensa ad un numero compreso tra min e max.
Il programma cerca di indovinare la scelta dell’utente e propone un numero.
A seconda della situazione l’utente deve dire al programma se
    il numero da indovinare è più piccolo;
    il numero da indovinare è più grande;
    ha indovinato.
Non poniamo limite al numero di tentativi
*/

#include <stdio.h>
#include <stdlib.h>
//declaring a variable to count the number of attempts
unsigned short int attempts=0;




//Function to Guess the number casually, go down to see the call (row 167)
void guessRandom(int minimum, int maximum){
    //declaring the variables we'll use during the function
    int numGen;
    char answer;
    char answer2;
    //entering a cycle until the number is guessed
     while(1) {
            attempts++;                                                 //counting another attempt
            numGen = minimum + (rand()+time(NULL))%(maximum+1-minimum); //generating a random number in range
            printf("Is your number: %i \'y\\n\'\n", numGen);            //asking if it's correct
            scanf(" %c", &answer);
            if(answer=='y') {
                printf("\nI guessed! In %d attempts\n\a",attempts);     //if yes, print the number of attempts and plays our beloved sound
                fflush(stdin);                                          //Clears keyboard buffer
                getchar();                                              //Program is paused until user presses a key
                break;
            }
            else if(answer=='n') {                                      //if no, update the range with user instructions
            printf("Is it bigger or smaller? \'>\\<\'\n");              //and the cycle will repeat with the new range
            scanf(" %c", &answer2);
            if(answer2=='>') minimum = numGen + 1;
            else if(answer2=='<') maximum = numGen - 1;
            else{printf("Invalid input, type \'>\'or\'<\'\n\n");
                fflush(stdin);
                attempts--;
                }
            }
            else{printf("Invalid input, type \'y\'or\'n\'\n\n");
                fflush(stdin);
                attempts--;
            }
            fflush(stdin);                                              //clears cache to avoid unexpected behavior if something else is printed
        }
}





//Function to Guess the number with a dichotomous method, go down to see the call (row 166)
void guessDichotomous(int minimum, int maximum)
{   attempts++;                                             //counting another attempt
                                                            //Initializing variables
    int guess = (minimum+maximum)/2;                        //The quickest way to guess a number is to start out with the average of the two extremes and iterating
    char answer=' ';
    char greaterOrSmaller=' ';

    printf("Is your number: %i \'y\\n\'\n", guess);         //asking the user if the guess is correct
    fflush(stdin);
    scanf("%c", &answer);

    if(answer=='y')                                         //If guessed (y), the program pauses (until the user presses a key) and prints the number of attempts
    {
    printf("\nI guessed! In %d attempts\n\a",attempts);     //and also plays our beloved sound
        fflush(stdin);                                      //Clears keyboard buffer
        getchar();                                          //Program is paused until user presses a key
    }


                                //If guess is wrong (n)
    else if(answer=='n')                                    //if the guess is wrong ask the user if the number is greater or smaller than the guess in order to adjust the range and iterating
    {
            printf("Is it bigger or smaller? \'>\\<\'\n");
            scanf(" %c", &greaterOrSmaller);

            //If greater (>)
            if(greaterOrSmaller=='>')
            {
                //  ---If maximum and minimum are two adjacent numbers, choose the greater one (avoids abnormal behavior due to division between int variables)---
                if(maximum-minimum==2)
                guessDichotomous(maximum, maximum);

                else guessDichotomous(guess, maximum);//new guess will be Average between guess and maximum
            }

            //If smaller (<)
            else if(greaterOrSmaller=='<')
            {
                if(maximum-minimum==2)                 //If maximum and minimum are two adjacent numbers, choose the smaller one (avoids abnormal behavior due to int variables)
                guessDichotomous(minimum, minimum);

                else guessDichotomous(minimum, guess); //new guess will be Average between guess and minimum
            }

            //If any other input
            else
            {
                printf("Invalid input\n\n");
                fflush(stdin);                      //Clears keyboard buffer
                attempts--;                         //this attempt is not valid
                guessDichotomous(minimum, maximum); //Resets guess to default value, which is the average of the two extremes
            }
    }

    //If any other input
    else
    {
        printf("Invalid input\n\n");
        fflush(stdin);                      //Clears keyboard buffer
        guessDichotomous(minimum, maximum); //Resets guess to default value, which is the average of the two extremes

    }
}

int main()
{
    //Initializing default variables
    short unsigned int method=2;
    int minimum = 1;
    int maximum = 0;
    printf("Think a number, I'll guess it!\n");
    while(method>1)                                             //cycle to ask which method to use
    {
        printf("Shall i use a dichotomous method or a random one? \'0\\1\'\n");
        scanf("%i",&method);
        fflush(stdin);
        switch(method){
            case 0:
                printf("Smart choice ;)\n\n");
                break;
            case 1:
                printf("Oh you feel lucky :O\n\n");
                break;
            default:
                printf("\nInvalid choice, you have to type only \'0\' or \'1\'\nIt's not that difficult, you can make it! Try again\n\n");
                method=2;
                break;
        }
    }
    while(1)            //cycle to ask the range within the given constraints
    {
        printf("Think a number and Insert a range \'min-max\'\n");
        scanf("%d-%d", &minimum, &maximum);
        fflush(stdin);
        if(minimum<=maximum && minimum>0) break;                                             //If minimum and maximum are legal, get out of the loop
        else printf("Invalid range, see constraints in the assignment and try again!\n\n");  //Else, repeat the loop until you get two acceptable values
    }

        //Let's guess the number you thought!
        //we divided the 2 methods in 2 functions,
        //it's a matter of style but we think it's neater in this way
    if(method==0)guessDichotomous(minimum, maximum);
    else if(method==1)guessRandom(minimum, maximum);
    return 0;
}
