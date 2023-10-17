#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct StructLista{
    int info;
    struct StructLista *next;
}StructLista;

typedef StructLista * pnt_NodoLista;

void InserisciTestaLista(pnt_NodoLista *lis, int elem);
void CancellaLista(pnt_NodoLista *lis);
void StampaLista(pnt_NodoLista lis);
void InvertiLista(pnt_NodoLista *lis);

int main()
{
    char opzione;
    int numero, flag;
    pnt_NodoLista testa;
    testa = NULL; //inizializzazione del puntatore, è importante inizializzare tutte le variabili ad un valore preciso

    flag = 1;
    while (flag)
    {
        system("cls");
        printf("\n\n Seleziona l\'operazione:\n");
        printf("\n 1 - Inserisci nuovo elemento");
        printf("\n 2 - Stampa elenco elementi");
        printf("\n 3 - Azzera la lista");
        printf("\n 4 - Inverti la lista");
        printf("\n 5 - Esci");
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
                InserisciTestaLista(&testa, numero);
                printf("\n\n Nuovo elemento creato correttamente!\n ");
                printf("\n\n");
                system("pause");
                break;
            case '2': //stampa degli elementi in lista
                system("cls");
                printf("\n\n STAMPA VALORI IN LISTA\n\n");
                StampaLista(testa);
                printf("\n\n");
                system("pause");
                break;
            case '3': //azzera lista
                system("cls");
                if (testa == NULL)
                    printf("\n\n LISTA VUOTA!\n\n ");
                else
                {
                    CancellaLista(&testa);
                    printf("\n\n LISTA AZZERATA!\n\n ");
                }
                printf("\n\n");
                system("pause");
                break;
            case '4': //inverti lista
                system("cls");
                if (testa == NULL)
                    printf("\n\n LISTA VUOTA!\n\n ");
                else
                {
                    InvertiLista(&testa);
                    printf("\n\n LISTA INVERTITA!\n\n ");
                }
                printf("\n\n");
                system("pause");
                break;
            case '5': //Esci dal programma
                flag = 0;
                break;
        }

    }

    //free of the list
    if (testa != NULL){
        CancellaLista(&testa);
    }

    return 0;
}


void InserisciTestaLista(pnt_NodoLista *lis, int elem)
/* Inserisce l'elemento elem in testa alla lista lis. */
{
    pnt_NodoLista paux;
    paux = (pnt_NodoLista)malloc(sizeof(StructLista));
    if(paux==NULL){
        printf("Error in malloc!\n");
        printf("\n\n");
        system("pause");
        exit(1);
    }
    paux->info = elem;
    paux->next = *lis;
    *lis = paux;
}


void StampaLista(pnt_NodoLista lis)
//la testa viene passata per valore quindi le modifiche non vengono viste all'esterno
{
    int count = 0;

    printf("\n");
    if (lis==NULL)
    {
        printf(" La lista e\' vuota!\n");
        return;
    }

    while (lis!=NULL)
    {
        count++;
        printf(" cella %d valore: %d\n", count, lis->info);
        lis = lis->next;
    }

    printf("\n\n Stampati %d valori\n ", count);
}

void CancellaLista(pnt_NodoLista *lis)
{
    pnt_NodoLista temp;
    if(*lis==NULL){
        printf("La lista e' vuota!!!");
        return;
    }
    while(*lis!=NULL){//Se abbiamo un solo elemento
        temp = *lis; //salvo in temp la lis
        *lis=(*lis)->next; //la faccio scorrere
        free(temp); //elimino la vecchia lis
    }
}

void InvertiLista(pnt_NodoLista *lis)
{
    pnt_NodoLista temp;
    pnt_NodoLista prec;
    pnt_NodoLista suc;
    if(*lis==NULL){
        printf("La lista e' vuota!!!");
        return;
    }

    prec = NULL;
    temp = *lis; //salvo in temp la lis
    suc = (*lis)->next;
    while(suc!=NULL){
        temp->next = prec;
        prec = temp;
        temp = suc;
        suc = suc->next;
    }
    temp->next = prec;
    (*lis) = temp;
}
