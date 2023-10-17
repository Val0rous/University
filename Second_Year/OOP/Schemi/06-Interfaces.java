Forme di dipendenza:
Associazione: uses
un oggetto ne usa un altro
Composizione: has-a
un oggetto ne aggrega altri
(versione più forte dell'associazione)
Aggregazione: gli oggetti composti hanno vita propria senza l'esistenza di A
Specializzazione: is-a
una classe ne specializza un'altra

UML notation:
- privateMethod()	privateField
+ publicMethod()		publicField
# protectedMethod()	protectedField
staticMethod()		staticField
<< interface >> Name
<<bind>> X: TypeVariable<>
dei metodi si riporta solo la signature, con sintassi:
name(arg1: type1, arg2: type2, ..): return_type

Notazione:
completa: implementazione
parziale: design (solo parte pubblica)

class C implements I{..}

Un'interfaccia è un tipo di dato, include solo un insieme di intestazioni di metodi (return_type methodName(args);) (senza visibilità public/private)
La classe C deve definire il corpo di tutti i metodi dichiarati in I
Sono consentite solo le operazioni delle chiamate dei metodi definiti dall'interfaccia. Gli oggetti delle classi che implementano l'interfaccia sono i valori/oggetti del tipo Interface
Se C implementa I, allora ogni istanza di C può essere passata dove il programma si attende un elemento del tipo I (principio di sostitubilità di Liskov) (I è più generale di C, ma fornisce meno funzionalità)

Polimorfismo:
Inclusivo: subtyping
(applicazione del principio di sostituibilità)
Una funzionalità realizzata per lavorare su valori/oggetti di A può lavorare con qualunque valore/oggetto di B (se B estende la classe A, o se B implementa l'interfaccia A)
Parametrico: genericità
Una funzionalità (classe o metodo) generica lavora in modo uniforme su valori/oggetti indipendentemente dal loro tipo: tale tipo diventa praticamente un parametro addizionale

Late binding (dynamic binding) (collegamento ritardato): chiamate a metodi non-statici: il codice da eseguire viene scelto dinamicamente in base alla classe dell'oggetto passato come argomento. Il tipo statico può essere diverso dal tipo run-time

Early (static) binding: metodi statici o finali
Late (dynamic)binding:  tutti gli altri casi

Una interface NON può contenere:
campi istanza
corpo di un metodo istanza
costruttori
Una interface potrebbe includere anche campi statici e metodi statici (con corpo), e in Java 8 i metodi possono avere una implementazione di default

class C implements I1,I2,I3{..}
C implementa tutte le classi, fornendo un corpo per ciascuna di esse, una volta sola per tutti i metodi in comune. Le istanze di C hanno tipo C, I1, I2, I3

interface I extends I1,I2,I3{..}
I definisce certi metodi, oltre a quelli delle altre 3 interfacce.
Una classe C che implementa I deve fornire un corpo per tutti i metodi indicati in I, I1, I2, I3. Le istanze di C hanno tipo C, I, I1, I2, I3



Library Interfaces:
java.lang.Appendable
java.io.DataInput
java.io.Serializable (tag interface)
javax.swing.Icon
class ImageIcon implements Icon, Serializable, Accessible{...} (multiple implementations)
interface ObjectInput extends DataInput{...} (interface extensions)

