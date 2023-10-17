// Author: Filippo
// Date: 20191014
// Description: Insert time in the format hh:mm

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch;
	char h1;
    char h2;
    char p1;
    char m1;
    char m2;
    int counter1 = 1;

	puts("Inserire un orario in formato hh:mm: \n");

	while ((ch=getchar())!=EOF && ch!='\n'){
            if (counter1==1 && (ch=='0' || ch=='1' || ch=='2')){
                h1 = ch;
                counter1 = counter1+1;
            } else if (counter1==2 && (ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')){
                h2 = ch;
                counter1 = counter1+1;
            } else if (counter1==3 && (ch=='.' || ch==':')){
                p1 = ch;
                counter1 = counter1+1;
            } else if (counter1==4 && (ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5')){
                m1 = ch;
                counter1 = counter1+1;
            } else if (counter1==5 && (ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9')) {
                m2 = ch;
                counter1 = counter1+1;
            }
    }

    printf("L\'orario inserito e\': %c%c%c%c%c\n", h1, h2, p1, m1, m2);

	return 0;
}
