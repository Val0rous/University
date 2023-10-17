#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

/*
AUTHORS:    Leonardo    Tassinari:  leonardo.tassinari6@studio.unibo.it
            Filippo     Fuzzi:      filippo.fuzzi2@studio.unibo.it
            Lorenzo     Prati:      lorenzo.prati3@studio.unibo.it
            Francesco   Valentini:  francesco.valentin11@studio.unibo.it

DATE: 2020/12/17
Scrivere un programma contenente tutte le funzioni di gestione del tipo di dato astratto PILA,
implementato sia tramite allocazione indicizzata (vettore statico e vettore dinamico) sia tramite strutture collegate.
Il programma deve visualizzare lo stato della pila ad inizio esecuzione (vuota) e dopo ogni operazione scelta dall'utente.
er la visualizzazione creare una funzione di appoggio in cui gli elementi letti non vengono eliminati.
Consegnare un file .zip contente un progetto che comprenda tutti i file necessari per headre il programma.
*/
int main()
{
    //main menu to chose the type of stack
    char answer='\0';
    while(1)
    {
        printf("Choose the type of stack:\n1)Linked structures\n2)static array\n3)dynamic array\n");
        answer=getch();
        if(answer=='1'||answer=='2'||answer=='3')break;
    }
    //Linked structures
    if (answer=='1')
    {

        //initialize head
        cell_t *head = NULL;

        //menu
        char option;
        int number, flag, check;

        flag = 1;
        while(flag)
        {
            do
            {
                system("cls");
                printf("Actual situation:\n");
                printLnkStrc(&head);
                printf("\nChoose the operation:\n");
                printf("\n 0 - Pop");
                printf("\n 1 - Push");
                printf("\n 2 - Print stack (without delete)");
                printf("\n 3 - Reset stack");
                printf("\n 4 - Exit");
                printf("\n\n > ");
                fflush(stdin);
                check = scanf("%c",&option);
            }
            while(check!=1);
            switch(option)
            {
            case '0':
            {
                //pop
                cell_t *temp = NULL;    //new temp pointer
                system("cls");
                printf("Pop");
                temp=popLnkStrc(&head); //temp equal extracted node
                if(temp!=NULL)  //check if the stack is empty
                {
                    printf("\nValue last element:%d\n(It has been deleted)\n",temp->value);
                    free(temp);
                }   //if is empty
                else  printf("The stack is empty\n");
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
            }
            break;
            case '1':
                //push
                do
                {
                    //ask for value
                    system("cls");
                    printf("Push");
                    printf("\n\n Insert the integer value to put on the stack: ");
                    fflush(stdin);
                    check = scanf("%d",&number);
                }
                while(check!=1 || number<0);
                pushLnkStrc(&head,number); //call function
                printf("\n\n new element added correctly!\n\n ");
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '2': //print stack
                system("cls");
                printf("\n\n Print Stack\n\n");
                printLnkStrc(&head);//call function
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '3': //reset stack
                system("cls");
                if (head == NULL)//check if stack is empty
                    printf("\n\n The stack is already empty!\n\n ");
                else
                {
                    deleteAllLnkStrc(&head);
                    printf("\n\n Stack flushed!\n\n ");
                }
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '4': //exit
                if (head != NULL)
                {
                    deleteAllLnkStrc(&head);//reset stack
                }
                flag = 0;
                break;
            }

        }
    }
    //STATIC ARRAY SELECTION
    if (answer=='2')
    {
        int dimensions=0;//to keep track of the dimesion
        while(1)//ask user the fixed dimension
        {
            system("cls");
            printf("type the maximum dimension of the array:");
            if(scanf("%d",&dimensions)&&dimensions>0&&dimensions<3000)break;
            fflush(stdin);
        }
        fflush(stdin);
        //initialize stack and position
        int stack[dimensions];
        int pos=-1;


        //print menu
        char option;
        int number, flag, check;

        flag = 1;
        while(flag)
        {
            do
            {
                system("cls");
                printf("Actual situation:\n");
                printArray(stack,pos);
                printf("\nChoose the operation:\n");
                printf("\n 0 - Pop");
                printf("\n 1 - Push");
                printf("\n 2 - Print stack (without delete)");
                printf("\n 3 - Reset stack");
                printf("\n 4 - Exit");
                printf("\n\n > ");
                fflush(stdin);
                check = scanf("%c",&option);
            }
            while(check!=1);
            switch(option)
            {
            case '0':
            {
                system("cls");
                printf("Pop\n");
                if(pos>-1) //double check the array is not empty(also inside the pop function)
                {
                    printf("\nValue last element:%d\n(It has been deleted)\n",popArray(stack,&pos));//show pop
                }
                else  printf("The stack is empty\n");
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
            }
            break;
            case '1':
                if(pos<dimensions)//double check if it's full
                {
                    do//ask user for the value
                    {
                        system("cls");
                        printf("Push");
                        printf("\n\n Insert the integer value to put on the stack: ");
                        fflush(stdin);
                        check = scanf("%d",&number);
                    }
                    while(check!=1 || number<0);
                    if (pushArray(stack,&pos,number,dimensions)==1)//call the function
                        printf("\n\n new element added correctly!\n\n ");
                    else printf("\n\n The stack is full or there's an error!\n\n ");//if return is an arror
                }
                else printf("\n\n The stack is full!\n\n ");
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '2': //print stack
                system("cls");
                printf("Print Stack\n\n");
                printArray(stack,pos);//call function
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '3': //reset stack
                system("cls");
                if (pos<0)//check if it's empty
                    printf("\n\n The stack is already empty!\n\n ");
                else
                {
                    resetArray(&pos);//call function
                    printf("\n\n Stack flushed!\n\n ");
                }
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '4': //exit
                flag = 0;
                break;
            }

        }
    }
    //DYNAMIC ARRAY (only differences will be commented)
    if (answer=='3')
    {
        int dimensions=0;
        while(1)
        {
            system("cls");
            printf("type the initial dimension of the array:");
            if(scanf("%d",&dimensions)&&dimensions>0&&dimensions<3000)break;
            fflush(stdin);
        }
        fflush(stdin);
        //initializing array with malloc
        int *stack=(int*)malloc(sizeof(int)*dimensions);
        if(stack==NULL)exit(1);
        int pos=-1;



        char option;
        int number, flag, check;

        flag = 1;
        while(flag)
        {
            do
            {
                system("cls");
                printf("Actual situation:\n");
                printArray(stack,pos);
                printf("\nChoose the operation:\n");
                printf("\n 0 - Pop");
                printf("\n 1 - Push");
                printf("\n 2 - Print stack (without delete)");
                printf("\n 3 - Reset stack");
                printf("\n 4 - Exit");
                printf("\n\n > ");
                fflush(stdin);
                check = scanf("%c",&option);
            }
            while(check!=1);
            switch(option)
            {
            case '0':
            {
                system("cls");
                printf("Pop\n");
                if(pos>-1)
                {
                    printf("\nValue last element:%d\n(It has been deleted)\n",popArray(stack,&pos));
                }
                else  printf("The stack is empty\n");
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
            }
            break;
            case '1':
                if(pos<dimensions)
                {
                    do
                    {
                        system("cls");
                        printf("Push");
                        printf("\n\n Insert the integer value to put on the stack: ");
                        fflush(stdin);
                        check = scanf("%d",&number);
                    }
                    while(check!=1 || number<0);
                    if (pushArray(stack,&pos,number,dimensions)==1)
                        printf("\n\n new element added correctly!\n\n ");
                    else printf("\n\n The stack is full or there's an error!\n\n ");
                }
                else  //if the stack was full print error and realloc with double dimension (just to show we did the realloc)
                {
                    dimensions*=2;
                    stack=(int*) realloc(stack,dimensions*sizeof(int));
                    printf("\n\n The stack was full! it has been expanded, try again\n\n ");
                }
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '2':
                system("cls");
                printf("Print Stack\n\n");
                printArray(stack,pos);
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '3':
                system("cls");
                if (pos<0)
                    printf("\n\n The stack is already empty!\n\n ");
                else
                {
                    resetArray(&pos);
                    printf("\n\n Stack flushed!\n\n ");
                }
                printf("Press return to continue...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                break;
            case '4':
                flag = 0;
                break;
            }

        }
        free(stack);//free of the stack
    }
    return 0;
}
