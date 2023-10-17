/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 1
 Descrizione: Data una stringa contenente una frase, contare le occorrenze di
			  ogni lettera dell'alfabeto (senza distinzione tra lettere
			  maiuscole e minuscole).
			  N.B.: le lettere accentate non sono da considerare.
 
 ********************************************************************************/

#include <stdio.h>

void main()
{
	// Input: frase da valutare
	char frase[]="Questa e' UNA FrASe di PROVA per l'elABOrato 1"; 
				
	// Output
	unsigned short occorrenze[26]; //Occorrenze delle 26 lettere dell'alfabeto

	__asm
	{
	}

	// Stampa su video
	{
		int i;
		for (i=0;i<26;i++)
		{
			printf("%c: %d\n",97+i,occorrenze[i]);
		}
	}
}
