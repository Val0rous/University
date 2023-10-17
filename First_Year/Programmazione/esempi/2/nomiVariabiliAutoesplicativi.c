#include <stdio.h>
#include <stdlib.h>

int main()
{

    // definire variabili con nomi auto-esplicativi
	int numeroAnniFiglio = 33;
	int numeroAnniPadre = 65;
	int numeroAnniMadre = 63;
    printf("Io ho %d anni, mio padre ha %d anni, mia madre ha %d anni.\n", numeroAnniFiglio, numeroAnniPadre, numeroAnniMadre);
    printf("Tra me e mio padre ci sono %d anni, tra me e mia madre %d anni, tra mio padre e mia madre %d anni\n", abs(numeroAnniPadre-numeroAnniFiglio), abs(numeroAnniMadre-numeroAnniFiglio), abs(numeroAnniMadre-numeroAnniPadre));

	system("pause");
	return 0;
}
