#include <stdio.h>
#define LIM 100

int getline(char[], int);
int ricerca_pattern(char[]);

char pattern[] = "aba";
int trovato=0; // inizializzazione ridondante

int main()
{
    // cerca le occorrenze di un pattern dentro una stringa
    char line[LIM];
    printf("Inserisci il testo in cui ricercare il pattern ");
    printf("una linea per volta.\nStringa vuota per terminare.\n");
    while (getline(line,LIM) > 0)
    {
    if (ricerca_pattern(line) >= 0)
        printf("%s\n", line);
        printf("\n Ho trovato %d occorrenze di %s\n", trovato, pattern);
    }
    return 0;
}

int getline(char s[], int lim)
{
    /* legge una linea di input nel vettore s,
    fino a un massimo di lim caratteri;
    ritorna la lunghezza della stringa */
    int c, i = 0;
    while(lim > 1 && (c=getchar()) != '\n')
    {
        s[i] = c;
        i++;
        lim--;
    }
    s[i] = '\0';
    return i;
}

int ricerca_pattern(char s[])
{
    /* cerca la stringa pattern dentro s */
    int i, j, k, ret=-1;
    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; pattern[k] != '\0'; j++, k++){
            if (s[j] != pattern[k]){
                break;
            }
        }
        if (pattern[k] == '\0')
        {
            trovato++;
            ret=i;
        }
    }
    return ret;
}
