/****************************************************************************
 *
 * conta-parole.c -- Conta il numero di parole uniche in un file
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
% LabASD - Conta il numero di parole uniche in un file
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-03-25

Scrivere un programma che legga un documento di testo da standard
input o da file, e determini il numero di parole distinte in esso
contenuto; ogni parola deve essere contata una sola volta, e non si fa
distinzione fra lettere maiuscole e minuscole.

Per "parola" si intende una sequenza contigua di caratteri per i quali
la funzione `isalpha()` restituisce _vero_ (cioè un valore diverso da
zero). Ad esempio, la stringa `i diritti inviolabili dell'uomo` è
composta da cinque parole: `i`, `diritti`, `inviolabili`, `dell` e
`uomo`. Per semplicità, si assuma che tutte le parole abbiano
lunghezza strettamente minore a `MAXLEN`.

Ad esempio, nel testo:

``` 
La Repubblica riconosce e garantisce i diritti inviolabili
dell'uomo, sia come singolo, sia nelle formazioni sociali ove si
svolge la sua personalità, e richiede l'adempimento dei doveri
inderogabili di solidarietà politica, economica e sociale.  
```

sono presenti 36 parole:

```
la
repubblica
riconosce
e
garantisce
i
diritti
inviolabili
dell
uomo
sia
come
singolo
sia
nelle
formazioni
sociali
ove
si
svolge
la
sua
personalit
e
richiede
l
adempimento
dei
doveri
inderogabili
di
solidariet
politica
economica
e
sociale
```

di cui 32 distinte. Da notare che con la mia configurazione di sistema
la funzione `isalpha()` non riconosce le lettere accentate come
caratteri alfabetici.

## File

- [conta-parole.c](conta-parole.c)
- [the-time-machine.txt](the-time-machine.txt) (fonte: <http://www.gutenberg.org/files/35/35-0.txt>) (32895 parole, di cui 4597 distinte)
- [war-and-peace.txt](war-and-peace.txt) (fonte: <http://www.gutenberg.org/files/2600/2600-0.txt>)
- [the-hound-of-the-baskervilles.txt](the-hound-of-the-baskervilles.txt) (fonte: <http://www.gutenberg.org/files/2852/2852-0.txt>)
- [war-of-the-worlds.txt](war-of-the-worlds.txt) (fonte: <http://www.gutenberg.org/files/36/36-0.txt>)

***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 100


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
