Definisce una nuova classe specializzandone una esistente, ereditando i suoi campi e metodi (non quelli privati, non visibili). Si possono modificare o aggiungere campi/metodi, riusando codice già scritto (e testato)

Elementi chiave OOP:
incapsulamento
interfacce
ereditarietà

class C extends D {..}
C eredita campi/metodi/costruttori non privati di D
eredita anche campi/metodi privati, ma non sono accessibili da C
i costruttori di D non sono direttamente richiamabili con la new, bisogna sempre definirne di nuovi
D superclasse / classe base 	/ classe padre
C sottoclasse / specializzazione / classe figlio
Si possono estendere classi anche senza averne il sorgente: basta il codice binario

super(args); //chiama un costruttore non privato della superclasse
se non viene chiamato, si chiama il costruttore di default del padre

protected: intermediate visibility level between public and private
		property is accessible from current class, from subclass,
		and from subclasses of subclasses (recursively)
protected consente accesso anche da tutto il package: è meno stringente rispetto al livello di default (package protected)
consente alle sottoclassi di accedere a informazioni della sottoclasse che non si vogliono far vedere agli user
rimpiazza spesso un precedente private

overriding dei metodi della superclasse: si modificano alcuni emtodi disponibili; si può invocare la versione del padre con super() o super.field

I metodi overridden si riportano anche nella sottoclasse (UML)
Meglio evitare i campi protected: meglio sempre privati!
Utilizzare getter o setter protected se serve!

Catena di sottoclassi: ogni classe introduce alcuni campi, che si aggiungono a quelli della superclasse formando la struttura di un oggetto in memoria
La singola classe deve definire tutti i costruttori necessari
Ogni costruttore deve:
chiamare l'opportuno costruttore padre come prima istruzione (super()), altrimenti verrà chiamato il costruttore di default (se c'è)
inizializzare propriamente i campi localmente definiti
Eseguendo una new:
si crea l'oggetto con tutti i campi non inizializzati
il codice dei costruttori viene eseguito dalle superclassi in giù

super.m(..args..) //esegue il metodo m della superclasse (o di quella più specifica che lo definisce). se tale metodo al suo interno chiama un altro metodo n (su this) si ritorna a considerare la versione più specifica a partire dalla classe di partenza C

tabella dei metodi virtuali (vtable) (call table) (dispatch table): risolve le chiamate con late binding

Si possono dichiarare final anche metodi e intere classi. Metodi final NON possono avere overriding. Classi final NON possono essere estese

Overriding di un metodo M:
la nuova versione deve avere la stessa signature
si può estendere la visibilità di un metodo
non su può limitare la visibilità di un metodo
si può indicare il metodo final

Ogni classe eredita (indirettamente) da Object (radice della gerarchia di ereditarietà di Java)
