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
	char frase[] = "Questa e' UNA FrASe di PROVA per l'elABOrato 1";

	// Output
	unsigned short occorrenze[26]; //Occorrenze delle 26 lettere dell'alfabeto


	//remember to change comments ;to make them look like this
	//I'm gonna use the double slash // just for convenience
	__asm
	{
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX
		XOR EDX, EDX

		//setting all elements of occorrenze[] to 0 (INIT)
		azzera: MOV DL,16
				MOV EAX, ECX
				MUL DL
				XCHG EAX,ECX
				MOV occorrenze[ECX],0
				XCHG EAX,ECX
				XOR EAX,EAX
				INC ECX
				CMP ECX, 26
				JB azzera



		//init ECX and EAX to 0 (ECX: loop counter) (EAX: main register)
		//all registers are now 0
		XOR EAX,EAX
		XOR EBX,EBX
		XOR ECX,ECX
		XOR EDX,EDX

		//LEA EBX,frase

		//MOV AL, [EBX]	//first element of array (by pointer)

		//creating a loop to access all array elements
		/*
		ciclo:  MOV AL, frase[ECX*8]

				CMP AL,0
				JE fine			//checking if string is empty (NULL char == 00h)

				MOV BL, AL		//copies value
				SUB AL,97
		
				CMP AL,0
				JB maiuscole	//uppercase char come first in ascii code
				//JNB minuscole	//other scenario	//useless

				minuscole:	CMP AL,25
							JA salta			//skips value
							MOV EDX,ECX
							XOR ECX,ECX
							MOV BH,16
							MUL BH
							MOV ECX,EAX
							INC occorrenze[ECX]	//updates counter of the right letter

				maiuscole:	ADD AL,32			//normalizing value
							CMP AL,0
							JB salta			//skips value
							CMP AL,25
							JA salta			//skips value
							MOV EDX, ECX
							XOR ECX, ECX
							MOV BH,16
							MUL BH
							MOV ECX, EAX
							INC occorrenze[ECX]
		
				MOV ECX,EDX
				XOR EDX,EDX
				MOV AL,BL




		salta:	INC ECX
				JMP ciclo		//end of loop


		fine:   NOP				//does nothing (No OPeration)
		*/
		
		ciclo: MOV AL, frase[ECX*8]

			   //null character --> end of string
			   CMP AL,0x00
			   JE fine

			   CMP AL,0x61
			   JBE minuscole

			   CMP AL,0x41
			   JBE maiuscole

			   minuscole:	MOV AH, 0x61
			   ciclominuscole:	CMP AL,AH
			   //controlla carattere per carattere con un ciclo, that's the fastest way to do this
				//now I'm too tired, and it's too late... Good luck future me!

							
			   maiuscole:	MOV AH, 0x41
							
						



			   //loop management stuff
			   INC ECX
			   JMP ciclo

		//end of loop (No OPeration)
		fine: NOP

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
		for (i = 0; i < 26; i++)
		{
			//only prints the entire array in this way - CHAR: NUMBER
			printf("%c: %d\n", 97 + i, occorrenze[i]);	//97 == 'a' in ASCII code
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
