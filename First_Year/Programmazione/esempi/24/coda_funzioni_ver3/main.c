#include <stdio.h>
#include <stdlib.h>

struct cella
{
    int valore;
    struct cella *next;
};

struct coda
{
	struct cella *primo; //o anche testa
	struct cella *ultimo; //o anche coda
};
typedef struct coda coda;

struct cella* pop(coda *t);
void push(coda *t, int num);
void stampaCoda(coda *t);
void resetCoda(coda *t);

int main()
{

    coda Coda1;
    Coda1.primo  = NULL;
    Coda1.ultimo = NULL;

    char opzione;
    int numero, flag, controllo;

    flag = 1;
    while(flag)
    {
        do
        {
            system("cls");
            printf("\n\n Seleziona l\'operazione:\n");
            printf("\n 1 - Inserisci nuovo elemento");
            printf("\n 2 - Stampa elenco elementi");
            printf("\n 3 - Azzera");
            printf("\n 4 - Esci");
            printf("\n\n > ");
            fflush(stdin);
            controllo = scanf("%c",&opzione);
        }while(controllo!=1);
        switch(opzione)
        {
            case '1':
                do
                {
                    system("cls");
                    printf("\n\n INSERIMENTO");
                    printf("\n\n Inserisci il valore intero da inserire: ");
                    fflush(stdin);
                    controllo = scanf("%d",&numero);
                }while(controllo!=1 || numero<0);
                push(&Coda1,numero);
                printf("\n\n Nuovo elemento creato correttamente!\n\n ");
                system("pause");
                break;
            case '2': //stampa degli elementi
                system("cls");
                printf("\n\n STAMPA VALORI IN CODA\n\n");
                if ((&Coda1)->primo == NULL)
                    printf("\n\n CODA VUOTA!\n\n ");
                else
                {
                    stampaCoda(&Coda1);
                    printf("\n\n La coda e\' stata svuotata!\n\n ");
                }
                system("pause");
                break;
            case '3': //azzera
                system("cls");
                if ((&Coda1)->primo == NULL)
                    printf("\n\n CODA VUOTA!\n\n ");
                else
                {
                    resetCoda(&Coda1);
                    printf("\n\n CODA AZZERATA!\n\n ");
                }
                system("pause");
                break;
            case '4': //fine programma
                if ((&Coda1)->primo != NULL)
                {
                    resetCoda(&Coda1);
                }
                flag = 0;
                break;
        }

    }

    system("pause");
    return 0;
}


void resetCoda(coda *t)
{
    struct cella *temp;

    while ((*t).primo != NULL)
    {
        temp = pop(t);
        if (temp != NULL)
            free(temp);
    }

}

void stampaCoda(coda *t)
{
    struct cella *temp;

    printf("\n");
    if ((*t).primo == NULL)
    {
        printf(" La coda e\' vuota!\n\n");
        return;
    }

    do
    {
        temp = pop(t);
        if (temp != NULL)
        {
            printf(" valore: %d\n",temp->valore);
            free(temp);
        }
    } while((*t).primo != NULL);

}

void push(coda *t, int num)
{
    struct cella * nuovo;

    nuovo = (struct cella*)malloc(sizeof(struct cella));
    if (nuovo == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    nuovo->valore = num;
    nuovo->next = NULL;

    if ((*t).primo == NULL){
        (*t).primo = nuovo;
    } else{
        (*t).ultimo->next = nuovo;
    }
    (*t).ultimo = nuovo;
}

struct cella* pop(coda *t)
{
    struct cella *temp;

    //Empty
    if ((*t).primo == NULL){
        return (*t).primo;
    }

    //Just one element
    if ((*t).primo->next == NULL){
        temp = (*t).primo;
        (*t).primo = NULL;
        (*t).ultimo = NULL;
        return temp;
    }

    //Other cases
    temp = (*t).primo;
    (*t).primo = (*t).primo->next;
    temp->next = NULL;
    return temp;
}
