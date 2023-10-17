#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argn, char *argv[])
{
	int valoreInput, valoreOutput, flag_ok, flag_numero, length, i;
	char *input1;
    flag_ok = 0;
	flag_numero = 1;

	printf("%d argomenti ricevuti\n", argn);
	printf("Nome del programma: \n\t%s\n", argv[0]);

	if (argn>1){
        //Check if the input is a number
        input1 = argv[1];
        length = strlen(input1);
        for (i=0; i<length; i++){
            if (!isdigit(input1[i])){
                flag_numero = 0;
            }
        }

        //Compute the final value
        if (flag_numero==1){
            valoreInput = atoi(input1);
            printf("\nIl valore di input e\': %d\n", valoreInput);
            valoreOutput = ((valoreInput*2)+3)*4;
            flag_ok = 1;
        }
	}

	if (flag_ok==0){
        printf("\n\nNO INTEGER INPUT!\n\n");
        system("pause");
        return 1; //Note return ONE!
	}
	printf("\nIl valore di output e\': %d\n", valoreOutput);
	printf("\n\n");
	system("pause");
    return 0; //Note return ZERO!
}
