#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct cella
{
    int valore;
    struct cella *next;
};

void creaElemento(struct cella **trct, int num);
void stampaLista(struct cella *t);
int cercaInLista(struct cella *t, int numero);
int eliminaElemento(struct cella **t, int num);
void resetLista(struct cella **t);
struct cella* invertiLista(struct cella *t, struct cella *p);

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
        printf("\n 6 - Inverti la lista (funzione ricorsiva)");
        printf("\n 7 - Esci");
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
                creaElemento(&testa, numero);
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
                count = cercaInLista(testa, numero);
                if (count > 0)
                    printf("\n\n Il valore %d e\' presente in lista nella cella %d\n ", numero, count);
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
                if (eliminaElemento(&testa, numero))
                    printf("\n\n Il valore %d e\' stato eliminato dalla lista\n ", numero);
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
            case '6': //inverti la lista (funzione ricorsiva)
                system("cls");
                if (testa == NULL)
                    printf("\n\n LISTA VUOTA!\n\n ");
                else
                {
                    testa = invertiLista(testa, NULL);
                    printf("\n\n LISTA INVERTITA!\n\n ");
                }
                printf("\n\n");
                system("pause");
                break;
            case '7': //Esci dal programma
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

/* Inverti lista con chiamata ricorsiva */
struct cella* invertiLista(struct cella *t, struct cella *p){
    struct cella *temp;

    if (t == NULL){
        return p;
    }

    temp = invertiLista(t->next, t);
    t->next = p;
    return temp;
}


void resetLista(struct cella **t)
{
    struct cella *temp;

    while (*t != NULL)
    {
        temp = *t;
        *t = (*t)->next;
        free(temp);
    }
}

/*
restituisce 1 se l'elemento è stato eliminato, 0 altrimenti
*/
int eliminaElemento(struct cella **t, int num)
{
    struct cella *prec, *temp;

    temp = *t;
    prec = NULL;

    while (temp != NULL)
    {
        if (temp->valore == num)
        {
            if (prec == NULL)
                *t = (*t)->next;
            else
                prec->next = temp->next;
            free(temp);
            return 1;
        }
        prec = temp;
        temp = temp->next;
    }

    return 0;
}


/*la testa viene passata per valore quindi le modifiche non vengono viste all'esterno
la funzione restituisce la posizione della cella in cui è stato trovato il valore, 0 altrimenti
*/
int cercaInLista(struct cella *t, int numero)
{
    int count = 0;
    while (t != NULL)
    {
        count++;
        if (t->valore == numero)
            return count;
        t = t->next;
    }
    return 0;
}


void stampaLista(struct cella *t)//la testa viene passata per valore quindi le modifiche non vengono viste all'esterno
{
    int count = 0;

    printf("\n");
    if (t == NULL)
    {
        printf(" La lista e\' vuota!\n");
        return;
    }

    while (t != NULL)
    {
        count++;
        printf(" cella %d valore: %d\n", count, t->valore);
        t = t->next;
    }

    printf("\n\n Stampati %d valori\n ", count);
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
