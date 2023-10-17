/****************************************************************************
 *
 * hashtable.c -- Hash Table.
 *
 * Copyright (C) 2021 Nicolas Farabegoli - Moreno Marzolla
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
% LabASD - Hash Table
% Nicolas Farabegoli <nicolas.farabegoli2@unibo.it>
  Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-25

Realizziamo una tabella hash in cui le collisioni vengono gestite
mediante liste (_chaining_). Le chiavi sono stringhe di caratteri
zero-terminate, come le normali stringhe in C; ad ogni chiave è
associato un valore intero, da trattare come "dato
satellite". L'interfaccia della struttura dati è descritta nel file
[hashtable.h](hashtable.h) a cui bisogna fare riferimento per le
specifiche delle singole funzioni.

La tabella hash viene realizzata mediante una struttura `HashTable`
così definita:

```C
typedef struct {
    HashNode **items;
    int size;
    int values_count;
} HashTable;
```

dove `items` è un array di `size` puntatori, ciascuno dei quali punta
all'inizio della lista di collisione, e `values_count` è il numero di
coppie (chiave, valore) presenti nella tabella hash (inizialmetne
zero). Il campo `values_count` consente di conoscere in tempo $O(1)$
il numero di coppie presenti nella hashtable, senza doverle contare di
volta in volta. Tale informazione può essere mantenuta aggiornata in
tempo $O(1)$ durante l'esecuzione delle altre operazioni.

I nodi delle liste di collisione sono definiti dalla struttura
`HashNode`:

```C
typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;
```

Nella Figura 1 viene mostrato un esempio di tabella hash.

![Figura 1: Esempio di tabella hash; **Nota**: non necessariamente le chiavi generano delle collisioni come mostrato](hashtable.png)

Vengono fornite due funzioni, `encode(key)` e `hash_function(h,k)`,
per associare le chiavi (stringhe) agli slot della tabella hash. La
funzione `encode(key)` trasforma una stringa in un numero ottenuto
sommando i codici ASCII di tutti i caratteri della stringa[^1].
`hash_function(h,k)` accetta come parametri una tabella hash `h` e un
intero `k`, e restituisce un intero appartenente all'intervallo $0,
\ldots, \texttt{h->size}-1$ usando l'operatore modulo. Il valore
prodotto da `hash_function()` viene usato come indice dell'array
`h->items[]`, per decidere in quale lista di trabocco inserire la
chiave data.

[^1]: Sommare banalmente i codici ASCII è una **pessima** idea perché
      può produrre collisioni in modo troppo predicibile. Tale
      funzione quindi **non va usata** in applicazioni reali.
      Una funzione alternativa che viene spesso raccomandata è
      `djb2` descritta [qui](http://www.cse.yorku.ca/~oz/hash.html).

Il programma [hashtable-main.c](hashtable-main.c) contiene una funzione
`main()` che legge da standard input una sequenza di comandi,
uno per ogni riga, che manipolano una tabella hash inizialmente vuota.

Il file di comandi, di cui viene fornito un esempio nel file
[hashtable.in](hashtable.in) contiene una sequenza di comandi,
descritti nella tabella seguente:

----------------------------------------------------------------------------
Comando       Significato
------------  --------------------------------------------------------------
`n size`      Inizializza l'array dei puntatori a liste di collisione
              alla dimensione `size` ; questa istruzione compare una 
              sola volta all'inizio

`i key val`   Inserisce la chiave `key` con valore `val`

`s key`       Restituisce il valore associato alla chiave `key`, se 
              presente, oppure un opportuno messaggio

`d key`       Cancella la chiave `key` e il valore associato, se presenti
----------------------------------------------------------------------------

Le chiavi `key` sono stringhe che non contengono spazi, in modo da
facilitarne la lettura. I valori `val` sono interi.

Nel caso in cui si tenti di inserire un elemento la cui chiave è gia
presente nella tabella, occorre aggiornare il vecchio valore con
quello nuovo (si faccia riferimento alla specifica della funzione
`hash_insert()` nel file [hashtable.h](hashtable.h)). Tale
implementazione rispecchia il modo in cui vengono gestite le strutture
hash in altri linguaggi di programmazione (es., Java).

Per compilare:

        gcc -std=c90 -Wall -Wpedantic hashtable.c hashtable-main.c -o hashtable-main

PEr eseguire:

        ./hashtable-main < hashtable.in

oppure

        ./hashtable-main hashtable.in

## Per approfondire

- Supponiamo di partire con una hash table di dimensione $k$, cioè una
  hash table in cui ci sono $k$ liste di collisione inizialmente
  vuote. Supponiamo di inserire $n$ coppie (chiave, valore), in cui
  tutte le chiavi sono distinte. Qual è la lunghezza media delle liste
  di collisione, nel caso migliore in cui l'hash delle chiavi sia
  uniformemente distribuito? Qual è invece la lunghezza _massima_ di
  una lista di collisione nel caso peggiore?

- La funzione `encode()` converte una stringa di caratteri in un
  valore numerico, da cui si ricava l'hash tramite l'operatore modulo.
  La funzione `encode()` non è molto sofisticata; riuscite a costruire
  una sequenza di chiavi diverse che producono tutte lo stesso valore
  hash?

## File

- [hashtable.c](hashtable.c)
- [hashtable.h](hashtable.h)
- [hashtable-main.c](hashtable-main.c)
- [hashtable.in](hashtable.in) (output atteso [hashtable.out](hashtable.out))

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hashtable.h"

unsigned long hash_function(const HashTable *table, unsigned long k)
{
    assert(table);
    
    return k % table->size;
}

unsigned long encode(const char *key)
{
    int i;
    unsigned long s;
    
    assert(key);
    
    s = 0;
    for (i=0; key[i]; i++) {
        s += key[i];
    }
    return s;
}

/* Ritorna 1 se k1 e k2 sono uguali */
static int keys_equal(const char *k1, const char *k2)
{
    assert(k1);
    assert(k2);
    
    return (0 == strcmp(k1, k2));
}

void ht_init(HashTable *h, const int size)
{
    int i;

    assert(h);
    
    h->size = size;
    h->values_count = 0;
    h->items = (HashNode **) malloc(h->size * sizeof(*(h->items)));
    assert(h->items);
    for (i = 0; i < h->size; i++) {
        h->items[i] = NULL;
    }
}

/* Crea un nuovo nodo per la hash table contenente una copia della
   chiave `key` con valore `value` associato.  Poni il successore di
   questo nodo a `next`. . */
static HashNode *create_node(const char *key, int value, HashNode *next)
{
    HashNode *item = (HashNode *) malloc(sizeof(HashNode));
    const int keylen = strlen(key);

    assert(item);
    item->key = (char*)malloc(keylen+1);
    assert(item->key);
    memcpy(item->key, key, keylen+1); /* copiamo anche il terminatore */
    item->next = next;
    item->value = value;
    return item;
}

/* Libera la memoria allocata per il nodo n della tabella hash.
   Libera anche la memoria riservata alla chiave. */
static void free_node(HashNode *n)
{
    assert(n);
    
    free(n->key);
    free(n);
}

int ht_insert(HashTable *h, const char *key, int value)
{
    /* [TODO] */
    return -1;
}

HashNode *ht_search(HashTable *h, const char *key)
{
    /* [TODO] */
    return NULL;
}

int ht_delete(HashTable *h, const char *key)
{
    /* [TODO] */
    return -1;
}

void ht_destroy(HashTable *h)
{
    int i;
    
    assert(h);
    
    for (i = 0; i < h->size; i++) {
        HashNode *current = h->items[i];
        while (current != NULL) {
            HashNode *next = current->next;
            free_node(current);
            current = next;
        }
    }
    free(h->items);
    h->items = NULL;
    h->size = 0;
    h->values_count = 0;
}

int ht_count(const HashTable *h)
{
    assert(h);
    return (h->values_count);
}
