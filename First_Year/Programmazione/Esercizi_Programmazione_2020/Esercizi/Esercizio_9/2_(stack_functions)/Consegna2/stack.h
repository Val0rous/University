#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//defining struct stack with int values
typedef struct cell_s
{
    int value;
    struct cell_s *next;
}cell_t;


//functions for linked structures
void pushLnkStrc(cell_t **t, int num);

cell_t* popLnkStrc(cell_t **t);

int isEmptyLnkStrc(cell_t **t);

void printLnkStrc(cell_t **t);

void deleteAllLnkStrc(cell_t **t);

cell_t* topLnkStrc(cell_t **t);

//function for arrays

int popArray(int*stack,int*pos);

int pushArray(int*stack,int*pos,int number, int dimension);

void printArray(int *stack,int pos);

void resetArray(int* pos);
#endif // STACK_H_INCLUDED
