#include <stdio.h>
#include <stdlib.h>

struct cella
{
    int valore;
    struct cella *next;
};
struct cella *testa = NULL; //inizializzazione del puntatore, è importante inizializzare tutte le variabili ad un valore preciso

struct cella* pop(struct cella **t);
struct cella* push(struct cella *t, int num);
struct cella* stampaPila(struct cella *t);
struct cella* resetPila(struct cella *t);

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
                testa = push(testa,numero);
                printf("\n\n Nuovo elemento creato correttamente!\n\n ");
                system("pause");
                break;
            case '2': //stampa degli elementi in pila
                system("cls");
                printf("\n\n STAMPA VALORI IN PILA\n\n");
                testa = stampaPila(testa);
                printf("\n\n La pila e\' stata svuotata!\n\n ");
                system("pause");
                break;
            case '3': //azzera pila
                system("cls");
                if (testa == NULL)
                    printf("\n\n PILA VUOTA!\n\n ");
                else
                {
                    testa = resetPila(testa);
                    printf("\n\n PILA AZZERATA!\n\n ");
                }
                system("pause");
                break;
            case '4': //fine programma
                if (testa != NULL)
                {
                    testa= resetPila(testa);
                }
                flag = 0;
                break;
        }

    }

    system("pause");
    return 0;
}


struct cella* resetPila(struct cella *t)
{
    struct cella *temp;

    while (t != NULL)
    {
        temp = pop(&t);
        if (temp != NULL)
            free(temp);
    }
    temp = NULL;
    return temp;
}

struct cella* stampaPila(struct cella *t)
{
    struct cella *temp;

    printf("\n");
    if (t == NULL)
    {
        printf(" La pila e\' vuota!\n\n");
        return t;
    }

    do
    {
        temp = pop(&t);
        if (temp != NULL)
        {
            printf(" valore: %d\n",temp->valore);
            free(temp);
        }
    } while(t != NULL);
    return t;
}

struct cella* push(struct cella *t, int num)
{
    struct cella *nuovoElemento;

    nuovoElemento = (struct cella*)malloc(sizeof(struct cella));
    if (nuovoElemento == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    nuovoElemento->valore = num;
    nuovoElemento->next = t;
    return nuovoElemento;
}

struct cella* pop(struct cella **t)
{
    struct cella *temp;

    if (*t == NULL)
        return *t;
    temp = *t;
    *t = (*t)->next;
    temp->next = NULL;
    return temp;
}
