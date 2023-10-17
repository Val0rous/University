/*
Pensa a un numero.

L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.

L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max).
Se i valori inseriti non rispettano il vincolo 0<min≤max, l’operazione di lettura va ripetuta.
L’utente pensa ad un numero compreso tra min e max.
Il programma cerca di indovinare la scelta dell’utente e propone un numero.
A seconda della situazione l’utente deve dire al programma se:
    -il numero da indovinare è più piccolo;
    -il numero da indovinare è più grande;
    -ha indovinato.
Non poniamo limite al numero di tentativi
Due possibili alternative di gioco:

1)

    Inserisci l’intervallo di ricerca (min max): 23 89

    Pensa ad un numero compreso tra 23 e 89

    Hai pensato a 56? (s/n) n

    il numero viene prima (<) o dopo (>) di 56? >

    Hai pensato a 73? (s/n) n

    il numero viene prima (<) o dopo (>) di 73? >

    Hai pensato a 81? (s/n) n

    il numero viene prima (<) o dopo (>) di 81? <

    Hai pensato a 77? (s/n) n

    il numero viene prima (<) o dopo (>) di 77? <

    Hai pensato a 75? (s/n) s

    Ho indovinato!!

2)

    Inserisci l’intervallo di ricerca (min max): 45 124

    Pensa ad un numero compreso tra 45 e 124

    Il numero e’ minore (<) uguale (=) o maggiore (>) di 84? >

    Il numero e’ minore (<) uguale (=) o maggiore (>) di 104? <

    Il numero e’ minore (<) uguale (=) o maggiore (>) di 94? >

    Il numero e’ minore (<) uguale (=) o maggiore (>) di 99? <Il numero e’ minore (<) uguale (=) o maggiore (>) di 96? >

    Il numero e’ minore (<) uguale (=) o maggiore (>) di 97? =

    Hai pensato a 97!
*/