#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char str1[50];
   char str2[15];
   char *posizione;

   strcpy(str1, "Vediamo se contengo la parola che cerchi");
   strcpy(str2, "ch");

   posizione = strstr(str1, str2);

   if(posizione == '\0') {
      printf("str1 non contiene str2");
   } else {
      printf("str1 contiene str2, la prima occorrenza e\' qui: <%s>.", posizione);
   }

   printf("\n\n");
   system("pause");
   return(0);
}
