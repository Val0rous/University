La JCF è una libreria del linguaggio Java che gestisce strutture dati (o collezioni) e relativi algoritmi. Fa parte del package java.util

Due tipi di collection:
Collection: contenitore di elementi atomici
Sottotipi:
List (sequenze)
Set (no duplicazioni)
Queue
Map: contenitore di coppie chiave-valore

Interfacce: Collection, List, Set, Iterator, Comparable
Classi collection: ArrayList, LinkedList, HashSet, HashMap
Classi con funzionalità: Collections, Arrays

Ogni collection ha sue regole di funzionamento, e non ammette certe operazioni che richiedono controlli a run-time (alcune collections sono immutabili e non si possono scrivere)

Foreach:	for(int i: array){...}
Java fornisce un meccanismo per usare il foreach su qualunque collection (non solo array): in particolare, su qualunque oggetto che implementi l'interfaccia java.lang.Iterable<X>

L'interfaccia Iterable ha un metodo per generare e restituire un nuovo Iterator
Un iteratore è un oggetto con metodi next(), hasNext() e remove()
for(T element: coll){...}
//coll is an object implementing Iterable<T>

Collection è la radice della gerarchia delle collezioni: rappresenta gruppi di oggetti (duplicati e non, ordinati e non); è rappresentata da sottointerfacce (List, Set)
Definisce operazioni base valide per tutte le collezioni
Assume implicitamente che ogni collezione abbia due costruttori
Le operazioni di modifica potrebbero lanciare un UnsupportedOperationException
Tutte le operazioni di ricerca lavorano sulla base del metodo Object.equals() da chiamare sugli elementi: questo metodo accetta un Object, influendo su alcuni metodi di Collection

Set: collezioni senza duplicati; nessuna coppia di elementi porta Object.equals() a dare true e non vi sono due elementi null
Non aggiunge metodi rispetto a Collection
I metodi di modifica devono rispettare la non duplicazione

List: sequenze di elementi; ha metodi per accedere a un elemento per posizione (0-based). Andrebbe scandito con un iteratore/foreach, non con indici incrementali. Fornisce un list-iterator che consente varie operazioni aggiuntive

Modalità di progettazione:
Interfacce: riportano funzionalità che definiscono il concetto
Classi astratte: fattorizzano codice comune alle varie implementazioni
Classi concrete: realizzano le varie implementazioni

Nel codice cliente:
interfacce: variabili, argomenti, tipi di ritorno
classi concrete: solo nella new, a parte casi molto particolari
classi astratte: non si menzionano praticamente mai, solo quando si volesse costruire una nuova implementazione

Classi astratte di collezioni: AbstractCollection, AbstractList, AbstractSet realizzano scheletri di classi per collezioni, corrispondenti alle relative interfacce e facilitano lo sviluppo di nuove classi aderenti alle interfacce

HashSet: usa una funzione hash per trovare un elemento in tempo costante ammortizzato (contains()); è realizzata con HashMap
TreeSet: usa un red-black tree per trovare un elemento in tempo logaritmico (contains()); è una specializzazione di SortedSet e NavigableSet (tempo log per inserimento, cancellazione e ricerca)
Oggetti equals devono avere lo stesso hashCode, ma non è detto il viceversa (anche se è opportuno per motivi di buone performance)
Eclipse genera un hashCode ragionevole (ma djb2 e murmur3 sono meglio)

TreeSet assume che esista un ordine tra gli elementi (approccio dicotomico alla ricerca); consente funzioni aggiuntive come le iterazioni in un intervallo

Realizzazione ordinamento:
approccio interno: elementi che implementano direttamente Comparable
approccio esterno: Comparator esterno fornito alla new

