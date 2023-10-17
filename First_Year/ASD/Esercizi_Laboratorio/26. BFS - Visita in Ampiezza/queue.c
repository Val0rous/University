/****************************************************************************
 *
 * queue.c -- Coda FIFO implementata mediante array circolare
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
% LabASD - Coda FIFO
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-07

Implementare una coda FIFO basata su un array circolare.  La coda è
rappresentata dalla struttura `Queue` seguente:

```C
typedef int QueueInfo;
typedef struct {
    int capacity;
    int head, tail;
    QueueInfo *data;
} Queue;
```

I dati nella coda sono contenuti nell'array `data[]` di dimensione
`capacity`. Il numero di elementi effttivamente presenti in coda potrà
essere minore di `capacity` (vedi oltre). Si inizi realizzando una
coda di capacità prefissasta costante (ad esempio, 100 elementi).

La variabile `head` rappresenta l'indice dell'elemento contenente la
testa della coda; `tail` rappresenta l'indice dell'elemento
_successivo_ alla fine della coda (si faccia riferimento alla Figura
1). Pertanto, la coda è vuota quando `head == tail`.

![Figura 1: Coda circolare](queue.png)

In generale, non tutti gli elementi dell'array conterranno valori
effettivamente presenti in coda. Questo consente di aggiungere nuovi
elementi in modo efficiente, almeno fino a quando si esaurisce lo
spazio nell'array `data`.

Poiché l'array viene considerato "circolare", quando uno degli indici
`head` o `tail` "esce" da una delle estremità, deve "rientrare"
dall'estermità opposta. Questo significa che tutti gli incrementi di
`head` e `tail` devono avvenire modulo `capacity` (l'operatore modulo
in linguaggio C è `%`).

Ad esempio, data una variabile `q` di tipo `Queue *`, per estrarre
l'elemento in testa alla coda si può utilizzare il seguente
frammento di codice:

```C
int result = q->data[q->head];
q->head = (q->head + 1) % q->capacity;
```

L'incremento della variabile `q->head` viene effettuato modulo
`q->capacity`.

In base a quanto detto sopra, il numero massimo di elementi che
possono essere presenti nella coda _non_ è `capacity`, ma `capacity -
1` (perché?).

Viene fornito un programma [queue-main.c](queue-main.c) che legge da
standard input (o da un file il cui nome viene passato sulla riga di
comando) una serie di comandi da eseguire su una coda inizialmente
vuota.

Operazione    Significato
------------  ----------------------------------------
`+` _val_     inserisce _val_ nella coda
`-`           rimuove il valore in fondo alla coda
`p`           stampa il contenuto della coda
------------  ----------------------------------------

L'inserimento e la rimozione di elementi dalla coda devono richiedere
tempo $O(1)$; nel caso si implementi la coda dinamica (vedi sotto), le
operazioni devono avere costo _ammortizzato_ $O(1)$.

Compilare con:

        gcc -std=c90 -Wall -Wpedantic queue.c queue-main.c -o queue-main

Eseguire con:

        ./queue-main < queue.in

oppure

        ./queue-main queue.in

## Per approfondire

Si renda la coda dinamica usando la tecnica del
raddoppiamento/dimezzamento. L'idea è la seguente:

- Se si tenta di inserire un elemento in una coda piena,
  la capienza della coda viene raddoppiata;

- Se dopo aver rimosso un elemento dalla coda, il numero di elementi
  diventa inferiore ad un quarto della capienza, la capienza della
  coda viene dimezzata.

Per raddoppiare o dimezzare la capienza della coda occorre allocare un
_nuovo_ array, copiare i dati dal vecchi al nuovo array, e far puntare
il campo `data` della coda al nuovo array, dopo aver deallocato quello
precedente. **Non usare la funzione `realloc()`**.

## File

- [queue.c](queue.c)
- [queue.h](queue.h)
- [queue-main.c](queue-main.c)
- [queue.in](queue.in)

 ***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"


#ifdef QUEUE_DEBUG
/* Questa funzione puo' risultare utile in fase di debug */
static void queue_debug( Queue *q )
{
    printf("h=%d t=%d n=%d\n", q->head, q->tail, q->capacity);
}
#endif

void queue_init( Queue *q )
{
    assert(q != NULL);

    q->capacity = 2;
    q->data = (QueueInfo*)malloc(q->capacity * sizeof(*(q->data)));
    assert(q->data != NULL);
    q->head = q->tail = 0;
}

void queue_destroy( Queue *q )
{
    assert(q != NULL);

    free(q->data);
    q->data = NULL;
    q->head = q->tail = -1;
    q->capacity = 0;
}

/* Ritorna 1 se e solo se la coda è piena. */
static int queue_is_full( const Queue *q )
{
    assert(q != NULL);

    /* return q->head == ((q->tail + 1) % q->capacity); */
    return (queue_size(q) == q->capacity - 1);
}

int queue_is_empty( const Queue *q )
{
    assert(q != NULL);

    return q->tail == q->head;
}

/* Ridimensional il buffer associato alla coda q alla nuova dimensione
   new_capacity. I dati vengono copiati dal vecchio al nuovo
   buffer. */
static void queue_resize( Queue *q, int new_capacity )
{
    int cur_size, cur_capacity;
    QueueInfo *new_data;

    assert(q != NULL);
    cur_size = queue_size(q);
    assert( new_capacity >= cur_size );
    cur_capacity = q->capacity;
    new_data = (QueueInfo*)malloc(new_capacity * sizeof(QueueInfo));
    assert(new_data != NULL);
    /* copiamo i dati dal vecchio al nuovo buffer */
    if (q->head <= q->tail) {
        /* Se i dati nella coda sono memorizzati in un segmento
           contiguo dell'array, basta una sola copia */
        memcpy(new_data,
               q->data + q->head,
               cur_size * sizeof(QueueInfo));
    } else {
        /* Invece, se i dati in coda sono memorizzati in due segmenti
           (cioè, se l'array circolare "torna indietro", ossia
           l'indice finale è minore dell'indice iniziale), sono
           necessarie due operazioni di copia. */
        memcpy(new_data,
               q->data + q->head,
               (cur_capacity - q->head) * sizeof(QueueInfo));
        memcpy(new_data + (cur_capacity - q->head),
               q->data,
               q->tail * sizeof(QueueInfo));
    }
    free(q->data);
    q->capacity = new_capacity;
    q->data = new_data;
    q->head = 0;
    q->tail = cur_size;
}

void queue_enqueue( Queue *q, QueueInfo val )
{
    assert(q != NULL);

    if (queue_is_full(q)) {
        queue_resize(q, q->capacity * 2);
    }

    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->capacity;
#ifdef QUEUE_DEBUG
    queue_debug(q);
#endif
}

QueueInfo queue_dequeue( Queue *q )
{
    QueueInfo result;

    assert(q != NULL);
    assert( ! queue_is_empty(q) );

    result = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;

    if (queue_size(q) <= q->capacity / 4) {
        queue_resize(q, q->capacity / 2);
    }

#ifdef QUEUE_DEBUG
    queue_debug(q);
#endif
    return result;
}

int queue_size( const Queue *q )
{
    assert(q != NULL);

    if (q->head <= q->tail) {
        return (q->tail - q->head);
    } else {
        return (q->capacity - (q->head - q->tail));
    }
}

void queue_print(const Queue *q)
{
    int i;

    assert(q != NULL);

    printf("HEAD << ");
    for (i=q->head; i != q->tail; i = (i+1) % q->capacity) {
        printf("%d ", q->data[i]);
    }
    printf("<< TAIL\n");
}
