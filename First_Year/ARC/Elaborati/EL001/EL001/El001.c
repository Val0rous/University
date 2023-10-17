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
 *         ogni lettera dell�alfabeto (inglese), all�interno della frase di input.
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
	//char frase[] = "Questa e' UNA FrASe di PROVA per l'elABOrato 1";
	//char frase[] = "The quick brown fox jumps over the lazy dog";
	char frase[] = " SOno dUnQue genERAlMENtE cOnsideRate 'fonti dI enErgIA riNnovabIle' il Sole, IL Vento, il mAre, il caLoRe delLA TerRA, ovvero QUellE fonTI IL cUI uTiLizzO aTtuaLE NOn ne PRegIUdica lA diSpOnibiLita' NEl FUTurO, MentRE quellE 'non rinNovabili', Sia peR avere LUNGhI perIodI Di forMaZIONe di MOlTO Superiori A quellI Di coNsuMo aTtuaLe (iN pArticOlARe fonTI FossIli quAli pEtroliO, cARbone, gaS NaturaLe), SIa peR eSSEre PreseNTI in riSeRVE Non iNeSaurIbiLi SullA scala dEI temPi Umana (IN ParTICOlare l'iSOtOPo 235 dELl'uranIo, l'eLementO attuaLMEntE piu' utiLiZzAtO PeR pRoDurRe eneRgia nuCLEAre), sono liMItAte nEL FutUro";

	// Output
	unsigned short occorrenze[26]; //Occorrenze delle 26 lettere dell'alfabeto


	//remember to change comments ;to make them look like this
	//I'm gonna use the double slash // just for convenience
	__asm
	{
		//azzera tutti i registri
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX

		//azzera tutti gli elementi di occorrenze[]
		MOV ECX, 25
		azzera:	MOV occorrenze[ECX * 2], 0
				CMP ECX, 0
				JE finale
				DEC ECX
				JMP azzera

		//alla fine, azzera nuovamente ECX
		finale: XOR ECX, ECX
		
		//accediamo a ogni elemento del vettore con un ciclo
		ciclo:	MOV BL, frase[ECX]

				//controlla se la stringa è vuota (carattere NULL)
				CMP BL, 0
				JE fine

				//simboli prima di 'A'
				CMP BL, 65
				JB salta

				//simboli dopo 'z'
				CMP BL, 122
				JA salta

				//controllo minuscole
				CMP BL, 97
				JAE minuscole

				//controllo maiuscole
				CMP BL, 90
				JBE maiuscole

				//i simboli tra 'Z' e 'a' vengono così automaticamente esclusi

				minuscole:	SUB BL, 97
							INC occorrenze[EBX*2]
							JMP salta

				maiuscole:	SUB BL, 65
							INC occorrenze[EBX*2]
							JMP salta



				/*
				* ROBA INUTILE CHE FUNZIONAVA MA NON VENIVA ACCETTATA, SVENTURA A TE, FERRY L'ORNITORINCO!!
				//controlla le minuscole
				CMP BL, 97
				JGE controllaminuscole

				//controlla le maiuscole
				CMP BL, 65
				JGE controllamaiuscole

				//se la lettera è minuscola, incrementa il contatore della lettera corrispondente
				controllaminuscole:	CMP BL, 122
									JG salta
									MOV AL, BL
									SUB AL, 97
									INC occorrenze[EAX * 2]
									JMP salta

				//se la lettera è maiuscola, incrementa il contatore della lettera corrispondente
				controllamaiuscole:	CMP BL, 90
									JG salta
									MOV AL, BL
									SUB AL, 65
									INC occorrenze[EAX * 2]
									JMP salta
		
				*/
		//salta la lettera corrente (se è un simbolo) , o vai semplicemente avanti con l'elemento seguente del vettore (se è una lettera)
		salta:	INC ECX
				JMP ciclo		
			
		//fine ciclo
		fine:	NOP

	}
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
	
		int i;
		for (i = 0; i < 26; i++)
		{
			//only prints the entire array in this way - CHAR: NUMBER
			printf("%c: %d\n", 97 + i, occorrenze[i]);	//97 == 'a' in ASCII code
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
