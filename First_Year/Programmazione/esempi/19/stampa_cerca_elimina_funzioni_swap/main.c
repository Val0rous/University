#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
implementata la funzione per lo swap di elementi

un elemento viene inserito se non � gi� presente
*/

struct cella
{
    int valore;
    struct cella *next;
};

int creaElemento(struct cella **t, int num);
void stampaLista(struct cella *t);
int cercaInLista(struct cella *t, int numero);
int eliminaElemento(struct cella **t, int num);
void resetLista(struct cella **t);
int swap(struct cella **t, int numero1, int numero2);

int main()
{
    char opzione;
    int count, numero, num1, num2, flag;
    struct cella *testa;
    testa = NULL; //inizializzazione del puntatore, � importante inizializzare tutte le variabili ad un valore preciso

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
        printf("\n 6 - Swap di due celle in lista");
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
                if(creaElemento(&testa,numero))
                    printf("\n\n Nuovo elemento creato correttamente!\n ");
                else
                    printf("\n\n Elemento presente, impossibile inserire!\n ");
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
            case '6': //azzera lista
                system("cls");
                printf("\n\n SWAP DI DUE CELLE\n\n ");
                if (testa == NULL)
                    printf("\n\n LISTA VUOTA!\n\n ");
                else
                {
                    printf("\n\n Inserisci primo valore: ");
                    fflush(stdin);
                    scanf("%d",&num1);
                    printf("\n Inserisci secondo valore: ");
                    fflush(stdin);
                    scanf("%d",&num2);
                    if(swap(&testa,num1,num2))
                        printf("\n\n Swap completato!\n\n ");
                    else
                        printf("\n\n Una delle due celle non e\' stata trovata!\n\n ");
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
restituisce 1 se l'elemento � stato eliminato, 0 altrimenti
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
la funzione restituisce la posizione della cella in cui � stato trovato il valore, 0 altrimenti
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
        printf(" cella %d valore: %d\n",count,t->valore);
        t = t->next;
    }

    printf("\n\n Stampati %d valori\n ",count);
}

/*
viene restituito 1 se l'elemento � stato inserito, 0 se l'elemento � gi� presente in lista
*/
int creaElemento(struct cella **t, int num)
{
    struct cella *nuovoElemento;

    if (cercaInLista(*t,num) == 0)
    {
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
        return 1;
    }
    else
        return 0;
}
/*
scambio di due celle
*/
int swap(struct cella **t, int numero1, int numero2)
{
    struct cella *ptr1, *ptr2;
    struct cella *prec1, *prec2;
    struct cella *temp;
    int find2;

    if (*t == NULL)
        return 0;

    prec1 = NULL;
    prec2 = NULL;

    ptr1 = *t;
    while (ptr1 != NULL)
    {
        if (ptr1->valore == numero1 || ptr1->valore == numero2)
            break;
        prec1 = ptr1;
        ptr1 = ptr1->next;
    }

    if (ptr1 == NULL) //elemento non trovato
        return 0;

    //se arriviamo qui in ptr1 c'� il riferimento al primo valore trovato
    if (ptr1->valore == numero1)
        find2 = numero2;
    else
        find2 = numero1;

    prec2 = ptr1;
    ptr2 = ptr1->next;
    while (ptr2 != NULL)
    {
        if (ptr2->valore == find2)
            break;
        prec2 = ptr2;
        ptr2 = ptr2->next;
    }

    if (ptr2 == NULL || prec2 == NULL) //elemento non trovato
        return 0;

    if (prec1 == NULL)  //Element is in head
        *t = ptr2;
    else
        prec1->next = ptr2;

    temp = ptr2->next;
    if (prec2 != ptr1)  //If elements are not consecutive
    {
        ptr2->next = ptr1->next;
        prec2->next = ptr1;
    }
    else
        ptr2->next = ptr1;
    ptr1->next = temp;

    return 1;
}
