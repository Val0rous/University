/****************************************************************************
 *
 * minheap.c -- Min-Heap binario
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
% LabASD - Min-Heap binario
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-07

Lo scopo di questo esercizio è implementare un min-heap binario;
formuleremo il problema in modo leggermente diversa da quella vista a
lezione (e descritta nel libro di testo), perché questa struttura dati
ci servirà in futuro.

Un min-heap è un contenitore di coppie (`key`, `prio`), di capienza
massima `size`, dove

- `key` è un intero compreso tra 0 e (`size`-1) inclusi,

- `prio` è un numero reale che rappresenta la priorità associata a quella chiave. Lo heap deve mantenere la proprietà di ordine rispetto alla priorità.

> **Attenzione**: nel libro, `key` indica la priorità rispetto alla
> quale ordinare il contenuto dello heap; qui invece la priorità
> rispetto alla quale ordinare le informazioni nello heap è `prio`,
> mentre `key` rappresenta un dato satellite. Questa deviazione da
> quanto descritto nel libro ci tornerà utile quando implementeremo
> gli algoritmi di Dijkstra e di Prim).

Ogni chiave può apparire al più una volta nello heap; le priorità
invece sono numeri reali arbitrari (anche negativi), e non sono
soggette ad alcun vincolo. Lo heap supporta la ricerca efficiente
della coppia (`key`, `prio`) con `prio` minima.

Un min-heap viene rappresentato dalle strutture

```C
typedef struct {
    int key;
    double prio;
} HeapElem;

typedef struct {
    HeapElem *heap;
    int n;
    int size;
} MinHeap;
```

dove `size` è la dimensione dell'array `heap[]`, e `n` è il numero di
coppie (`key`, `prio`) effettivamente presenti nello heap in un dato
momento. Si deve sempre avere $0 \leq n \leq \texttt{size}$.

In un min-heap ogni nodo soddisfa la seguente proprietà:

> La priorità di un nodo è _minore o uguale_ a quella di entrambi i
> figli (se esistono)

Il file [minheap.h](minheap.h) contiene la specifica dell'interfaccia
della struttura dati min-heap. Si chiede di realizzare le funzioni
indicate, lasciando `minheap_change_prio()` per ultima in quanto è la
più laboriosa. È sempre possibile definire ulteriori funzioni di
supporto che si ritengano utili.

La Figura 1 mostra un esempio di min-heap con capienza massima `size =
8` contenente $n = 5$ elementi. L'attributo `prio` di ogni nodo ha
valore minore o uguale a quello dei figli (se presenti); le chiavi
invece sono dati satellite, che non entrano in gioco nel mantenimento
dell'ordine nello heap. Lo heap può essere realizzato mediante un
array di `size` elementi, di cui i primi `n` contengono le coppie
(chiave, priorità) presenti.

![Figura 1: Esempio di min-heap di capienza massima `size = 8` contenente $n = 5$ elementi, e sua rappresentazione tramite un array](minheap.png)

> **Attenzione**: le formule che sono state descritte a lezione per
> individuare l'indice dei figli/del padre di un nodo $i$ devono
> essere modificate per tenere conto del fatto che in C gli array sono
> indicizzati a partire da zero anziché da uno.

L'inserimento di una nuova coppia (chiave, priorità) avviene come
in Figura 2.

![Figura 2: Inserimento della coppia `(key=4, prio=1)`](minheap-insert.png)

La nuova coppia viene inserita alla base dello heap. Se lo heap è
rappresentato in un array `heap[]` di dimensione `size` e contiene $n$
elementi prima dell'inserimento, la nuova coppia viene inserita in
`heap[n]` e si incrementa $n$. Successivamente, si confronta
l'attributo `prio` del nodo appena inserito con quello del padre,
effettuando uno scambio nel caso in cui venga violata la proprietà di
ordine. Gli scambi con il padre vanno ripetuti fino a quando il nuovo
nodo raggiunge il livello corretto.

L'operazione più laboriosa è la `minheap_change_prio()`, che modifica
la priorità associata ad una chiave già presente nello heap.

Nella Figura 3 illustriamo come cambia lo heap se la priorità della
chiave 0 diventa 31. Se la priorità di un nodo aumenta, occorre
applicare l'operazione `Heapify()` vista a lezione per far "scendere"
il nodo fino al livello corretto, come mostrato in figura.

![Figura 3: `minheap_change_prio(h, 0, 31.0)`](minheap-change-prio1.png)

Nel caso in cui la priorità diminuisca (Figura 4), potrebbe rendersi
necessario effettuare scambi con il nodo padre fino a quando il nuovo
nodo raggiunge il livello corretto, in modo simile a quanto fatto
durante l'inserimento.

![Figura 4: `minheap_change_prio(h, 7, -2.0)`](minheap-change-prio2.png)

In uno heap binario con $n$ elementi i costi delle operazioni
dovrebbero essere i seguenti:

Operazione                     Costo
-----------------------------  --------------
`minheap_min()`                $O(1)$
`minheap_delete_min()`         $O(\log n)$
`minheap_insert()`             $O(\log n)$
`minheap_change_prio()`        $O(n)$[^1]
-----------------------------  --------------

[^1]: L'operazione più complessa è `minheap_chage_prio()`. Per
iniziare, la si realizzi mediante una scansione lineare dell'array
`heap[]` per cercare la posizione dell'elemento di chiave data.  Nella
specifica sono illustrati [alcuni suggerimenti](#suggerimenti) per
ridurre il costo asintotico di questa operazione a $O(\log n)$.

Il programma [minheap-main.c](minheap-main.c) contiene una funzione
`main()` che legge da standard input una sequenza di comandi, uno per
ogni riga, che manipolano uno heap inizialmente vuoto. I comandi sono
descritti nella tabella seguente.

----------------------------------------------------------------------------
Comando         Significato
--------------  ------------------------------------------------------------
_n_             Inizializza lo heap per contenere al più _n_ elementi;
                questa istruzione compare una sola volta all'inizio

`+` _key prio_  Inserisce la chiave _key_ con priorità _prio_

`-`             Cancella la coppia <_key, prio_> con priorità minima

`?`             Stampa la chiave associata alla priorità minima

`c` _key prio_  Modifica la priorità associata alla chiave _key_

`s`             Stampa il numero $n$ di elementi presenti nello heap

`p`             Stampa il contenuto dello heap (per debug)
----------------------------------------------------------------------------

Per compilare;

        gcc -std=c90 -Wall -Wpedantic minheap.c minheap-main.c -o minheap-main

Per eseguire:

        ./minheap-main < minheap.in

oppure

        ./minheap-main minheap.in

A titolo di confronto, l'ultimo comando `m` presente nel file di input
proposto dovrebbe stampare `6` come chiave associata alla minima
priorità.

## Suggerimenti

Realizzare l'operazione `minheap_change_prio()` in modo efficiente è
complesso. Tale funzione deve modificare la priorità di una chiave già
presente nello heap.

Se già sappiamo la posizione nell'array `heap[]` dell'elemento da
modificare, la funzione può essere implementata in tempo $O(\log n)$
nel caso peggiore. Il problema è che trovare la chiave `k` potrebbe
richiedere tempo $O(n)$ ("trovare la chiave" significa determinare
l'indice `i` tale che `heap[i].key == k`), perché bisogna scorrere
tutto lo heap.

Per trovare la chiave $k$ in tempo $O(1)$ si può utilizzare un secondo
array `pos[]` contenente `size` elementi. `pos[k]` è la posizione
(l'indice) dell'elemento di chiave `k` nell'array `heap[]`.  Per ogni
chiave `k` presente nello heap deve valere la proprietà:

        heap[pos[k]].key == k

Se la chiave `k` non è presente, si può porre `pos[k] = -1`.

Occorre prestare attenzione a mantenere aggiornato il contenuto di
`pos[]` man mano che gli elementi in `heap[]` vengono scambiati tra loro.

## File

- [minheap.c](minheap.c)
- [minheap.h](minheap.h)
- [minheap-main.c](minheap-main.c)
- [minheap.in](minheap.in) (output atteso [minheap.out](minheap.out))
- [minheap1.in](minheap1.in)
- [minheap2.in](minheap2.in)
- [minheap3.in](minheap3.in)

 ***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "minheap.h"

void minheap_print(const MinHeap *h)
{
    int i = 0, j, width = 1;

    assert(h != NULL);

    printf("\nn=%d size=%d\n", h->n, h->size);
    while (i < h->n) {
        for (j=0; j<width && i < h->n; j++) {
            printf("h[%d]=(%d %f) ", i, h->heap[i].key, h->heap[i].prio);
            i++;
        }
        printf("\n");
        width *= 2;
    }
    for (i=0; i<h->size; i++) {
        printf("pos[%d]=%d ", i, h->pos[i]);
    }
    printf("\n\n");
}


/* Costruisce un min-heap vuoto che può contenere al massimo
   size elementi */
void minheap_init(MinHeap *h, int size)
{
    int i;

    assert(h != NULL);

    h->n = 0;
    h->size = size;
    h->heap = (HeapElem*)malloc(size * sizeof(HeapElem));
    assert(h->heap != NULL);
    h->pos = (int*)malloc(size * sizeof(int));
    assert(h->pos != NULL);
    for (i=0; i<size; i++) {
        h->pos[i] = -1;
    }
}

/* Per svuotare lo heap è sufficiente impostare a zero il campo "n",
   che indica il numero di elementi presenti. */
void minheap_clear( MinHeap *h )
{
    assert(h != NULL);

    h->n = 0;
}

void minheap_destroy( MinHeap *h )
{
    assert(h != NULL);

    h->n = h->size = 0;
    free(h->heap);
    free(h->pos);
}

/* Restituisce 1 sse l'elemento in posizione i nello heap è un
   elemento valido, cioè se l'indice i è minore a n (numero di
   elementi che al momento si trovano nello heap). */
static int valid(const MinHeap *h, int i)
{
    assert(h != NULL);

    return ((i >= 0) && (i < h->n));
}

/* Scambia heap[i] con heap[j] */
static void swap(MinHeap *h, int i, int j)
{
    HeapElem tmp;

    assert(h != NULL);
    assert(valid(h, i));
    assert(valid(h, j));
    assert(h->pos[h->heap[i].key] == i);
    assert(h->pos[h->heap[j].key] == j);

    tmp = h->heap[i];
    h->heap[i] = h->heap[j];
    h->heap[j] = tmp;
    h->pos[h->heap[i].key] = i;
    h->pos[h->heap[j].key] = j;
}

/* Restituisce l'indice del padre del nodo i */
static int parent(const MinHeap *h, int i)
{
    assert(valid(h, i));

    return (i+1)/2 - 1;
}

/* Restituisce l'indice del figlio sinistro del nodo i */
static int lchild(const MinHeap *h, int i)
{
    assert(valid(h, i));

    return 2*i + 1;
}

/* Restituisce l'indice del figlio destro del nodo i */
static int rchild(const MinHeap *h, int i)
{
    assert(valid(h, i));

    return lchild(h, i) + 1;
}

/* Restituisce l'indice del figlio di i con priorità minima. Se i non
   ha figli, restituisce -1 */
static int min_child(const MinHeap *h, int i)
{
    int l, r, result = -1;

    assert(valid(h, i));

    l = lchild(h, i);
    r = rchild(h, i);
    if (valid(h, l)) {
        result = l;
        if (valid(h, r) && (h->heap[r].prio < h->heap[l].prio)) {
            result = r;
        }
    }
    return result;
}

/* Scambia l'elemento in posizione i con il padre fino a quando
   raggiunge la posizione corretta nello heap */
static void move_up(MinHeap *h, int i)
{
    int p;

    assert(valid(h, i));

    p = parent(h, i);
    while ( (p >= 0) && (h->heap[i].prio < h->heap[p].prio) ) {
        swap(h, i, p);
        i = p;
        p = parent(h, i);
    }
}

/* Scambia l'elemento in posizione i con il figlio con priorità
   minima fino a quando raggiunge la posizione corretta nello heap.
   Questa funzione corrisponde a Min-Heapify() */
static void move_down(MinHeap *h, int i)
{
    int done = 0;

    assert(valid(h, i));

    do {
        const int dst = min_child(h, i);
        if (valid(h, dst) && (h->heap[dst].prio < h->heap[i].prio)) {
            swap(h, i, dst);
            i = dst;
        } else {
            done = 1;
        }
    } while (!done);
}

/* Restituisce 1 se lo heap è vuoto */
int minheap_is_empty(const MinHeap *h)
{
    assert(h != NULL);

    return (h->n == 0);
}

/* Restituisce 1 se lo heap è pieno, cioè è stata esaurita la
   capienza a disposizione */
int minheap_is_full(const MinHeap *h)
{
    assert(h != NULL);

    return (h->n == h->size);
}

/* Restituisce il numero di elementi presenti nello heap */
int minheap_get_n(const MinHeap *h)
{
    assert(h != NULL);

    return h->n;
}

/* Restituisce la chiave associata all'elemento con priorità minima */
int minheap_min(const MinHeap *h)
{
    assert( !minheap_is_empty(h) );

    return h->heap[0].key;
}

/* Inserisce una nuova coppia (key, prio) nello heap. */
void minheap_insert(MinHeap *h, int key, double prio)
{
    int i;

    assert( !minheap_is_full(h) );
    assert((key >= 0) && (key < h->size));
    assert(h->pos[key] == -1);

    i = h->n++;
    h->pos[key] = i;
    h->heap[i].key = key;
    h->heap[i].prio = prio;
    move_up(h, i);
}

/* Rimuove la chiave associata alla priorità minima */
int minheap_delete_min(MinHeap *h)
{
    int result;

    assert( !minheap_is_empty(h) );

    result = minheap_min(h);
    swap(h, 0, h->n-1);
    h->pos[h->heap[h->n-1].key] = -1;
    h->n--;
    if (!minheap_is_empty(h)) {
        move_down(h, 0);
    }
    return result;
}

/* Modifica la priorità associata alla chiave key. La nuova priorità
   può essere maggiore, minore o uguale alla precedente. */
void minheap_change_prio(MinHeap *h, int key, double newprio)
{
    int j;
    double oldprio;

    assert(h != NULL);
    j = h->pos[key];
    assert( valid(h, j) );
    oldprio = h->heap[j].prio;
    h->heap[j].prio = newprio;
    if (newprio > oldprio) {
        move_down(h, j);
    } else {
        move_up(h, j);
    }
}
