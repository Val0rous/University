/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/11/15
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
#include <windows.h>

#define MAX_ENTRIES 100        //define maximum number of contacts
#define MAX_TEL_NUM_LENGTH 20  //define maximum dimension for number string
#define MAX_TEL_NAME_LENGTH 50 //define maximum dimension for name string
#define TIME_SLEEP 500         //define sleep time

int main()
{                //first, menu to choose wich version to use
    char jagged; //to store the answer

    //user choice with getch()
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

    //if not jagged
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
                    fgets(tempName, MAX_TEL_NAME_LENGTH, stdin); //Max name length is 20 digits
                    tempName[strlen(tempName) - 1] = '\0';       //remoove the new line character
                    fflush(stdin);
                    //conver all to capital
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
                Sleep(TIME_SLEEP);
            }
            if (choice == '2')
            {
                system("cls");
                char tempName[MAX_TEL_NAME_LENGTH + 1];
                printf("Type the exact name of the contact to search:\n");
                fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                tempName[strlen(tempName) - 1] = '\0';      //store user request
                for (int j = 0; j <= strlen(tempName); j++) //make it capital
                {
                    tempName[j] = toupper(tempName[j]);
                }
                fflush(stdin);
                int found = 0;

                for (int i = 0; i <= nameIndexDim; i++) //scan main array with strcmp()
                {
                    if (strcmp(name_list[i], tempName) == 0)
                    {
                        found++;
                        printf("%s\t\t%s\n", name_list[i], number_list[i]); //if found, show
                    }
                }
                if (!found)
                {
                    printf("No items found\n"); //if not
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
                fflush(stdin); //get user request and make it capital
                int found = 0;
                for (int i = 0; i <= nameIndexDim; i++) //search it in main array with strstr() and show what found
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
                for (int i = 0; i <= nameIndexDim; i++) //print entire array
                {
                    printf("%s\t\t%s\n", name_list[i], number_list[i]);
                }
                printf("press a key to continue...\n");
                getch();
            }

            if (choice == '0') //exit
                break;
            system("cls");
        }
    }
    //if jagged, only differencies recommented!

    else if (jagged == '1')
    {
        //Contacts name list
        char *name_list[MAX_ENTRIES]; //this time with pointers
        //Array index dimension
        int nameIndexDim = -1;
        //Contacts phone number list
        char *number_list[MAX_ENTRIES];
        //Array index dimension
        int numberIndexDim = -1;

        printf("Welcome to the contacts app! What can I help you with?\n");

        while (1)
        {
            char choice;
            printf("1) Add a new entry\n");
            printf("2) Search by name (exact search)\n");
            printf("3) Search by name (approximate search)\n");
            printf("4) Print complete contact list\n");
            printf("0) Close the program\n\n");

            while (1)
            {
                choice = getch();

                if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '0')
                    break;

                printf("Error: wrong input. Please try again\a\n\n");
            }

            if (choice == '1')
            {
                system("cls");

                if (nameIndexDim < MAX_ENTRIES)
                {
                    char tempName[MAX_TEL_NAME_LENGTH + 1];
                    printf("Type the name of the contact:\n");
                    fgets(tempName, MAX_TEL_NAME_LENGTH, stdin);
                    tempName[strlen(tempName) - 1] = '\0';
                    fflush(stdin);

                    for (int j = 0; j <= strlen(tempName); j++)
                    {
                        tempName[j] = toupper(tempName[j]);
                    }
                    int good = 1;

                    for (int i = 0; i <= nameIndexDim; i++)
                    {
                        if (strcmp(name_list[i], tempName) == 0)
                            good = 0;
                    }
                    //DIFFERENCIES!!!!!
                    if (good == 1)
                    {
                        char *pTempName = (char *)malloc(sizeof(tempName)); //create space for the string
                        if (!pTempName)
                            exit(-1);                          //check if space is created or crash
                        strcpy(pTempName, tempName);           //save the string into the space
                        name_list[++nameIndexDim] = pTempName; //add it to the array

                        char tempNum[MAX_TEL_NUM_LENGTH + 1];
                        printf("Type the corresponding number:\n"); //ask corresponding number and save it
                        fgets(tempNum, MAX_TEL_NUM_LENGTH, stdin);
                        tempName[strlen(tempName) - 1] = '\0';
                        fflush(stdin);
                        char *pTempNum = (char *)malloc(sizeof(tempNum));
                        if (!pTempNum)
                            exit(-1);
                        strcpy(pTempNum, tempNum);
                        number_list[++numberIndexDim] = pTempNum;

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
                Sleep(TIME_SLEEP);
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
        //free the malloc with the pointers of the main array
        for (int i = 0; i <= nameIndexDim; i++)
        {
            free(name_list[i]);
            free(number_list[i]);
        }
    }
    return 0;
}
