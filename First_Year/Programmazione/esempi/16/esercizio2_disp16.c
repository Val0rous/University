#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STUD 500
#define N_MAT 5
#define VOTOMIN 1
#define VOTOMAX 11
#define SUFF 6
#define TRUE 1
#define FALSE 0

// Studenti
struct
{	char cognome[50];
	char nome[50];
	int matricola;
	int anno_di_corso;
	float voto[N_MAT]; //elenco dei voti dello studente nelle diverse materie
}stud[MAX_STUD];

// Materie
struct
{	int codice;
	char descr[50];
	char docente[50];
} materia[N_MAT] = {{1,"Lettere","Rossi"},{2,"Matematica","Monti"},{3,"Inglese","Smith"},{4,"Diritto","Bianchi"},{5,"Fisica","Verdi"}};


int main()
{

	float media, somma;
	char  next, trovato;
	int  i, j, nStud, matricola, num_insuff;
	next = 'S';

	// inizializzazione dimensioni
	do
	{
		printf("Quanti studenti (max %d)? ",MAX_STUD);
		scanf("%d",&nStud);
		fflush(stdin);
	}while (nStud>MAX_STUD || nStud<=0);

	// inserimento studenti e voti
	printf("\n\nInserimento STUDENTI e VOTI...\n");

	for (i=0; i<nStud; i++)
	{
		printf("\nStudente[%d]:\n", i);
		printf("Matricola: ");
		scanf("%d",&stud[i].matricola);
		fflush(stdin);
		printf("Nome: ");
		scanf("%s",stud[i].nome);
		fflush(stdin);
		printf("Cognome: ");
		scanf("%s",stud[i].cognome);
		fflush(stdin);
		printf("  Voti studente:\n", i);

		for(j=0; j<N_MAT; j++)
		{
			do
			{
				printf("\t%s: ",materia[j].descr);
				scanf("%f",&stud[i].voto[j]);  //inserisce i voti per ciascuna materia nel vettore dei voti dello studente i-esimo
				fflush(stdin);
				if (stud[i].voto[j] > VOTOMAX || stud[i].voto[j] < VOTOMIN)
					printf("\nErrore di inserimento!\n");
				else
     				break;
			}while (1);
		}
	}

	// Inserimento matricola da cercare
	do
	{
		trovato = FALSE;
		do
		{
			printf("\n\nInserisci la matricola dello studente da ricercare: ");
			scanf("%d",&matricola);
			fflush(stdin);

			for (i=0; i<nStud && !trovato; i++)
			{
				if (stud[i].matricola==matricola)
					trovato=TRUE;
			}

			if (!trovato)
            {
				printf("La matricola inserita non esiste.");
                do
                {
                    printf("\n\nVuoi eseguire un\'altra ricerca (S/N)\?");
                    scanf("\n%c",&next);
                    fflush(stdin);
                }while ((toupper(next))!='S' && (toupper(next))!='N');
            }
		}
		while (!trovato && toupper(next)=='S');

		printf("\n");

		if (trovato){
            // Ricerca insufficienze e calcolo media
            somma = 0;
            num_insuff = 0;
            printf("Materie insufficienti:\n");

            i--;	// indice della matricola cercata

            for(j = 0; j < N_MAT; j++)
            {
                somma += stud[i].voto[j];
                if (stud[i].voto[j] < SUFF)	// verifica materie insufficienti
                {
                    printf("%s (Prof. %s)  %.1f\n",materia[j].descr, materia[j].docente, stud[i].voto[j]);
                    num_insuff++;
                }
            }

            if (!num_insuff)
                printf("Nessuna materia insufficiente");

            // calcolo media
            media = somma/N_MAT;
            printf("\nMedia: %.1f\n",media);

            do
            {
                printf("\n\nVuoi eseguire un\'altra ricerca (S/N)\?");
                scanf("\n%c",&next);
            }while ((toupper(next))!='S' && (toupper(next))!='N');
		}
	}
	while ((toupper(next))=='S');

	return 0;
}

