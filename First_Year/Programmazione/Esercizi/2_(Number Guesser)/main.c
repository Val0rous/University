/*
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

//Creating a function to guess the number n the user thought, with n belonging to N
int guessNumber(int minimum, int maximum)
{
    //Initializing variables
    int guess = (minimum+maximum)/2;
    //The quickest way to guess a number is to start out with the average of the two extremes and iterating
    char answer;
    char greaterOrSmaller;

    printf("Is your number: %i \'y\\n\'\n", guess);
    scanf(" %c", &answer);

    //If guessed (y), the program pauses (until the user presses a key)
    if(answer=='y')
    {
        printf("\nI guessed!\n");
        //Clears keyboard buffer
        fflush(stdin);
        //Program is paused until user presses a key
        getchar();
    }

    //If guess is wrong (n)
    else if(answer=='n')
    {
            printf("Is it bigger or smaller? \'>\\<\'\n");
            scanf(" %c", &greaterOrSmaller);

            //If greater (>)
            if(greaterOrSmaller=='>')
            {
                //If maximum and minimum are two adjacent numbers, choose the greater one (avoids abnormal behavior due to int variables)
                if(maximum-minimum==1)
                guessNumber(maximum, maximum);
                
                //Average between guess and maximum
                else guessNumber(guess, maximum);
            }

            //If smaller (<)
            else if(greaterOrSmaller=='<')
            {
                //If maximum and minimum are two adjacent numbers, choose the smaller one (avoids abnormal behavior due to int variables)
                if(maximum-minimum==1)
                guessNumber(minimum, minimum);

                //Average between guess and minimum
                else guessNumber(minimum, guess);
            }

            //If any other input
            else
            {
                printf("Invalid input\n\n");
                //Clears keyboard buffer
                fflush(stdin);
                //Resets guess to default value, which is the average of the two extremes
                guessNumber(minimum, maximum);
            }
    }

    //If any other input
    else
    {
        printf("Invalid input\n\n");
        //Clears keyboard buffer
        fflush(stdin);
        //Resets guess to default value, which is the average of the two extremes
        guessNumber(minimum, maximum);

    }
}

int main()
{
    //Initializing default variables
    int minimum = 1;
    int maximum = 0;

    //If minimum is illegal, get minimum and maximum values again
    while(minimum>maximum || minimum==0)
    {
        printf("Insert range \'min-max\'\n");
        scanf("%d-%d", &minimum, &maximum);

        //If minimum and maximum are legal, get out of the loop (and move on to guessNumber() )
        if(minimum<=maximum && minimum>0) break;

        //Else, repeat the loop until you get two acceptable values
        else printf("Invalid range\n\n");
    }

    //Let's guess the number you thought!
    guessNumber(minimum, maximum);

    return 0;
}