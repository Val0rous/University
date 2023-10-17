#include <stdio.h>
#include <stdlib.h>

struct cella
{
    int valore;
    struct cella *next;
};

int main()
{
    int numero;
    struct cella *testa;
    struct cella *nuovoElemento;
    testa = NULL; //inizializzazione del puntatore, e\' importante inizializzare tutte le variabili ad un valore preciso

    numero = 7;
    /*
    creazione di un nuovo elemento e inserimento in lista:
        1. allocazione della memoria per mantenere la nuova cella
        2. collegare la nuova cella con quella puntata dalla testa
        3. collegare la testa con la nuova cella creata
    */

    nuovoElemento = (struct cella*)malloc(sizeof(struct cella)); //Operazione 1
    if(nuovoElemento==NULL){
        printf("Error in malloc!\n");
        exit(1);
    }
    nuovoElemento->valore = numero;
    nuovoElemento->next = testa; //Operazione 2
    testa = nuovoElemento; //Operazione 3

    /* free of the list */
    while (testa != NULL) {
        nuovoElemento = testa;
        testa = nuovoElemento->next;
        free(nuovoElemento);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
