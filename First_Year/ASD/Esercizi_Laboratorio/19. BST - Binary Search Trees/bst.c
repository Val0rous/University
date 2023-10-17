/****************************************************************************
 *
 * bst.c -- Alberi binari di ricerca
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
% LabASD - Alberi binari di ricerca
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-19

Implementare un albero binario di ricerca (BST, _binary search tree_)
non bilanciato.

Il file [bst.h](bst.h) contiene la specifica dell'interfaccia del
BST. Si chiede di realizzare le funzioni indicate. È possibile
definire ulteriori funzioni che si ritengano necessarie.

Un nodo di un BST è definito dalla struttura:

```C
typedef int BSTKey;
typedef struct BSTNode {
    struct BSTNode *parent, *left, *right;
    BSTKey key;
} BSTNode;
```

dove `BSTKey` è il tipo dell'informazione mantenuta in ciascun nodo
(di default, un valore intero), mentre `parent`, `left` e `right` sono
rispettivamente puntatori al padre, al figlio sinistro e al figlio
destro. Nel caso della radice si avrà `parent == NULL`.  Un esempio è
mostrato nella Figura 1.

![Figura 1: Esempio di albero binario di ricerca](bst.png)

La specifica delle funzioni è indicata nel file [bst.h](bst.h).  La
funzione `bst_pretty_print()` (che suggerisco di lasciare per ultima,
dato che è la meno importante) stampa un BST in modo un po' più
leggibile, ruotando di 90 gradi quanto viene stampato.

Ad esempio, la funzione `bst_pretty_print()` potrebbe produrre l'output
seguente:

```
   55
12
      9
   5
      -3
```

che rappresenta l'albero:

```
         12
        /  \
       5    55
      / \
    -3   9
```


Il programma [bst-main.c](bst-main.c) legge da standard input una
sequenza di comandi, uno per ogni riga, che manipolano un BST
inizialmente vuoto. I comandi sono descritti nella tabella seguente,
dove _k_ è una chiave intera.

Comando       Significato
-----------   ----------------------------------------------
`+` _k_       Inserisci la chiave _k_
`-` _k_       Cancella il nodo contenente _k_, se presente
`?` _k_       Verifica se la chiave _k_ è presente
`s`           Stampa il numero di nodi (_size_) nell'albero
`h`           Stampa l'altezza dell'albero
`p`           Stampa il contenuto dell'albero
-----------   ----------------------------------------------

Un esempio di file di input è [bst.in](bst.in).

Per compilare:

        gcc -std=c90 -Wall -Wpedantic bst.c bst-main.c -o bst-main

Per eseguire:

        ./bst-main < bst.in

oppure

        ./bst-main bst.in

Si assuma che `BSTKey` sia il tipo `int`.

## Per approfondire

- Scrivere una funzione che inserisca gli interi $\{0, 1, \ldots, n -
  1\}$ in un BST inizialmente vuoto in modo da ottenere un albero di
  altezza minima; se lo si ritiene utile, si può assumere che $n$ sia
  una qualche potenza di due.

- È possibile mantenere in ciascun nodo l'informazione sull'altezza
  del sottoalbero radicato in quel nodo. Questo consentirebbe di
  realizzare la funzione `bst_height()` in tempo $O(1)$, a patto di
  riuscire a mantenere efficientemente l'altezza di ciascun nodo anche
  dopo inserimenti e cancellazioni. Modificare le funzioni
  `bst_insert()` e `bst_delete()` perché aggiornino le altezze
  contenute in tutti i nodi che si trovano lungo il cammino che va dal
  nodo inserito/cancellato fino alla radice dell'albero.

- Le procedure di inserimento e ricerca possono essere espresse in
  modo iterativo (come fatto nel libro di testo) oppure ricorsivo. È
  istruttivo provare ad implementarle in entrambi i modi.

- Qual è l'altezza media di un BST in cui vengono inserite $n$ chiavi
  casuali uniformemente distribuite in un qualche intervallo di
  valori? Si provi a determinarla sperimentalmente, ripetendo
  l'inserimento di $n$ valori casuali e calcolando la media delle
  altezze ottenute. [È stato
  dimostrato](https://dl.acm.org/doi/10.1145/765568.765571) che
  l'altezza media è $\left(\alpha \ln n - \beta \ln \ln n +
  O(1)\right)$, con $\alpha \approx 4.311$ e $\beta \approx 1.953$.

## File

- [bst.c](bst.c)
- [bst.h](bst.h)
- [bst-main.c](bst-main.c)
- [bst.in](bst.in) (output atteso [bst.out](bst.out))
- [bst1.in](bst1.in)
- [bst2.in](bst2.in)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void bst_init(BST *T)
{
    assert(T != NULL);

    T->root = NULL;
    T->size = 0;
}

static void bst_clear_rec(BSTNode *n)
{
    if (n != NULL) {
        bst_clear_rec(n->left);
        bst_clear_rec(n->right);
        free(n);
    }
}

void bst_clear(BST *T)
{
    assert(T != NULL);

    bst_clear_rec(T->root);
    T->root = NULL;
    T->size = 0;
}

/* In questa implementazione di BST, la distruzione di un albero
   equivale a svuotarlo; non necessariamente è così (dipende da cosa
   mettiamo nella struttura BST), per cui forniamo entrambe le
   funzioni. */
void bst_destroy(BST *T)
{
    bst_clear(T);
}


BSTNode *bst_search(const BST *T, BSTKey k)
{
    assert(T != NULL);

    /* [TODO] */
    return NULL;
}


void bst_insert(BST *T, BSTKey k)
{
    assert(T != NULL);

    /* [TODO] */
}


void bst_delete(BST *T, BSTNode *n)
{
    assert(T != NULL);
    assert(n != NULL);

    /* [TODO] */
}


int bst_height(const BST *T)
{
    assert(T != NULL);
    /* [TODO] */
    return -1;
}

static void bst_print_rec( const BSTNode *n )
{
    printf("(");
    if (n != NULL) {
        printf("%d ", n->key);
        bst_print_rec(n->left);
        printf(" ");
        bst_print_rec(n->right);
    }
    printf(")");
}

/* Nota: la funzione di stampa assume che BSTKey sia il tipo "int" */
void bst_print( const BST *T )
{
    assert(T != NULL);

    bst_print_rec(T->root);
    printf("\n");
}


void bst_pretty_print( const BST *T )
{
    /* [TODO] */
}

int bst_size(const BST *T)
{
    assert(T != NULL);

    return T->size;
}

int bst_is_empty(const BST *T)
{
    assert(T != NULL);

    return (T->root == NULL);
}
