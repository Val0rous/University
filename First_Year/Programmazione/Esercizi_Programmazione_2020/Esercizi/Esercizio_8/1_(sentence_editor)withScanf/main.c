/*
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
