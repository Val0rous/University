// Author: Filippo
// Date: 20191014
// Description: Read sentence until a CHARACTER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define CARATTERE '#'

int main(void){

    char ch;
    char bufferA[100];
    int i, index = 0;

    memset(bufferA, '\0', sizeof(bufferA)); /*function memset() used to clear the memory location*/

    while ((ch = getchar()) != CARATTERE){  //legge un singolo carattere, restituendolo
        bufferA[index++]=ch;
    }

    printf("The input sentence is: \n%s\n", bufferA);

    return 0;
}
