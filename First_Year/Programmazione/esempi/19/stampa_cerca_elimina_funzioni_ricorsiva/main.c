#include <stdio.h>
#include <stdlib.h>
stampa_cerca_elimina_funzioni_ricorsiva

/*
funzioni ricorsive
*/

struct cella
{
    int valore;
    struct cella *next;
};

void creaElemento(struct cella **t, int num);
void stampaLista(struct cella *t);
void _stampaLista(struct cella *t, int *count);
int cercaInLista(struct cella *t, int numero);
int eliminaElemento(struct cella **t, int num);
int _eliminaElemento(struct cella **t, struct cella *p, int num);
void resetLista(struct cella **t);

int main()
{
    char opzione;
    int count, numero, flag;
    struct cella *testa;
    testa = NULL; //inizializzazione del puntatore, è importante inizializzare tutte le variabili ad un valore preciso

    flag = 1;
    while (flag)
    {
        system("cls");
        printf("\n\n Seleziona l\'operazione:\n");
        printf("\n 1 - Inserisci nuovo elemento");
        printf("\n 2 - Stampa elenco elementi");
        printf("\n 3 - Cerca elemento");
        printf("\n 4 - Elimina elemento");
        printf("\n 5 - Azzera la lista");
        printf("\n 6 - Esci");
        printf("\n\n > ");
        fflush(stdin);
        opzione = getch();
        switch(opzione)
        {
            case '1': //creazione nuovo elemento, vedi esercizio: creazione_lista_semplice_con_un_elemento.c
                system("cls");
                printf("\n\n INSERIMENTO");
                printf("\n\n Inserisci il valore intero da inserire nella lista: ");
                scanf("%d",&numero);
                fflush(stdin);
                creaElemento(&testa,numero);
                printf("\n\n Nuovo elemento creato correttamente!\n ");
                printf("\n\n");
                system("pause");
                break;
            case '2': //stampa degli elementi in lista
                system("cls");
                printf("\n\n STAMPA VALORI IN LISTA\n\n");
                stampaLista(testa);
                printf("\n\n");
                system("pause");
                break;
            case '3': //Cerca un elemento nella lista
                system("cls");
                printf("\n\n CERCA VALORE IN LISTA");
                printf("\n\n Inserisci il valore da cercare nella lista: ");
                fflush(stdin);
                scanf("%d",&numero);
                count = cercaInLista(testa,numero);
                if (count > 0)
                    printf("\n\n Il valore %d e\' presente in lista nella cella %d\n ",numero,count);
                else
                    printf("\n\n Il valore selezionato NON e\' presente in lista\n ");
                printf("\n\n");
                system("pause");
                break;
            case '4': //Elimina un elemento
                system("cls");
                printf("\n\n ELIMINA VALORE IN LISTA");
                printf("\n verra\' eliminata la prima occorrenza trovata a partire dalla testa");
                printf("\n\n Inserisci il valore da eliminare nella lista: ");
                fflush(stdin);
                scanf("%d",&numero);
                if (eliminaElemento(&testa,numero))
                    printf("\n\n Il valore %d e\' stato eliminato dalla lista\n ",numero);
                else
                    printf("\n\n Il valore selezionato NON e\' presente in lista\n ");
                printf("\n\n");
                system("pause");
                break;
            case '5': //azzera lista
                system("cls");
                if (testa == NULL)
                    printf("\n\n LISTA VUOTA!\n\n ");
                else
                {
                    resetLista(&testa);
                    printf("\n\n LISTA AZZERATA!\n\n ");
                }
                printf("\n\n");
                system("pause");
                break;
            case '6': //Esci dal programma
                flag = 0;
                break;
        }

    }

    /* free of the list */
    if (testa != NULL){
        resetLista(&testa);
    }

    return 0;
}


void resetLista(struct cella **t)
{
    struct cella *temp;

    if (*t == NULL)
        return;

    temp = *t;
    *t = (*t)->next;
    resetLista(t);
    free(temp);
}

/*
restituisce 1 se l'elemento è stato eliminato, 0 altrimenti
*/
int eliminaElemento(struct cella **t, int num)
{
    return _eliminaElemento(t,NULL,num);
}

int _eliminaElemento(struct cella **t, struct cella *p, int num)
{
    struct cella *temp;

    if (*t == NULL)
        return 0;

    if ((*t)->valore == num)
    {
        temp = *t;
        if (p == NULL)
            *t = (*t)->next;
        else
            p->next = (*t)->next;
        free(temp);
        return 1;
    }
    else
        return _eliminaElemento(&((*t)->next),p,num);
}


/*la testa viene passata per valore quindi le modifiche non vengono viste all'esterno
la funzione restituisce la posizione della cella in cui è stato trovato il valore, 0 altrimenti
*/
int cercaInLista(struct cella *t, int numero)
{
    int temp;
    static int count = 0;

    if (t == NULL)
        return 0;

    count++;
    if (t->valore == numero)
    {
        temp = count;
        count = 0;
        return temp;
    }

    return cercaInLista(t->next,numero);
}

void stampaLista(struct cella *t)//la testa viene passata per valore quindi le modifiche non vengono viste all'esterno_
{
    int count = 0;
    if (t == NULL)
    {
        printf("\n\n La lista e\' vuota");
        return;
    }
    _stampaLista(t,&count);
    printf("\n\n Stampati %d valori\n ",count);
}

void _stampaLista(struct cella *t, int *count)
{
    if (t == NULL)
        return;
    (*count)++;
    printf(" cella %d valore: %d\n",*count,t->valore);
    _stampaLista(t->next,count);
}

void creaElemento(struct cella **t, int num)
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
    nuovoElemento->next = *t;
    *t = nuovoElemento;
}
