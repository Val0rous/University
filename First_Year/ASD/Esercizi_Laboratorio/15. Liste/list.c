/****************************************************************************
 *
 * list.c -- Lista concatenata con sentinella
 *
 * Copyright (C) 2021 Moreno Marzolla
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/***
% LabASD - Lista concatenata con sentinella
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-25

(Ringraziamenti: prof. [Violetta Lonati](http://lonati.di.unimi.it/),
Università di Milano)

Implementare una lista doppiamente concatenata con sentinella; il file
[list.h](list.h) contiene la specifica dell'interfaccia. In una lista
concatenata, ogni nodo (di tipo `ListNode`) ha un puntatore al nodo
precedente e al nodo seguente, oltre ad un attributo `val` che
contiene il valore memorizzato in quel nodo. I valori sono di tipo
`ListInfo`, che di default è impostato al tipo `int`.

In una lista con sentinella è presente un nodo speciale, detto appunto
"sentinella", che non contiene alcuna informazione utile ma serve solo
per marcare l'inizio (o la fine) della lista. La lista vuota viene
rappresentata come mostrato in Figura 1.

![Figura 1: Lista vuota con sentinella](empty-list.png)

Il tipo di dato `List` è una struttura contenente un intero che indica
la lunghezza della lista (esclusa la sentinella), e la sentinella. Nel
caso di lista vuota, i puntatori `succ` e `pred` della sentinella
puntano alla sentinella stessa.

Una lista non vuota appare come mostrato in Figura 2.

![Figura 2: Lista doppiamente concatenata con sentinella](list.png)

Tramite la sentinella è possibile avere accesso diretto al primo e
all'ultimo elemento della lista, in modo da supportare l'inserimento
in testa o in coda in tempo $O(1)$. La sentinella inoltre semplifica
l'implementazione delle operazioni, in quanto non occorre gestire il
caso particolare di lista vuota: anche in una lista vuota comunque
esiste il nodo sentinella.

Il file [list-main.c](list-main.c) contiene un `main()` che legge da
standard input una sequenza di operazioni da eseguire su una lista
inizialmente vuota.

-------------------------------------------------------------------------
Operazione    Significato
------------  -----------------------------------------------------------
`+ k`         Inserisci un nuovo nodo contenente `k`

`- k`         Cancella uno dei nodi contenenti `k`, se presente; 
              altrimenti, non fare nulla

`? k`         Cerca il valore `k` nella lista, e stampa un opportuno 
              messaggio per indicarne o meno la presenza

`c`           Stampa la lunghezza della lista

`p`           Stampa il contenuto della lista

`d`           Svuota la lista, cancellando tutti i nodi in essa contenuti
-------------------------------------------------------------------------

Si tenga presente che è possibile inserire più volte lo stesso valore;
in caso di cancellazione di un valore che compare più volte, sarà
possibile cancellarne una occorrenza qualsiasi.

Esempio di file di input [list.in](list.in); su sistemi Linux/MacOSX,
dopo aver compilato il programma con

        gcc -std=c90 -Wall -Wpedantic list.c list-main.c -o list-main

è possibile provare l'input con il comando:

        ./list-main < list.in

oppure

        ./list-main list.in

Come sempre, è possibile realizzare ulteriori funzioni di supporto.

## Per approfondire

Chi lo desidera può implementare ulteriori operazioni (es.,
inserimento in coda o in testa; cancellazione dalla testa o dalla
coda), oppure realizzare una variante della lista in cui gli elementi
vengono mantenuti ordinati.

## File

- [list.c](list.c) 
- [list.h](list.h) 
- [list-main.c](list-main.c)
- [list.in](list.in) (output atteso [list.out](list.out))

 ***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v. I puntatori al
   nodo successivo e precedente puntano entrambi al nodo appena creato */
static ListNode *list_new_node(int v)
{
    ListNode *r=(ListNode *)malloc(sizeof(ListNode));
    assert(r); /* evitiamo un warning con VS */
    r->val = v;
    r->succ = r->pred = r;
    return r;
}

/* Restituisce l'indirizzo di memoria della sentinella di L */
ListNode *list_end(List *L)
{
    assert(L);
    
    return &(L->sentinel);
}

void list_init( List* L )
{
    assert(L);
    
    L->length = 0;
    L->sentinel.pred = L->sentinel.succ = &(L->sentinel);
}

int list_length(List *L)
{
    assert(L);
    
    return L->length;    
}


void list_destroy(List *L)
{
    list_remove_all(L);
}

void list_remove_all(List *L)
{
    /* [TODO] */
}

/* Nota: questa funzione assume che ListInfo sia il tipo "int" */
void list_print(List *L)
{   
    const ListNode *node;

    assert(L);

    printf("(");
    for (node = list_first(L); node != list_end(L); node = list_succ(node)) {
        printf("%d ", node->val);
    }
    printf(")\n");
}

int list_is_empty(List *L)
{
    assert(L);
    
    return (list_first(L) == list_end(L));
}

ListNode *list_search(List *L, ListInfo k)
{
    /* [TODO] */
    return NULL;
}

ListNode *list_first(List *L)
{
    assert(L);
    
    return L->sentinel.succ;
}

ListNode *list_last(List *L)
{
    assert(L);
    
    return L->sentinel.pred;
}


/* Inserisce un nuovo nodo contenente k all'inizio della lista */
void list_add_first(List *L, ListInfo k)
{
    /* [TODO] */
}

/* Inserisce un nuovo nodo contenente k alla fine della lista */
void list_add_last(List *L, ListInfo k)
{
    /* [TODO] */
}

/* Rimuove il nodo n dalla lista L */
void list_remove(List *L, ListNode *n)
{
    /* [TODO] */
}

ListInfo list_remove_first(List *L)
{
    /* [TODO] */
    return -1;
}

ListInfo list_remove_last(List *L)
{
    /* [TODO] */
    return -1;
}

ListNode *list_succ(const ListNode *n)
{
    assert(n);
    
    return n->succ;
}

ListNode *list_pred(const ListNode *n)
{
    assert(n);
    
    return n->pred;
}

ListNode *list_nth_element(List *L, int n)
{
    /* [TODO] */
    return list_end(L);
}

void list_concat(List *L1, List *L2)
{
    /* [TODO] */
}

int list_equal(List *L1, List *L2)
{
    /* [TODO] */
    return -1;
}
