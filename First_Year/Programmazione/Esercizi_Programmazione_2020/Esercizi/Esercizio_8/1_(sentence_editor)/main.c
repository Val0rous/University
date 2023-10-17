/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/12/04
Scrivere un programma C che prenda da riga di comando una frase
e stampi a video la frase così modificata.

Per ogni parola in ingresso:

1.  Spostare la prima lettera alla fine.

2.  Aggiungere le lettere "an" alla fine di ogni parola di tre lettere o meno,
    e "o" alla fine di ogni parola.

3.  Fare in modo che la nuova prima lettera della parola corrisponda al tipo
    (minuscola/maiuscola) della vecchia prima lettera della parola.
    Rendete minuscola la lettera che è stata spostata, se non è la prima lettera.
    Non modificare il tipo (minuscola/maiuscola) delle altre lettere.

4.  Ogni carattere non isalpha deve rimanere inalterato.

Ad esempio, data come input la frase:

I *REALLY* like Yale's course-selection procedures.

il programma deve stampare in output:

Ian *EALLYro* ikelo Aleyo'san ourseco-electionso rocedurespo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

char *wordManipulator(char *sentence, int *start, int end)
{
    //create new temp var for the word to change (more eventual space for the new letters)
    char temp[end - *(start) + 3];
    //copy it in temp
    for (int i = 0; i < (end - *(start) + 1); i++)
    {
        temp[i] = sentence[*start + i];
    }
    //remove terminator character
    temp[end - *start + 1] = '\0';
    //point 1
    char firstChar = temp[0];               //store first char
    int index = 0;
    for (; index <= strlen(temp); index++) // shift all characters of 1 place
    {
        temp[index] = temp[index + 1];
    } //place and lower the first character at the end
    temp[index - 1] = tolower(firstChar);   //invert this and the bottom line if you want that single characters become capital
    if (91 > firstChar && firstChar > 64) temp[0] = toupper(temp[0]);   //if first char was capital, make also the new one
    temp[index] = '\0';                 //add terminator charachter
// point 2
    int moreSpace = 0;      //to record how many new letter we added
//add "an" if start is shorter than 3
    if(end - *(start)<3)
    {
        moreSpace=2;
        temp[index]='a';
        temp[index+1]='n';
        temp[index+2]='\0';
    }
    else// add "o"
    {
        moreSpace=1;
        temp[index]='o';
        temp[index+1]='\0';
    }
    //allocate space for the new sentence string
    char *result = (char *)calloc(strlen(sentence) + moreSpace, sizeof(char));
    if (result == NULL)
    {
        printf("not enough memory");
        exit(1);
    }
    //copy the old sentence in the result string but with the corrected word
    for (int i = 0; i <= strlen(sentence) + moreSpace; i++)
    {
        if (i < *start)
        {
            result[i] = sentence[i];
        }

        if (end+moreSpace>=i  && *start<=i)
        {
            result[i] = temp[i - *start];
        }
        if(i>end+moreSpace)
        {
            result[i] = sentence[i-moreSpace];
        }

    }


    //update start
    *start = end +1+moreSpace;
    //deallocate old sentence
    free(sentence);
    //return new sentence
    return result;
}

int main(int argc, char *argv[]) //Open in cmd or powershell (in file folder) and type .\main.exe <your_string> (Windows only)
{

    int len = 1;
    for (int i = 1; i < argc; i++) //loop to get total string length
    {
        len += strlen(argv[i]); //Gets string length
    }

    char *sentence= (char *)calloc(len, sizeof(char));        //create string to store the sentence
    if (sentence == NULL)
    {
        printf("not enough memory");
        exit(1);
    }
    //in this loop we will store the sentence,
    strcpy(sentence, argv[1]);     //copy first item in the sentence
    for (int i = 2; i < argc; i++) //loop to append all the other words in the sentence
    {
        strcat(sentence, " "); //to add the space
        strcat(sentence, argv[i]);
    }

    printf("\nInput sentence:\t\t%s\n\nWARNING: if output line does not appear disable real time protection in windows defender or try 4 times\n",sentence);
    printf("alternatively use commented code for user input\n");

    //we need to understand the indexes of the word to apply then the algorithm only to that word, repeat for each word
    int start = 0;  //indexes of start and and of the word in the sentence
    int end = 0;

    while (end < strlen(sentence))
    {

        for (; !isalnum(sentence[start]) || isspace(sentence[start]); start++)
        {
        } //to know where to start applying the algorithm shifts the start index till the first alpha char
        for (end = start + 1; isalnum(sentence[end]) && !isspace(sentence[end]); end++)
        {
        }//shifts the end index till the first not alpha char
        if (end > strlen(sentence)) //stop accordingly
            break;
        end--; //end character
        //apply the algorithm (it will also update start index)
        sentence= wordManipulator(sentence, &start, end);




    }
    //print result and free last used string
    printf("\nOutput sentence:\t%s\n",sentence);
    free (sentence);
    printf("press any key to continue...");
    getchar();
    return 0;
}

//CODE FOR USER INPUT
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_CHAR 300

char *wordManipulator(char *sentence, int *start, int end)
{
    char temp[end - *(start) + 3];
    for (int i = 0; i < (end - *(start) + 1); i++)
    {
        temp[i] = sentence[*start + i];
    }
    temp[end - *start + 1] = '\0';
    //point 1
    char firstChar = temp[0];
    int index = 0;
    for (; index <= strlen(temp); index++) // < or <= ??
    {
        temp[index] = temp[index + 1];
    }
    temp[index - 1] = tolower(firstChar);   //invert this and the bottom line if you want that single characters become capital
    if (91 > firstChar && firstChar > 64) temp[0] = toupper(temp[0]);
    temp[index] = '\0';
// point 2
    int moreSpace = 0;

    if(end - *(start)<3)
    {
        moreSpace=2;
        temp[index]='a';
        temp[index+1]='n';
        temp[index+2]='\0';
    }
    else
    {
        moreSpace=1;
        temp[index]='o';
        temp[index+1]='\0';
    }

    char *result = (char *)calloc(strlen(sentence) + moreSpace, sizeof(char));
    if (result == NULL)
    {
        printf("not enough memory");
        exit(1);
    }
    for (int i = 0; i <= strlen(sentence) + moreSpace; i++)
    {
        if (i < *start)
        {
            result[i] = sentence[i];
        }

        if (end+moreSpace>=i  && *start<=i)
        {
            result[i] = temp[i - *start];
        }
        if(i>end+moreSpace)
        {
            result[i] = sentence[i-moreSpace];
        }

    }



    *start = end +1+moreSpace;
    free(sentence);

    return result;
}

int main()
{
    char *sentence= (char *)calloc(MAX_CHAR, sizeof(char));        //create string to store the sentence
    if (sentence == NULL)
    {
        printf("not enough memory");
        exit(1);
    }
    printf("Type the sentence to manipulate:");
    gets(sentence);

    printf("\nInput sentence:\t\t%s\n",sentence);

    //in this loop we will store the sentence, understand the indexes of the word to apply then the algorithm only to that word, repeat for each word
    int start = 0;  //indexes of start and and of the word in the sentence
    int end = 0;

    while (end < strlen(sentence))
    {

        for (; !isalnum(sentence[start]) || isspace(sentence[start]); start++)
        {
        } //to know where to start applying the algorithm
        for (end = start + 1; isalnum(sentence[end]) && !isspace(sentence[end]); end++)
        {
        }
        if (end > strlen(sentence))
            break;
        end--; //end character

        sentence= wordManipulator(sentence, &start, end);




    }
    printf("\nOutput sentence:\t%s\n",sentence);
    free (sentence);
    getchar();
    return 0;
}
*/
