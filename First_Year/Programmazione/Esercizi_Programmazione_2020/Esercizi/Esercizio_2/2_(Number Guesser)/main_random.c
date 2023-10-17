#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numGen;
    int minimum = 1;
    int maximum = 0;
    char answer;
    char answer2;

    while(1){

        printf("Insert range \'min-max\'\n");
        scanf("%d-%d", &minimum, &maximum);
        if(minimum<=maximum && minimum>0) break;
        else printf("Invalid range\n\n");
    }

    while(1) {

        numGen = minimum + (rand()+time(NULL))%(maximum+1-minimum);

        printf("Is your number: %i \'y\\n\'\n", numGen);
        scanf(" %c", &answer);
        if(answer=='y') {
            printf("\nI guessed!\n");
            break;
        }
        else if(answer=='n') {
        printf("Is it bigger or smaller? \'>\\<\'\n");
        scanf(" %c", &answer2);
        if(answer2=='>') minimum = numGen + 1;
        else if(answer2=='<') maximum = numGen - 1;
        }
    }

    return 0;
}


