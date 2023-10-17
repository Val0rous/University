/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

            Let us know if it's over or under commented, thanks for understendig!

DATE: 2020/10/16

Scrivere un programma C che legga da tastiera un testo terminato dal carattere #
e poi stampi le statistiche relative al numero di spazi,
al numero di caratteri di nuova linea,
al numero di caratteri letti,
al numero di quelli maiuscoli, etc.
utilizzando almeno una volta tutte le funzioni dell'header ctype.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //Including string stuff
#include <ctype.h>      //and some exciting string stuff

#define TERMINATOR '#'  //We want '#' to be the end character in the string typed in by the user

int main()
{
    //Declaring and initializing the variables we're gonna use later
    char answer='n';
    char ch;
    char phrase[100];   //Array containing 99 characters + NULL (end character)
    int index = 0;
    int spaces = 0;
    int numbers = 0;
    int alphanumeric=0;
    int alpha=0;
    int printable=0;
    int control=0;
    int graphic=0;
    int punct=0;
    int exadec=0;
    int newLines = 0;
    int tabs = 0;
    int readCharacters = 0;
    int upperCharacters = 0;
    int lowerCharacters = 0;

    do
    {
        printf("Enter a sentence terminated by\'#\':\n");
        memset(phrase, '\0', sizeof(phrase));               //function memset() used to clear the memory location

        while ((ch = getchar()) != TERMINATOR)              //Important to use "!=0" and not "==0"
        {   //reads a single character
            phrase[index++] = ch;
            if (isspace(ch)!=0) spaces++;
            if (isalnum(ch)!=0) alphanumeric++;
            if (isalpha(ch)!=0) alpha++;
            if (iscntrl(ch)!=0) control++;                   //Creating stats for each category
            if (isdigit(ch)!=0) numbers++;
            if (isgraph(ch)!=0) graphic++;
            if (isprint(ch)!=0) printable++;
            if (ispunct(ch)!=0) punct++;
            if (isupper(ch)!=0) upperCharacters++;
            if (islower(ch)!=0) lowerCharacters++;
            if (isxdigit(ch)!=0) exadec++;
            if (ch=='\n') newLines++;
            if (ch=='\t') tabs++;
        }

        readCharacters=index+1;     //Makes the counter start from 1 rather than 0

        //Printing stats
        printf("The number of white-spaces is: \t\t\t%d\n", spaces);
        printf("The number of alphanumeric characters is: \t%d\n", alphanumeric);
        printf("The number of alphabetical characters is: \t%d\n", alpha);
        printf("The number of control characters is: \t\t%d\n", control);
        printf("The number of number characters is: \t\t%d\n", numbers);
        printf("The number of graphical characters is: \t\t%d\n", graphic);
        printf("The number of lower characters is: \t\t%d\n", lowerCharacters);
        printf("The number of printable characters is: \t\t%d\n", printable);
        printf("The number of punctuation characters is: \t%d\n", punct);
        printf("The number of upper characters is: \t\t%d\n", upperCharacters);
        printf("The number of exadecimal characters is: \t%d\n", exadec);
        printf("The number of \"new line\" characters is: \t%d\n", newLines);
        printf("The number of tabulation characters is: \t%d\n", tabs);

        //Makes sentence 100% lowercase
        for(int i=0;phrase[i];i++)
        {
            if(isalpha(phrase[i]))
                phrase[i] = tolower(phrase[i]);
        }

        //...and prints it
        printf("\nYour sentence lowered is: %s\n",phrase);

        //Makes sentence 100% uppercase
        for(int i=0;phrase[i];i++)
        {
            if(isalpha(phrase[i]))
                phrase[i] = toupper(phrase[i]);
        }
        //...and prints it
        printf("\nYour sentence upped is: %s\t\n\n", (phrase));
        fflush(stdin);      //Clearing keyboard buffer

        //Asks the user whether he wants to type in another sentence or not and waits for input
        printf("Do you want to try again? type \'y\' otherwise type any character to exit \n");
        scanf("%c", &answer);
    }

while(answer=='y');     //Repeats all statements until the answer is 'y' (YES)
return 0;
}
