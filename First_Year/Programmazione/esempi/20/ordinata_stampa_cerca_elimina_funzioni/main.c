#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#define PULISCI system("cls");
#define PAUSA system("pause");
#define MAXVALPRIORITA 3

/*
Esempio di programma che gestisce liste ordinate.
*/

struct cella
{
    int ordine;
    int ID;
    char nome[51];
    struct cella *next;
};

int inserisciElemento(struct cella **t, char* nomecognome, int priorita);
void stampaLista(struct cella *t);
int cercaInLista(struct cella *t, int numero);
int eliminaElemento(struct cella **t, int num);
void resetLista(struct cella **t);

int IDpaziente = 0; /* Variabile globale per assegnare un ID paziente */

int main()
{
    char opzione;
    char nomecognome[51];
    int count, numero, priorita, flag, controllo, intervallo;
    struct cella *testa;
    testa = NULL; //inizializzazione del puntatore, � importante inizializzare tutte le variabili ad un valore preciso

    flag = 1;
    while (flag)
    {
        system("cls");
        printf("\n\n Seleziona l\'operazione:\n");
        printf("\n 1 - Inserisci nuovo paziente");
        printf("\n 2 - Stampa elenco pazienti");
        printf("\n 3 - Cerca paziente");
        printf("\n 4 - Elimina paziente");
        printf("\n 5 - Azzera la lista pazienti");
        printf("\n 6 - Esci");
        printf("\n\n > ");
        fflush(stdin);
        opzione = getch();
        switch(opzione)
        {
            case '1': //creazione nuovo elemento, vedi esercizio: creazione_lista_semplice_con_un_elemento.c
                PULISCI
                printf("\n\n INSERIMENTO (step 1)");
                printf("\n\n Inserisci nome e cognome del paziente da inserire nella lista: \n");
                controllo = scanf("%50[a-zA-Z ]s",nomecognome);
                fflush(stdin);
                while(controllo != 1)
                {
                    PULISCI
                    printf("\n\n INSERIMENTO (step 1)");
                    printf("\n\n Inserisci nome e cognome del paziente da inserire nella lista: \n");
                    controllo = scanf("%50[a-zA-Z ]s",nomecognome);
                    fflush(stdin);
                }
                PULISCI
                printf("\n\n INSERIMENTO (step 2)");
                printf("\n\n Assegnamento dell'ID (identification number) del paziente: \n");
                IDpaziente = IDpaziente+1;
                printf("\n\n   ID (identification number) del paziente: %d\n", IDpaziente);
//                controllo = scanf("%d",&numero);
//                fflush(stdin);
//                while(numero < 1 || controllo != 1)
//                {
//                    PULISCI
//                    printf("\n\n INSERIMENTO (step 2)");
//                    printf("\n\n Inserisci l'ID (identification number, da 1 a 99) del paziente da inserire nella lista: \n");
//                    controllo = scanf("%d",&numero);
//                    fflush(stdin);
//                }
                PULISCI
                printf("\n\n INSERIMENTO (step 3)");
                printf("\n\n Inserisci l'ordine di priorita\' (da 1 a %d) del paziente da inserire nella lista: \n", MAXVALPRIORITA);
                intervallo = (int)floor(MAXVALPRIORITA/3);
                printf(" (1-%d = Codice Rosso; %d-%d Codice Giallo; %d-%d Codice Bianco) \n", intervallo, intervallo+1, 2*intervallo, 2*intervallo+1, MAXVALPRIORITA);
                controllo = scanf("%d",&priorita);
                fflush(stdin);
                while(priorita < 1 || priorita > MAXVALPRIORITA || controllo != 1)
                {
                    PULISCI
                    printf("\n\n INSERIMENTO (step 3)");
                    printf("\n\n Inserisci l'ordine di priorita\' (da 1 a %d) del paziente da inserire nella lista: \n", MAXVALPRIORITA);
                    printf(" (1-%d = Codice Rosso; %d-%d Codice Giallo; %d-%d Codice Bianco) \n", intervallo, intervallo+1, 2*intervallo, 2*intervallo+1, MAXVALPRIORITA);
                    controllo = scanf("%d",&priorita);
                    fflush(stdin);
                }
                if(inserisciElemento(&testa, nomecognome, priorita))
                {
                    PULISCI
                    printf("\n\n Nuovo paziente inserito correttamente.\n ");
                }
                else
                {
                    PULISCI
                    printf("\n\n Impossibile inserire nuovo paziente.\n ");
                }
                printf("\n\n");
                PAUSA
                break;
            case '2': //stampa degli elementi in lista
                PULISCI
                printf("\n\n STAMPA ELENCO PAZIENTI IN LISTA\n\n");
                stampaLista(testa);
                printf("\n\n");
                PAUSA
                break;
            case '3': //Cerca un elemento nella lista
                PULISCI
                printf("\n\n CERCA PAZIENTE IN LISTA");
                printf("\n\n Inserisci l'ID del paziente da cercare nella lista: \n");
                controllo = scanf("%d",&numero);
                fflush(stdin);
                while(numero < 1 || controllo != 1)
                {
                    PULISCI
                    printf("\n\n CERCA PAZIENTE IN LISTA");
                    printf("\n\n Inserisci l'ID del paziente da cercare nella lista: \n");
                    controllo = scanf("%d",&numero);
                    fflush(stdin);
                }
                count = cercaInLista(testa,numero);
                if (count > 0)
                    printf("\n\n Il paziente %d e\' presente in lista in posizione %d. \n ",numero,count);
                else
                    printf("\n\n Il paziente non e\' presente in lista.\n ");
                printf("\n\n");
                PAUSA
                break;
            case '4': //Elimina un elemento
                PULISCI
                printf("\n\n ELIMINA UN PAZIENTE DALLA LISTA");
                printf("\n Verra\' eliminata la prima occorrenza trovata a partire dalla testa della lista.");
                printf("\n\n Inserisci l'ID del paziente da eliminare nella lista: \n");
                fflush(stdin);
                scanf("%d",&numero);
                if (eliminaElemento(&testa,numero))
                    printf("\n\n Il paziente %d e\' stato eliminato dalla lista. \n",numero);
                else
                    printf("\n\n Il paziente selezionato non e\' presente in lista. \n");
                printf("\n\n");
                PAUSA
                break;
            case '5': //azzera lista
                PULISCI
                if (testa == NULL)
                    printf("\n\n La lista pazienti e\' vuota. \n\n ");
                else
                {
                    resetLista(&testa);
                    printf("\n\n LISTA PAZIENTI AZZERATA!\n\n ");
                }
                printf("\n\n");
                PAUSA
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

    while (*t != NULL)
    {
        temp = *t;
        *t = (*t)->next;
        free(temp);
    }

    IDpaziente = 0; /* Reset variabile globale per assegnare un ID paziente */
}

/*
restituisce 1 se l'elemento � stato eliminato, 0 altrimenti
*/
int eliminaElemento(struct cella **t, int IDpaziente)
{
    struct cella *prec, *temp;

    temp = *t;
    prec = NULL;

    while (temp != NULL)
    {
        if (temp->ID == IDpaziente)
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
int cercaInLista(struct cella *t, int IDpaziente)
{
    int count = 0;
    while (t != NULL)
    {
        count++;
        if (t->ID == IDpaziente)
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
        printf(" La lista pazienti e\' vuota!\n");
        return;
    }

    while (t != NULL)
    {
        count++;
        printf(" - posizione: %d; codice: %d; IDpaziente: %d; paziente: %s; \n", count, t->ordine, t->ID, t->nome);
        t = t->next;
    }

    printf("\n Numero pazienti in lista: %d.\n ",count);
}

/*
viene restituito 1 se l'elemento � stato inserito, 0 se altrimenti
*/
int inserisciElemento(struct cella **t, char* nomecognome, int priorita)
{
    ///////////
    struct cella *prec = NULL;
    struct cella *temp = NULL;
    struct cella *nuovo = NULL;
    nuovo = (struct cella*)malloc(sizeof(struct cella));
    if (nuovo == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n");
        PAUSA
        return 0;
    }
    nuovo->ordine = priorita;
    nuovo->ID = IDpaziente;
    strcpy(nuovo->nome, nomecognome); /* Per fare correttamente: nuovo->nome = nomecognome; */
    nuovo->next = NULL;

    if (*t == NULL) //lista vuota
        *t = nuovo;
    else
    {
        prec = NULL;
        temp = *t;
        while (temp != NULL)
        {
            if (temp->ordine > nuovo->ordine) //trovata la cella con valore pi� grande
            {
                nuovo->next = temp;
                if (prec == NULL) // se l�elemento � da inserire in testa
                {
                    *t = nuovo;
                    nuovo->next = temp;
                }
                else
                {
                    prec->next = nuovo;
                    nuovo->next = temp;
                }
                break;
            }
            prec = temp;
            temp = temp->next;
        }

        if (temp == NULL) //il nuovo elemento non � stato inserito e siamo in fondo alla lista
        {
            prec->next = nuovo;
            nuovo->next = temp;
        }
    }
    return 1;
}
