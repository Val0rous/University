/*
AUTHORS:    Filippo Fuzzi: filippo.fuzzi2@studio.unibo.it
            Lorenzo Prati: lorenzo.prati3@studio.unibo.it
            Leonardo Tassinari: leonardo.tassinari6@studio.unibo.it
            Francesco Valentini: francesco.valentin11@studio.unibo.it

DATE: 2020/10/01

EXERCISE TEXT (IT): Scrivere un programma C che dichiari una variabile per ogni tipo studiato
                    (usando anche i qualificatori short, long, signed e unsigned),
                    ne stampi il valore e l’occupazione di memoria in byte.
                    Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti
                    (modificatore, campoMinimo, precisione, modificatoreLunghezza).
                    Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che quest’ultima ha stampato.
                    Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato.

              (EN): Write a C program that declares a variable for every type we have studied
                    (also using short, long, signed and unsigned qualifiers),
                    printing its value and memory used (in bytes).
                    Use ALL arguments of the printf() function and ALL of the different variants
                    (modifiers, minimumField, precision, lengthModifier)
                    For every call to the printf() function, print to the screen the number of printed characters, too.
                    Also, print the minimum and maximum values possible for every used type.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    //Declaring char variables
    char Char = 'H';
    unsigned char UnsignedChar = 'L';

    //Declaring int variables
    short int ShortInt = -54;
    unsigned short int UnsignedShortInt = 54u;

    int Int = 36;
    unsigned int UnsignedInt = 36u;

    long int LongInt = -2020l;
    unsigned long int UnsignedLongInt = 2020ul;

    //Declaring float variables
    float Float = -3.454564f;

    //Declaring Double variables
    double Double = 3050.446457;
    long double LongDouble = 808784.14488234;

    //Printing variable type, value, occupied bytes, minimum value, maximum value, number of printed characters of the previous printf(), including the tabulation
    printf("Type:\t\t\tValue:\t\tOccupied Bytes:\t\tMin:\t\tMax:\t\tPrinted Characters:\n");
    //with the first printf we store and print the value of printed characters of the second printf where all the information regarding the variable type are printed
    printf("%d\n", printf("Char\t\t\t%c\t\t%d\t\t\t%d\t\t%d\t\t", Char, sizeof(Char), CHAR_MIN, CHAR_MAX));
    //reapeating for each type
    printf("%d\n", printf("Unsigned Char\t\t%c\t\t%d\t\t\t%d\t\t%d\t\t", UnsignedChar, sizeof(UnsignedChar), 0, UCHAR_MAX));

    printf("%d\n", printf("Short Int\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t", ShortInt, sizeof(ShortInt), SHRT_MIN, SHRT_MAX));


    printf("%d\n", printf("Unsigned Short Int\t%d\t\t%d\t\t\t%d\t\t%u\t\t", UnsignedShortInt, sizeof(UnsignedShortInt), 0, USHRT_MAX));


    printf("%d\n", printf("Int\t\t\t%d\t\t%d\t\t\t%d\t%d\t", Int, sizeof(Int), INT_MIN, INT_MAX));

    printf("%d\n", printf("Unsigned Int\t\t%d\t\t%d\t\t\t%d\t\t%u\t", UnsignedInt, sizeof(UnsignedInt), 0, UINT_MAX));


    printf("%d\n", printf("Long Int\t\t%d\t\t%d\t\t\t%d\t%u\t", LongInt, sizeof(LongInt), LONG_MIN, LONG_MAX));


    printf("%d\n", printf("Unsigned Long Int\t%d\t\t%d\t\t\t%d\t\t%u\t", UnsignedLongInt, sizeof(UnsignedLongInt), 0, ULONG_MAX));


    printf("%d\n", printf("Float\t\t\t%f\t%d\t\t\t%e\t%e\t", Float, sizeof(Float), FLT_MIN, FLT_MAX));


    printf("%d\n", printf("Double\t\t\t%f\t%d\t\t\t%Lg\t%Lg\t", Double, sizeof(Double), DBL_MIN, DBL_MAX));


    printf("%d\n\n", __mingw_printf("Long Double\t\t%.9Lg\t%d\t\t\t%Lg\t%Lg\t", LongDouble, sizeof(LongDouble), LDBL_MIN, LDBL_MAX));

    printf("Examples Format specifiers: int=%d, float=%f\n", Int, Float);
/*Examples of specifiers
%d      Normal number,
%5d     right align and add spaces to display at least 5 characters;
%05d    right align and add zeros to display at least 5 characters;

%-5d    left (-) align and add spaces to display at least 5 characters;
%5.3d   right align, add spaces to display at least 5 characters and display at least 3 digits (adding zeros at the beginning);
%x      print an int variable in hex format;
%o      print an int variable in octal format;

%10.3f  right align, add spaces to display at least 10 characters and display at least 3 decimals (adding zeros at the end);
%10.3e  right align, add spaces to display at least 10 characters and 3 decimals (doesn't add zeros at the end because it's a number written in exp form);
%-10g   right align, add spaces to display at least 10 characters, hence all of the characters of a float (8) + 2 spaces at the end.

%+d     specifies always the sign
%*d     specifies the value of the minimum field with a placeholder that has to be mentioned after the comma right before the referred value
% d     puts a space if the first value isn't a sign

Escape sequences

\n new line
\t tab
\\ print \
\' print '
\a plays the sound that Teacher Filippo likes :)



*/
    printf("|%d|\n|%5d|\n|%05d|\n", Int, Int, Int);

    printf("|%-5d|\n|%5.3d|\n|%x|\n|%o|\n", Int, Int, Int, Int);

    printf("|%10.3f|\n|%10.3e|\n|%-10g|\n", Float, Float, Float);

    printf("|%+d|\n|%*d|\n|% d|\n\a", Int, 3,Int, Int);



    system("pause"); //Pauses the program to avoid it being executed too fast

    return 0;
}
