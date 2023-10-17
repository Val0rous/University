#include <stdio.h>
#include <stdlib.h>

typedef struct cella
{
    int valore;
    struct cella *next;
}cella;
typedef cella* p_cella;
cella *testa = NULL; //inizializzazione del puntatore, è importante inizializzare tutte le variabili ad un valore preciso

p_cella pop(p_cella *t);
void push(p_cella *t, int num);
void stampaPila(p_cella *t);
void resetPila(p_cella *t);

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
            printf("\n 3 - Azzera la Pila");
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
                    printf("\n\n Inserisci il valore intero da inserire nella pila: ");
                    fflush(stdin);
                    controllo = scanf("%d",&numero);
                }while(controllo!=1 || numero<0);
                push(&testa,numero);
                printf("\n\n Nuovo elemento creato correttamente!\n\n ");
                system("pause");
                break;
            case '2': //stampa degli elementi in pila
                system("cls");
                printf("\n\n STAMPA VALORI IN PILA\n\n");
                stampaPila(&testa);
                printf("\n\n La pila e\' stata svuotata!\n\n ");
                system("pause");
                break;
            case '3': //azzera pila
                system("cls");
                if (testa == NULL)
                    printf("\n\n PILA VUOTA!\n\n ");
                else
                {
                    resetPila(&testa);
                    printf("\n\n PILA AZZERATA!\n\n ");
                }
                system("pause");
                break;
            case '4': //fine programma
                if (testa != NULL)
                {
                    resetPila(&testa);
                }
                flag = 0;
                break;
        }

    }

    system("pause");
    return 0;
}


void resetPila(p_cella *t)
{
    p_cella temp;

    while (*t != NULL)
    {
        temp = pop(t);
        if (temp != NULL)
            free(temp);
    }

}

void stampaPila(p_cella *t)
{
    p_cella temp;

    printf("\n");
    if (*t == NULL)
    {
        printf(" La pila e\' vuota!\n\n");
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
    } while(*t != NULL);

}

void push(p_cella *t, int num)
{
    p_cella nuovoElemento;

    nuovoElemento = (p_cella)malloc(sizeof(struct cella));
    if (nuovoElemento == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    nuovoElemento->valore = num;
    nuovoElemento->next = *t;
    *t = nuovoElemento;
}

p_cella pop(p_cella *t)
{
    p_cella temp;

    if (*t == NULL)
        return *t;
    temp = *t;
    *t = (*t)->next;
    temp->next = NULL;
    return temp;
}
