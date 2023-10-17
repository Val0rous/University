/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/10/30
Si realizzi un programma in linguaggio C in grado di gestire una rubrica di nomi e numeri telefonici.
La rubrica può contenere fino a 100 voci diverse. Ciascuna voce è composta da un nome e da un numero di telefono.

Il programma deve fornire all’utente un menù di scelta, con le seguenti voci:

1) Aggiungi nuova voce in rubrica

2) Ricerca esatta per nome

3) Ricerca approssimata per nome

4) Stampa completa rubrica

0) Esci dal programma

Una volta che l’utente ha scelto l’operazione desiderata (1-4),
il programma acquisirà i dati necessari dall’utente ed eseguirà il comando.

Nota: nella rubrica non possono esistere due voci con lo stesso nome.

Realizzare una variante del programma implementando un vettore frastagliato.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


#define MAX_ENTRIES 100
#define MAX_TEL_NUM_LENGTH 20
#define MAX_TEL_NAME_LENGTH 50

int main()
{
    char jagged;
    while (1)
    {
        printf("1)I wanna use a jagged array\n2)I don't");
        jagged = getch();
        if (jagged == '1' || jagged == '2')
            break;
        else
            printf("Error: wrong input. Please try again\a\n\n");
    }
    system("cls");
    if (jagged = '2')
    {
        //Contacts name list
        char name_list[MAX_ENTRIES][MAX_TEL_NAME_LENGTH + 1];
        //Array index dimension
        int nameIndexDim = -1;
        //Contacts phone number list
        char number_list[MAX_ENTRIES][MAX_TEL_NUM_LENGTH + 1];
        //Array index dimension
        int numberIndexDim = -1;

        //welcome message
        printf("Welcome to the contacts app! What can I help you with?\n");

        while (1) //MAIN LOOP
        {
            char choice;
            //print menu
            printf("1) Add a new entry\n");
            printf("2) Search by name (exact search)\n");
            printf("3) Search by name (approximate search)\n");
            printf("4) Print complete contact list\n");
            printf("0) Close the program\n\n");

            while (1) //get answer cycle
            {
                //Gets user input
                choice = getch();

                if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '0')
                    break;

                printf("Error: wrong input. Please try again\a\n\n");
            }

            //new item selection
            if (choice == '1')
            {
                system("cls");

                if (nameIndexDim < MAX_ENTRIES)
                {
                    char tempName[MAX_TEL_NAME_LENGTH + 1]; //store name in tempName
                    printf("Type the name of the contact:\n");
                    fgets(tempName, MAX_TEL_NAME_LENGTH, stdin); //Max phone number length is 20 digits
                    tempName[strlen(tempName) - 1] = '\0';
                    fflush(stdin);

                    for (int j = 0; j <= strlen(tempName); j++)
                    {
                        tempName[j] = toupper(tempName[j]);
                    }
                    int good = 1; //check if present in the array

                    for (int i = 0; i <= nameIndexDim; i++)
                    {
                        if (strcmp(name_list[i], tempName) == 0)
                            good = 0;
                    }

                    if (good == 1)
                    { //if not

                        strcpy(name_list[++nameIndexDim], tempName); //add it to the array
                        char tempNum[MAX_TEL_NUM_LENGTH + 1];
                        printf("Type the corresponding number:\n"); //ask corresponding number and save it
                        fgets(tempNum, MAX_TEL_NUM_LENGTH, stdin);
                        tempName[strlen(tempName) - 1] = '\0';
                        fflush(stdin);
                        for (int j = 0; j <= strlen(tempNum); j++)
                        {
                            tempNum[j] = toupper(tempNum[j]);
                        }
                        strcpy(number_list[++numberIndexDim], tempNum);
                        printf("Item saved succesfully!\n");
                    }
                    else
                        printf("name already present!\a\n");
                }
                else
                    printf("There's no more space!\a\n");
                _sleep(1);
            }
            if (choice == '2')
            {
                system("cls");
                char tempName[MAX_TEL_NAME_LENGTH + 1];
                printf("Type the exact name of the contact to search:\n");
                fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                tempName[strlen(tempName) - 1] = '\0';
                for (int j = 0; j <= strlen(tempName); j++)
                {
                    tempName[j] = toupper(tempName[j]);
                }
                fflush(stdin);
                int found = 0;

                for (int i = 0; i <= nameIndexDim; i++)
                {
                    if (strcmp(name_list[i], tempName) == 0)
                    {
                        found++;
                        printf("%s\t\t%s\n", name_list[i], number_list[i]);
                    }
                }
                if (!found)
                {
                    printf("No items found\n");
                }
                else
                    printf("item found\n");
                printf("press a key to continue...\n");
                getch();
            }

            if (choice == '3')
            {
                system("cls");
                char tempName[MAX_TEL_NAME_LENGTH + 1];
                printf("Type part of the name of the contact to search:\n");
                fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                tempName[strlen(tempName) - 1] = '\0';
                for (int j = 0; j <= strlen(tempName); j++)
                {
                    tempName[j] = toupper(tempName[j]);
                }
                fflush(stdin);
                int found = 0;
                for (int i = 0; i <= nameIndexDim; i++)
                {
                    if (strstr(name_list[i], tempName))
                    {
                        found++;
                        printf("%s\t\t%s\n", name_list[i], number_list[i]);
                    }
                }
                if (!found)
                {
                    printf("No items found\n");
                }
                else
                    printf("%d item%c found\n", found, found == 1 ? '\0' : 's');
                printf("press a key to continue...\n");
                getch();
            }

            if (choice == '4')
            {
                system("cls");
                printf("Name,\t\tnumber\n");
                for (int i = 0; i <= nameIndexDim; i++)
                {
                    printf("%s\t\t%s\n", name_list[i], number_list[i]);
                }
                printf("press a key to continue...\n");
                getch();
            }
            if (choice == '0')
                break;
            system("cls");
        }
    }
    else if (jagged == '1')
    {
        //Contacts name list
        char *name_list[MAX_ENTRIES];
        //Array index dimension
        int nameIndexDim = -1;
        //Contacts phone number list
        char *number_list[MAX_ENTRIES];
        //Array index dimension
        int numberIndexDim = -1;

        //welcome message
        printf("Welcome to the contacts app! What can I help you with?\n");

        while (1) //MAIN LOOP
        {
            char choice;
            //print menu
            printf("1) Add a new entry\n");
            printf("2) Search by name (exact search)\n");
            printf("3) Search by name (approximate search)\n");
            printf("4) Print complete contact list\n");
            printf("0) Close the program\n\n");

            while (1) //get answer cycle
            {
                //Gets user input
                choice = getch();

                if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '0')
                    break;

                printf("Error: wrong input. Please try again\a\n\n");
            }

            //new item selection
            if (choice == '1')
            {
                system("cls");

                if (nameIndexDim < MAX_ENTRIES)
                {
                    char tempName[MAX_TEL_NAME_LENGTH + 1]; //store name in tempName
                    printf("Type the name of the contact:\n");
                    fgets(tempName, MAX_TEL_NAME_LENGTH, stdin); //Max phone number length is 20 digits
                    tempName[strlen(tempName) - 1] = '\0';
                    fflush(stdin);

                    for (int j = 0; j <= strlen(tempName); j++)
                    {
                        tempName[j] = toupper(tempName[j]);
                    }
                    int good = 1; //check if present in the array

                    for (int i = 0; i <= nameIndexDim; i++)
                    {
                        if (strcmp(name_list[i], tempName) == 0)
                            good = 0;
                    }

                    if (good == 1)
                    { //if not

                        strcpy(name_list[++nameIndexDim], tempName); //add it to the array
                        char tempNum[MAX_TEL_NUM_LENGTH + 1];
                        printf("Type the corresponding number:\n"); //ask corresponding number and save it
                        fgets(tempNum, MAX_TEL_NUM_LENGTH, stdin);
                        tempName[strlen(tempName) - 1] = '\0';
                        fflush(stdin);
                        for (int j = 0; j <= strlen(tempNum); j++)
                        {
                            tempNum[j] = toupper(tempNum[j]);
                        }
                        strcpy(number_list[++numberIndexDim], tempNum);
                        printf("Item saved succesfully!\n");
                    }
                    else
                        printf("name already present!\a\n");
                }
                else
                    printf("There's no more space!\a\n");
                _sleep(1);
            }
            if (choice == '2')
            {
                system("cls");
                char tempName[MAX_TEL_NAME_LENGTH + 1];
                printf("Type the exact name of the contact to search:\n");
                fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                tempName[strlen(tempName) - 1] = '\0';
                for (int j = 0; j <= strlen(tempName); j++)
                {
                    tempName[j] = toupper(tempName[j]);
                }
                fflush(stdin);
                int found = 0;

                for (int i = 0; i <= nameIndexDim; i++)
                {
                    if (strcmp(name_list[i], tempName) == 0)
                    {
                        found++;
                        printf("%s\t\t%s\n", name_list[i], number_list[i]);
                    }
                }
                if (!found)
                {
                    printf("No items found\n");
                }
                else
                    printf("item found\n");
                printf("press a key to continue...\n");
                getch();
            }

            if (choice == '3')
            {
                system("cls");
                char tempName[MAX_TEL_NAME_LENGTH + 1];
                printf("Type part of the name of the contact to search:\n");
                fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                tempName[strlen(tempName) - 1] = '\0';
                for (int j = 0; j <= strlen(tempName); j++)
                {
                    tempName[j] = toupper(tempName[j]);
                }
                fflush(stdin);
                int found = 0;
                for (int i = 0; i <= nameIndexDim; i++)
                {
                    if (strstr(name_list[i], tempName))
                    {
                        found++;
                        printf("%s\t\t%s\n", name_list[i], number_list[i]);
                    }
                }
                if (!found)
                {
                    printf("No items found\n");
                }
                else
                    printf("%d item%c found\n", found, found == 1 ? '\0' : 's');
                printf("press a key to continue...\n");
                getch();
            }

            if (choice == '4')
            {
                system("cls");
                printf("Name,\t\tnumber\n");
                for (int i = 0; i <= nameIndexDim; i++)
                {
                    printf("%s\t\t%s\n", name_list[i], number_list[i]);
                }
                printf("press a key to continue...\n");
                getch();
            }
            if (choice == '0')
                break;
            system("cls");
        }
    }
    return 0;
}
