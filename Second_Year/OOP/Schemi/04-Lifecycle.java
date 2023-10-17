//static code
class.method(args)
class.field

start with lowercase: packages
				methods
				fields
start with Uppercase:	Class

return this;		//schema fluente: concatenare creazione di oggetti e inizializzazione (build())

XYZ: 	classe che genera oggetti
XYZs:	classe con proprietà statiche relative

Default constructor: ClassName()		(implicitly defined if no other constructors are defined)
(no return type)
Custom constructor:  ClassName(args){/*initializing fields*/}

new:
creates object with all fields having default value
executes constructor code (this points to created object)
new returns this reference

this(..)
chiama un altro costruttore
può essere solo la prima istruzione
consente di riusare il codice di altri costruttori

Constructor Overloading
calls a constructor with same number of compatible args
if there is none, gives an error

package n1.n2....nj → subdirectory n1/n2/../nj from a CLASSPATH directory (enviroment variable)

package pname;
//if not defined, default package is applied

public:	visibile da tutte le classi
private:	visibile solo nella classe corrente
final:	non modificabile (anche oggetti)

void drawPixel(int x, int y, int color);
void advancePosition();
boolean isCompleted();
int computeIterations();

