#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
   char srcA[40];
   char srcB[40];
   char destA[12];
   char destB[60];

   strcpy(srcA, "This is a test!");
   strcpy(srcB, "..VERIFICATION");

   memset(destA, '\0', sizeof(destA)); /*function memset() used to clear the memory location*/
   strcpy(srcA, "This is a test!");
   strncpy(destA, srcA, 10);
   strcpy(destB, destA);

   strcat(destB, srcB);

   printf("Final copied string: |%s|.\n", destA);
   printf("Final appended string: |%s|.\n", destB);

   printf("\n\n");
   system("pause");
   return(0);
}
