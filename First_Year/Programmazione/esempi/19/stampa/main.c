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
    int numero, count, flag;
    struct cella *testa;
    struct cella *nuovoElemento;
    struct cella *temp; //puntatore temporaneo per scorrere la lista e non perdere il riferimento alla testa
    testa = NULL; //inizializzazione del puntatore, e\' importante inizializzare tutte le variabili ad un valore preciso

    flag = 1;
    while (flag)
    {
        system("cls");
        printf("\n\n Seleziona l\'operazione:\n");
        printf("\n 1 - Inserisci nuovo elemento");
        printf("\n 2 - Stampa elenco elementi");
        printf("\n 3 - Esci");
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
                    printf("\n\n");
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
            case '3': //Esci dal programma
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
