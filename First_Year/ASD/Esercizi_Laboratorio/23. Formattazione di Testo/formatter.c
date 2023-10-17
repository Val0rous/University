/****************************************************************************
 *
 * formatter.c -- Formattazione di testo
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
% LabASD - Formattazione di testo
% Moreno Marzolla <moreno.marzolla@unibo.it>
% Ultimo aggiornamento: 2021-04-22

Scrivere un programma che legga un file di testo da standard input
(oppure da file), e stampi su standard output la sequenza di parole
che lo compongono in modo che ogni riga abbia lunghezza massima di
`Lmax` caratteri, con `Lmax` parametro passato dalla riga di comando.

Più in dettaglio, il programma deve scomporre il testo in sequenza di
parole, dove per "parola" si intende una qualunque sottosequenza
massimale di caratteri che non includa alcun carattere `c` per cui
l'espressione `isspace(c)` restituisce un valore diverso da zero.

Il programma deve stampare le parole su standard output, ciascuna
separata dalla successiva con un _singolo_ spazio. Gli eventuali "a
capo" nell'input devono essere trattati come se fossero spazi. La
lunghezza di una riga è data dalla somma delle lunghezze delle parole
e degli spazi che le separano, e deve essere minore o uguale a
`Lmax`. Si può assumere che le parole abbiano sempre lunghezza
strettamente minore di `WORDLEN`.

Ad esempio, il comando

        ./formatter 65 < divina-commedia-canto1.in

produrrà un risultato le cui ultime cinque righe sono:

```
ivi elegge!>>. E io a lui: <<Poeta, io ti richeggio per quello
Dio che tu non conoscesti, a cio ch'io fugga questo male e
peggio, che tu mi meni la dov' or dicesti, si ch'io veggia la
porta di san Pietro e color cui tu fai cotanto mesti>>. Allor si
mosse, e io li tenni dietro.
```

Può essere utile leggere il prossimo carattere dal file usando la
funzione `int fgetc(FILE*)`, definita in `<stdio.h>`; la funzione
restituisce il simbolo `EOF` se si è raggiunta la fine del file.

Per riconoscere gli spazi è possibile usare la funzione `int
isspace(int c)` definita in `<ctype.h>`, che ritorna un intero diverso
da zero se `c` è uno spazio o simile (sono considerati spazi anche i
caratteri _form-feed_ `'\f'`, _newline_ `'\n'`, _carriage return_
`'\r'`, tabulazione `'\t'`, e tabulazione verticale `'\v'`).

Questo esercizio può essere risolto mediante una strategia _greedy_:
si aggiungono parole alla riga corrente fin quando possibile.

Per compilare:

        gcc -std=c90 -Wall -Wpedantic formatter.c -o formatter

Per eseguire:

        ./formatter 65 < divina-commedia.in

## Suggerimenti

Questo esercizio è più complesso di quanto sembri, perché deve gestire
numerosi casi particolari. In particolare:

- Il programma funziona correttamente se l'input è un file vuoto?

- Il programma funziona correttamente se l'input è costituito
  da una singola parola, senza spazi né prima né dopo?

- Il programma stampa correttamente la prima/l'ultima riga di testo?

## Curiosità

Questo programma è una versione molto semplificata del programma
[fmt](https://en.wikipedia.org/wiki/Fmt_(Unix)) del sistema operativo
Unix. `fmt` formatta i paragrafi di un file di testo in modo da
rispettare una ampiezza massima definita dall'utente. Su distribuzioni
Linux basate su Debian, questo comando fa parte del pacchetto
`coreutils`. Si noti che il programma richiesto in questo esercizio, a
differenza di `fmt`, compatta una sequenza di spazi contigui in un
singolo spazio e tratta gli "a capo" come se fossero spazi.

## Per approfondire

- Si modifichi il programma in modo da giustificare le righe di testo
  stampate in output. Il programma deve inserire degli spazi ulteriori
  (distribuiti nel modo più uniforme possibile) in modo che la
  lunghezza di ogni riga stampata sia esattamente uguale a `Lmax`.

- La soluzione che si chiede di realizzare tratta gli "a capo" come se
  fossero spazi. Modificare il programma per mandare a capo l'output
  ogni volta che si incontra un "a capo" nell'input.

## File

- [formatter.c](formatter.c)
- [divina-commedia-canto1.in](divina-commedia-canto1.in) (da [LiberLiber](https://www.liberliber.it/online/autori/autori-a/dante-alighieri/la-divina-commedia-edizione-petrocchi)). Il comando `./formatter 75 divina-commedia-canto1.in` dovrebbe produrre [questo risultato](divina-commedia-canto1.out); la prima riga, prodotta dalla funzione `header()`, serve solo come riferimento.
- [the-time-machine.txt](the-time-machine.txt) (fonte: <http://www.gutenberg.org/files/35/35-0.txt>)
- [war-and-peace.txt](war-and-peace.txt) (fonte: <http://www.gutenberg.org/files/2600/2600-0.txt>)
- [the-hound-of-the-baskervilles.txt](the-hound-of-the-baskervilles.txt) (fonte: <http://www.gutenberg.org/files/2852/2852-0.txt>)
- [the-war-of-the-worlds.txt](the-war-of-the-worlds.txt) (fonte: <http://www.gutenberg.org/files/36/36-0.txt>)

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/* massima lunghezza di una parola */
#define WORDLEN 1024


/* Stampa una riga di intestazione di lunghezza n */
void header(int n)
{
    int i;

    for (i=1; i<=n; i++) {
        printf("%c", i%10 ? '-' : '|');
    }
    printf("\n");
}

int main( int argc, char *argv[] )
{
    FILE *filein = stdin;
    int Lmax;
    char w[WORDLEN];
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Uso: %s Lmax [filein]\n", argv[0]);
        return EXIT_FAILURE;
    }

    Lmax = atoi(argv[1]);

    if (argc > 2) {
        filein = fopen(argv[2], "r");
        if (filein == NULL) {
            fprintf(stderr, "Can not open %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    header(Lmax);
    /* [TODO] completare il programma qui */
    printf("\n");
    return EXIT_SUCCESS;
}
