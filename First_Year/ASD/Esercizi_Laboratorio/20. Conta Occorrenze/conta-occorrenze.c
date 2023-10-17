/****************************************************************************
 *
 * conta-occorrenze.c -- Conta occorrenze di parole in un file di testo
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
% LabASD - Conta occorrenze di parole in un file di testo
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-11

Scrivere un programma che legge un file di testo e conta il numero di
occorrenze di ciascuna parola presente nel file. Per "parola" si
intende una sequenza di caratteri alfabetici contigui; un carattere
$c$ si considera alfabetico se la funzione `isalpha(c)` restituisce un
valore diverso da zero; questa funzione è definita nell'header file
`<ctype.h>`. Il programma non deve fare differenza tra maiuscole e
minuscole. Per la lettura del file e la conversione dei caratteri in
minuscoli può essere utile fare uso delle funzioni `fgetc()`
(dichiarata in `<stdio.h>`) e `tolower()` (dichiarata in
`<ctype.h>`), in modo simile a quanto già fatto nell'esercizio sul
[conteggio delle parole distinte](conta-parole.html).

Il programma legge il testo da standard input, oppure da un file il
cui nome è indicato come unico parametro sulla riga di comando.  Al
termine dell'esecuzione, il programma deve stampare a video le parole
presenti nel file, in ordine alfabetico, con accanto il numero di
occorrenze.

Ad esempio, se l'input è il seguente frammento di testo:

```
Nel mezzo del cammin di nostra vita
mi ritrovai per una selva oscura,
che' la diritta via era smarrita.
Ahi quanto a dir qual era e' cosa dura
esta selva selvaggia e aspra e forte
che nel pensier rinova la paura!
Tant' e' amara che poco e' piu' morte;
ma per trattar del ben ch'i' vi trovai,
diro' de l'altre cose ch'i' v'ho scorte.

```

il programma deve stampare:

```
a 1
ahi 1
altre 1
amara 1
aspra 1
ben 1
cammin 1
ch 2
che 3
cosa 1
cose 1
de 1
del 2
di 1
dir 1
diritta 1
diro 1
dura 1
e 5
era 2
esta 1
forte 1
ho 1
i 2
l 1
la 2
ma 1
mezzo 1
mi 1
morte 1
nel 2
nostra 1
oscura 1
paura 1
pensier 1
per 2
piu 1
poco 1
qual 1
quanto 1
rinova 1
ritrovai 1
scorte 1
selva 2
selvaggia 1
smarrita 1
tant 1
trattar 1
trovai 1
una 1
v 1
vi 1
via 1
vita 1
```

Per risolvere questo problema serve una struttura dati che consenta di
gestire un insieme di coppie <_parola, numero occorrenze_> supportando
le seguenti operazioni:

- inserimento di una nuova coppia;

- ricerca di una coppia data la parola.

Dato che l'esercizio richiede che, al termine, le parole vengano
stampate in ordine alfabetico, è utile che la struttura dati mantenga
l'ordinamento alfabetico delle parole.

In questo esercizio useremo un albero binario di ricerca (_Binary
Search Tree_, BST), dove le parole sono le chiavi di ricerca, e il
numero delle occorrenze è un dato satellite. I nodi dell'albero
possono essere definiti come:

```C
typedef struct BSTNode {
    char *s;
    int count;
    struct BSTNode *left, *right;
} BSTNode;
```

dove `count` è il numero di occorrenze della parola `s`.

Non serve realizzare tutte le operazioni di un BST, ma è sufficiente
una versione opportunamente modificata dell'inserimento. Durante
l'inserimento bisogna creare un nuovo nodo se la parola non è
presente, oppure incrementare il contatore di occorrenze se la parola
è già presente.

Per confrontare due parole e decidere come muoversi nell'albero, si
può usare la funzione `strcmp(s1, s2)` che ritorna un valore negativo,
positivo o zero se `s1` è, rispettivamente, minore, maggiore o uguale
a `s2`.

Si può assumere che tutte le parole abbiano sempre lunghezza
strettamente minore di una certa costante `MAXLEN`.

## File

- [conta-occorrenze.c](conta-occorrenze.c)
- [the-time-machine.txt](the-time-machine.txt) (fonte: <http://www.gutenberg.org/files/35/35-0.txt>) (la parola "about" compare 69 volte; "certain" 18 volte; "you" 137 volte)
- [war-and-peace.txt](war-and-peace.txt) (fonte: <http://www.gutenberg.org/files/2600/2600-0.txt>)
- [the-hound-of-the-baskervilles.txt](the-hound-of-the-baskervilles.txt) (fonte: <http://www.gutenberg.org/files/2852/2852-0.txt>)
- [the-war-of-the-worlds.txt](the-war-of-the-worlds.txt) (fonte: <http://www.gutenberg.org/files/36/36-0.txt>)

***/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 128

typedef struct BSTNode {
    char *s;
    int count;
    struct BSTNode *left, *right;
} BSTNode;


int main( int argc, char *argv[] )
{
    FILE *filein = stdin;

    if (argc > 1) {
        filein = fopen(argv[1], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }
    /* TODO */

    return EXIT_SUCCESS;
}
