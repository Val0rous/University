#include <stdio.h>
#include <stdlib.h>

struct cella
{
    int valore;
    struct cella *next;
};

struct cella *testa = NULL; //puntatore al primo elemento
struct cella *coda = NULL; //puntatore all’ultimo elemento

struct cella* pop(struct cella **te, struct cella **co);
void push(struct cella **te, struct cella **co, int num);
void stampaCoda(struct cella **te, struct cella **co);
void resetCoda(struct cella **te, struct cella **co);

int main()
{

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
                push(&testa, &coda, numero);
                printf("\n\n Nuovo elemento creato correttamente!\n\n ");
                system("pause");
                break;
            case '2': //stampa degli elementi
                system("cls");
                printf("\n\n STAMPA VALORI IN CODA\n\n");
                if (testa == NULL)
                    printf("\n\n CODA VUOTA!\n\n ");
                else
                {
                    stampaCoda(&testa, &coda);
                    printf("\n\n La coda e\' stata svuotata!\n\n ");
                }
                system("pause");
                break;
            case '3': //azzera
                system("cls");
                if (testa == NULL)
                    printf("\n\n CODA VUOTA!\n\n ");
                else
                {
                    resetCoda(&testa, &coda);
                    printf("\n\n CODA AZZERATA!\n\n ");
                }
                system("pause");
                break;
            case '4': //fine programma
                if (testa != NULL)
                {
                    resetCoda(&testa, &coda);
                }
                flag = 0;
                break;
        }

    }

    system("pause");
    return 0;
}


void resetCoda(struct cella **te, struct cella **co)
{
    struct cella *temp;

    while (*te != NULL)
    {
        temp = pop(te, co);
        if (temp != NULL)
            free(temp);
    }

}

void stampaCoda(struct cella **te, struct cella **co)
{
    struct cella *temp;

    printf("\n");
    if (te == NULL)
    {
        printf(" La coda e\' vuota!\n\n");
        return;
    }

    do
    {
        temp = pop(te, co);
        if (temp != NULL)
        {
            printf(" valore: %d\n",temp->valore);
            free(temp);
        }
    } while(*te != NULL);

}

void push(struct cella **te, struct cella **co, int num)
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

    if (*te == NULL){
        *te = nuovo;
    } else{
        (*co)->next = nuovo;
    }
    *co = nuovo;
}

struct cella* pop(struct cella **te, struct cella **co)
{
    struct cella *temp;

    if (*te == NULL){
        *co = NULL;
        return *te;
    }
    temp = *te;
    *te = (*te)->next;
    if (*te == NULL){
        *co = NULL;
    }
    temp->next = NULL;
    return temp;
}
