#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct cella
{
    int valore;
    struct cella *next;
};

int main()
{
    char opzione;
    int trovato;
    int numero, count, flag;
    struct cella *testa;
    struct cella *nuovoElemento;
    struct cella *temp; //puntatore temporaneo per scorrere la lista e non perdere il riferimento alla testa
    struct cella *prec;
    testa = NULL; //inizializzazione del puntatore, e\' importante inizializzare tutte le variabili ad un valore preciso

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
                nuovoElemento = (struct cella*)malloc(sizeof(struct cella));
                if (nuovoElemento == NULL)
                {
                    printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
                    system("pause");
                    exit(1);
                }
                nuovoElemento->valore = numero;
                nuovoElemento->next = testa;
                testa = nuovoElemento;
                printf("\n\n Nuovo elemento creato correttamente!\n ");
                printf("\n\n");
                system("pause");
                break;
            case '2': //stampa degli elementi in lista
                system("cls");
                printf("\n\n STAMPA VALORI IN LISTA\n\n");
                temp = testa; //puntatore temporaneo per scorrere la lista e non perdere il riferimento alla testa
                count = 0;
                while (temp != NULL)
                {
                    printf(" cella %d valore: %d\n",(count+1),temp->valore);
                    temp = temp->next;
                    count++;
                }
                printf("\n\n Stampati %d valori\n ",count);
                printf("\n\n");
                system("pause");
                break;
            case '3': //Cerca un elemento nella lista
                system("cls");
                printf("\n\n CERCA VALORE IN LISTA");
                printf("\n\n Inserisci il valore da cercare nella lista: ");
                fflush(stdin);
                scanf("%d",&numero);
                trovato = 0;
                temp = testa; //puntatore temporaneo per scorrere la lista e non perdere il riferimento alla testa
                count = 0;
                while (temp != NULL)
                {
                    count++;
                    if (temp->valore == numero)
                    {
                        trovato = 1;
                        break;
                    }
                    temp = temp->next;
                }
                if (trovato)
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
                trovato = 0;
                temp = testa; //puntatore temporaneo per scorrere la lista e non perdere il riferimento alla testa
                prec = NULL;
                while (temp != NULL)
                {
                    if (temp->valore == numero)
                    {
                        if (prec == NULL)
                            testa = testa->next;
                        else
                            prec->next = temp->next;
                        free(temp);
                        trovato = 1;
                        break;
                    }
                    prec = temp;
                    temp = temp->next;
                }
                if (trovato)
                    printf("\n\n Il valore %d e\' stato eliminato dalla lista\n ",numero);
                else
                    printf("\n\n Il valore selezionato NON e\' presente in lista\n ");
                printf("\n\n");
                system("pause");
                break;
            case '5': //azzera lista
                system("cls");
                while (testa != NULL)
                {
                    temp = testa;
                    testa = testa->next;
                    free(temp);
                }
                printf("\n\n LISTA AZZERATA!\n\n ");
                printf("\n\n");
                system("pause");
                break;
            case '6': //Esci dal programma
                flag = 0;
                break;
        }

    }

    /* free of the list */
    while (testa != NULL){
        temp = testa;
        testa = temp->next;
        free(temp);
    }

    return 0;
}
