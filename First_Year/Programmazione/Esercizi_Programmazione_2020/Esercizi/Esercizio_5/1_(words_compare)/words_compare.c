/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/10/30

Scrivere un programma C che riceva in ingresso due parole inserite da tastiera. Si consideri che ciascuna parola pu� contenere al massimo 30 caratteri.
Il programma deve essere case sensitive, cio� deve distinguere lettere minuscole da lettere maiuscole e deve essere in grado anche di analizzare numeri, simboli e segni di punteggiatura.
Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere �*�. Ad esempio, inserite le parole

abchdfffchdchdtlchd

e

chd

il programma deve visualizzare la parola

ab*fff**tl*

Scrivere due versioni: la prima deve ignorare la presenza della libreria string.h e quindi dovete lavorare esplicitamente su ogni singolo carattere delle stringhe.
La seconda deve usare le funzioni della libreria string.h per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{   //Initializing variables
    char str1[31];
    char str2[31];
    int length1 = 0, length2 = 0, i = 0;
    int ans = 0, check;

    //Ask if the program is allowed to use string.h library
    while (1)
    {
        printf("Shall I use the library?\nNo String.h (1) \nString.h (2)\n");
        scanf("%d", &ans);
        fflush(stdin);
        if (ans == 1 || ans == 2)
            break;
        printf("Invalid input!\n\n");
    }
    system("cls");
    //Get first string
    while(1){                                                   //cycle to check if the string is exceeding the index
    printf("Type the first string: ");
    scanf("%s", &str1);
    fflush(stdin);
    length1=0;
    while (str1[length1] != '\0')                               //Checks length of first string
        {
            length1++;
        }
    if (length1<31)break;
    printf("the string can be maximum 30 characters\n");
    }

    //Get second string
    while(1){                                                  //cycle to check if the string is exceeding the index
    printf("Type the second string: ");
    scanf("%s", &str2);
    fflush(stdin);
    length2=0;
    while (str2[length2] != '\0')                               //Checks length of second string
        {
            length2++;
        }
    if (length2<31)break;
    printf("the string can be maximum 30 characters\n");
    }

    //No string.h
    if (ans == 1)
    {
        while (str1[length1] != '\0')                               //Checks length of first string
        {
            length1++;
        }
        while (str2[length2] != '\0')                               //Checks length of second string
        {
            length2++;
        }

        for (i = 0; i + (length2 - 1) < length1; i++)
        {                                                           //Runs through first string
            check = 1;                                              //Flag if substrings are equal
            for (int k = 0; k < length2; k++)
            {                                                       //Runs through second string
                if (str1[i + k] != str2[k])                         //matching each character of the first string with the second one
                {
                    check = 0;                                      //if match not found exit the cycle
                    break;
                }                                                   //If substrings are not equal, check = 0
            }

            if (check == 1)                                         //if string matches
            {

                str1[i] = '*';                                      //replace  the first character with the "*"
                i++;                                                //increase the index of the cycle
                for (int k = 0; k + (length2 - 1) < length1; k++)   //shorten the first string deleting the secondary string
                {
                    str1[i + k] = str1[i + k + length2 - 1];
                }
                length1 -= length2 - 1;                             //update length1
                str1[length1] = '\0';                               //place terminator character
                i--;
            }
        }

        printf("\nResult: %s", str1);                               //print result

    }

    //Using string.h
    else
    {
        length1 = strlen(str1);                                     //get length of first string
        length2 = strlen(str2);                                     //get length of second string
        while (strstr(str1, str2))                                  //while the second string occurs on the first one:
        {
            char *occ = strstr(str1, str2);                         //find the address of the first occurrance
                *occ = '*';                                         //replace it with '*' char
                for (int i = 1; i + (length2 - 1) <= length1; i++)  //shorten the first string deleting the secondary string
                {
                    *(occ + i) = *(occ + i + length2 - 1);
                }

                length1 -= length2 - 1;                             //update length1
                str1[length1] = '\0';                               //place terminator character
        }
        printf("\nResult: %s", str1);                               //print result
    }
    printf("\nPress enter to continue...");                         //exit protocol
    getchar();
	return 0;
}
