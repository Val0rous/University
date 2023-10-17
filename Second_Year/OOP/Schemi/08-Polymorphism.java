class B extends A{..}
gli oggetti di B rispondono a tutti i messaggi previsti dalla classe A, e potenzialmente a qualcuno di più
un oggetto di B può essere passato dove se ne aspetta uno della classe A, senza problemi di typing
in Java si considera B come un sottotipo di A a tutti gli effetti

NO ereditarietà multipla (class C extends D1,D2 ..)
Si usano le interfacce multiple!

Polimorfismo con:
interfacce:
contratto
si possono far aderire facilmente al contratto classi esistenti
classi
contratto + comportamento
ereditarietà singola
in genere ci si aderisce per costruzione dall'inizio

objectName instanceof ObjectClass	//ispeziona il tipo a runtime

Conversione tra classi:
Upcast:	sottoclasse → superclasse (spesso automatica)
Downcast:	superclasse → sottoclasse (potrebbe fallire)

Classi astratte: misto tra interfacce (contratto) e classi (comportamento completo), descrivono un comportamento parziale: alcuni metodi sono dichiarati ma non implementati. Non sono istanziabili. Possono essere estese e completate, per poi generare gli oggetti da queste nuove classi
Usate spesso nei pattern Template Method: un metodo definisce un comportamento comune (spesso final) ma usa metodi da concretizzare in sottoclassi.
abstract class C ... {...}
abstract int m(int a, String s);		//metodo astratto (senza body)

Le classi astratte possono definire campi, costruttori, metodi (concreti e astratti), definendo il loro livello di accesso. Possono estendere da classi astratte o concrete. Possono implementare interfacce, senza doverne ottemperare il contratto. Una classe concreta è tale se e solo se implementa tutti i metodi definiti

Le classi astratte NON hanno ereditarietà multipla!!!

class C extends D implements I,J,K,L {..}
C deve implementare tutti i metodi dichiarati in I,J,K,L e super-interfacce; può fare overriding dei metodi (non finali) definiti in D e superclassi

abstract class CA extends D implements I,J,K,L {..}
CA non è tenuta a implementare alcun metodo; può implementare qualche metodo per definire un comportamento parziale

Autoboxing dei tipi primitivi: simula l'equivalenza tra tipi primitivi e loro Wrapper
se trova un primitivo dove ci si attende un oggetto → BOXING
se trova un wrapper dove ci si attende un primitivo → DEBOXING
Anche i tipi primitivi sono così usabili con Object[]

void m(int a, float b, Object... args){...}		//variable arguments
ultimo argomento del metodo:	Type... argname
argname è un Type[]
chi chiama il metodo non chiama un array, ma passa una lista di argomenti di tipo Type
funziona automaticamente con polimorfismo, autoboxing, instanceof, ...

