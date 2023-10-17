#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   char *p_str3;
   int ret;

   strcpy(str1, "ACCDEF");
   strcpy(str2, "AbCDEF");

   ret = strncmp(str1, str2, 3);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }

   p_str3 = strrev(str2);
   printf("\n\nstr2 after strrev: %s\n\n", p_str3);

   printf("\n\n");
   system("pause");
   return(0);
}
