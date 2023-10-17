#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

//LINKED STRUCTURES FUNCTIONS
void pushLnkStrc(cell_t **t, int num) //push
{
    cell_t *newElement = (cell_t*)malloc(sizeof(cell_t));//malloc space
    if (newElement == NULL)//check error
    {
        printf("\n\n Error in malloc!\n ");
        system("pause");
        exit(1);
    }
    newElement->value = num;//set value
    newElement->next = *t;//set next to previous head
    *t = newElement;//update head
}

cell_t* popLnkStrc(cell_t **t) //pop IT HAS TO BE FREED WHEN CALLED
{
    cell_t *temp;//tep pointer

    if (*t == NULL)//check if stack is empty
        return *t;
    temp = *t;//set temp=head
    *t = (*t)->next;//update head
    temp->next = NULL;//detach extracted element
    return temp; //return extracted element
}

int isEmptyLnkStrc(cell_t **t) //check if it is empty
{
    return (*t==NULL);
}

cell_t* topLnkStrc(cell_t **t) //check top without deleting
{
    return (*t);
}

void printLnkStrc(cell_t **t) //print linked structure
{
    if(*t==NULL) printf("the stack is empty\n");//check if it's empty
    else
    {
        int i=1;
        for(cell_t *cursor=*t; cursor!=NULL; cursor=cursor->next)//for each node
        {
            printf("elem:%d value:%d\n",i,cursor->value);       //print node
            i++;
        }
    }
}

void deleteAllLnkStrc(cell_t **t)   //delete list
{
    for(cell_t *cursor=*t; cursor!=NULL; )//for each element
    {
        cell_t * del=cursor;//temp pointer
        cursor=cursor->next;//next cursor cursor
        free((popLnkStrc(&del)));//free pointer
    }
    *t=NULL;    //reset head
}

//STATIC ARRAY STACK

int popArray(int*stack,int*pos) //pop
{
    if(pos<0)return -1; //if empty return -1
    else
    {
        (*pos)--;//decrease position
        return stack[(*pos)+1]; //return previous element
    }

}
int pushArray(int*stack,int*pos,int number, int dimension) //push
{
    if (*pos<dimension)//check if full (return -1)
    {
        (*pos)=(*pos)+1;//increase position
        stack[*pos]=number; //assign value
        return 1; //return 1 to confirm assignment
    }
    else return -1;
}

void printArray(int *stack,int pos) //print entire stack without delete
{
    if(pos<0)   printf("The stack is empty\n"); //check if empty
    else
    {
        for(int i=0; i<=pos; i++) //for each element
        {
            printf("element %d, value:%d\n",i+1,stack[pos-i]); //print value
        }
    }
}

void resetArray(int* pos) //reset array
{
    *pos=-1; //set position to empty
}
