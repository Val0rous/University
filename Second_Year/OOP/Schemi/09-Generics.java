Astrazioni uniformi per problemi ricorrenti:
se si hanno dei problemi ricorrenti che hanno una soluzione comune, si possono fattorizzare per astrazione in una sola classe altamente riusabile

Collection: oggetto che immagazzina il riferimento a un numero (generalmente non precisato) di altri oggetti. Consente modifiche e accessi veloci all'insieme di elementi di tale collezione

X is a type-variable
F is a code fragment working on a certain type
F<String> requires X to work on String types
F<Integer> requires X to work on Integer types

Java Generics: non hanno impatto a runtime per l'implementazione a "erasure": javac compila via i generici, quindi la JVM non li vede

Classe generica:
public class List<X>{
	private final X head;
	private final List<X> tail;
}

Classe generica C<X,Y>
X,Y sono le type-variables: possono essere usati come un qualunque tipo dentro la classe
I client devono usare tipi generici: versioni istanziate delle classi generiche:
C<String, Integer>
C<C<Object, Object>, Object>
Ogni type-variable va sostituita con un tipo effettivo, un parametro, che può essere:
una classe non generica				C<Object, String>
una type-variable definita				C<X, Y>
un tipo generico completamente istanziato	C<Object, Object>
...o parzialmente istanziato			C<Object, X>
NON con un tipo primitivo

Inferenza dei parametri: <>		(diamond symbol)
si può tentare di omettere i parametri nella new: il compilatore cerca di capire quali siano i parametri guardando gli argomenti della new e l'eventuale contesto dentro cui si trova la new. Se non ci riesce manda un errore a compile-time
Senza <> verrebbe confuso con un Raw Type, meccanismo usato per gestire il legacy con le versioni precedenti di Java
final Vector<Pair<String,Integer>> v = new Vector<>();

Interfaccia generica: interface I<X,Y>{..}
le type-variables compaiono nei metodi definiti dall'interfaccia
quando una classe le implementa deve istanziare le type-variables (o assegnarle ad altre type-variables se è generica anche lei)
Servono a creare dei contratti uniformi che non devono dipendere dai tipi utilizzati
Iteratore: oggetto usato per accedere a una sequenza di elementi (librerie Java)

Metodo generico: lavora su qualche argomento e/o valore di ritorno indipendentemente dal tipo effettivo: il tipo viene astratto in una type-variable del metodo

def:		<X1,..,Xn> ret-type method-name(formal-args){...}
call:		receiver.<X1,..,Xn>method-name(actual-args){...}
call con inferenza: stessa sintassi delle call standard (senza <>)

metodo generico (statico o non-statico) in una classe non generica (most common scenario)
metodo generico (non-statico) in una classe generica
(stessa gestione)

Java Wildcards: nuovi tipi, simili a interfacce (non generano oggetti, descrivono solo contratti); generalmente usati come tipo dell'argomento di metodi
Si usano nelle situazioni dove un metodo deve accettare come argomento non solo oggetti di tipo C<T>, ma di ogni C<S>, dove S<:T (S è più ristretto (specifico) di T)

Tipi di wildcard
Bounded (covariante):		C<? extends T>
accetta un qualunque C<S> con S<:T
void m(Vector<? extends Number> arg){...}
Bounded (controvariante):	C<? super T>
accetta un qualunque C<S> con S>:T
void m(Vector<? super Integer> arg){...}
Unbounded:				C<?>
accetta un qualunque C<S>
void m(Vector<?> arg){...}


Se non si passa un argomento compatibile si ha un errore a compile-time

