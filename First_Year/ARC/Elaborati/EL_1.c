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

/********************************************************************************
* Data una stringa contenente una frase, contare le occorrenze di ogni lettera 
* dell'alfabeto (senza distinzione tra lettere maiuscole e minuscole).
*
* INPUT: una stringa (contenente la frase), sotto forma di array di BYTE
*        terminante con 0
*
* OUTPUT: un array di 26 WORD (unsigned) contenenti il numero di occorrenze di
*         ogni lettera dell’alfabeto (inglese), all’interno della frase di input.
*
* Esempi di casi importanti da verificare:
* - Stringa vuota;
* - Stringa contenente segni di punteggiatura;
* - Stringa contenente sia lettere maiuscole che minuscole.
*
* N.B.: le lettere accentate non sono da considerare.
*********************************************************************************/

#include <stdio.h>

void main()
{
	// Input: frase da valutare
	char frase[]="Questa e' UNA FrASe di PROVA per l'elABOrato 1"; 
				
	// Output
	unsigned short occorrenze[26]; //Occorrenze delle 26 lettere dell'alfabeto


	//remember to change comments ;to make them look like this
	//I'm gonna use the double slash // just for convenience
	__asm	
	{

		XOR CL, CL

		MOV AL, frase[CL]
		; JZ vuoto

		; ciclo: MOV AL, frase[CL]
		; INC CL
		; JMP ciclo

		vuoto: NOP
	};
	
	//maybe I should run sentence from last char to first char, just to simplify conditional codes
	//maybe not

	/****************************************************************************
	* COMMENTING ASSEMBLY CODE HERE TO AVOID COMMENTING CONFLICTS
	* init ECX to 0 (ECX: loop counter)
	* 
	* ECX = 0 --> first element of array
	* checking if string is empty (NULL char == 00 h)
	* declaring a loop
	* creating a loop
	*****************************************************************************/

	// Stampa su video
	{
		int i;
		for (i=0;i<26;i++)
		{
			//only prints the entire array in this way - CHAR: NUMBER
			printf("%c: %d\n",97+i,occorrenze[i]);	//97 == 'a' in ASCII code
		}
	}
}

/*
	A C program would behave in this way:

	select a character
	count total number of repetitions in sentence
	save it in array
	repeat 26 times

	(Complexity: n^2)

	A smarter C program would:
	run through entire sentence
	when finds a character (LOL, always) increments char counter
	this way we can check punctuation symbols, too!

	if (frase[0] == NULL) -> Empty string
*/
