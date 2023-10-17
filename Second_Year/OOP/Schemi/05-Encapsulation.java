indentazione: 4 caratteri
linee lunghe max 90 caratteri

//  single line comment
/*  multi line comment, for sections */
/** multi line comment, generating documentation */

one variable definition per line, better if at method start
always better to initialize variables
one instruction per line

Egyptian brackets
no assignments inside expressions
disambiguate priority operators with ()

Classes, Interfaces:	start with uppercase
methods, fields, variables:		start with lowercase
structuredName → camelCasing
CONSTANT_FIELDS → all uppercase with underscore as separator

static fields:	public, protected, private
instance fields:	public, protected, private
constructors:	public, protected, private
methods:		grouped by role

Decomposizione: isolare i sottoproblemi più semplici, diminuendo il più possibile le dipendenze tra classi
livelli di decomposizione:
packages (whole program)
classes  (package or program)
methods  (class)

Incapsulamento: public solo i metodi/costruttori che servono a interagire con le istanze
il resto deve essere private

Ogni classe deve definire un metodo toString(), automaticamente chiamato quando si concatenano stringhe con l'operatore +

non–boolean getter:	T getXYZ(){...}
boolean getter:		boolean isXYZ(){...}
setter:			void setXYZ(T xYZ){...}