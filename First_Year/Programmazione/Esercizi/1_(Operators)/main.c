/*
AUTHORS:    Filippo Fuzzi: filippo.fuzzi2@studio.unibo.it
            Lorenzo Prati: lorenzo.prati3@studio.unibo.it
            Leonardo Tassinari: leonardo.tassinari6@studio.unibo.it
            Francesco Valentini: francesco.valentin11@studio.unibo.it

DATE: 2020/10/10

EXERCISE TEXT (IT):
Scrivere un programma C che mostri l'utilizzo di tutti gli operatori studiati.

Il programma deve inoltre mostrare:
    il comportamento scorretto che si ottiene utilizzando tipi non appropriati alla dimensione delle variabili,
    quello che si ottiene usando più operatori con side effects all'interno della stessa istruzione,
    quello che si ottiene quando le regole di conversione implicita sono applicate e
    quando si supera il range dei valori disponibili per un tipo di dato.

Il programma deve poi mostrare l'utilizzo di tutte le funzioni matematiche della libreria math.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a = 0, b = 0, c = 0; //Declaring and initializing example variables


//we divided the program in chapter callable by the user
//because otherwise it would have been a huge wall of text

//chapter 1
void c1(){
    printf("\n\n");
    //ARITHMETICAL operators
    printf("ARITHMETICAL OPERATORS\n\n");

    //Prints value of a
    printf(" a = %d\n\n", a);

    //Variable a is always reset so as to show changes in its value
    a = 0;
    printf("++a increments a before accessing the variable so returns a = %d\n", ++a);
    //a is 1

    a = 0;
    printf("a++ returns %d ", a++);
    //a is 0
    printf("then a is incremented: a = %d\n", a);
    //a is 1

    a = 0;
    printf("--a decrements a before accessing the variable so returns a = %d\n", --a);
    //a is -1

    a = 0;
    printf("a-- returns %d ", a--);
    //a is 0
    printf("then a is decremented: a = %d\n", a);
    //a is -1

    //Variable a is reset to 1 to show changes of its sign
    a = 1;
    printf("If a=1, +a specifies the constant is positive so returns a = %d\n", +a);
    //a is 1

    printf("If a=1, -a inverts the constant sign and returns a = %d\n", -a);
    //a is -1

    //Initializing variables a and b so as to show effects of mathematical operations
    a = 7; b = 5;
    //Prints values of a and b
    printf("\n a = %d and b = %d\n\n", a, b);

    printf("a + b returns %d\n", a + b);
    //Sum is 12
    printf("a - b returns %d\n", a - b);
    //Difference is 2
    printf("a * b returns %d\n", a * b);
    //Product is 35
    printf("a / b returns %d\n", a / b);
    //Quotient is 1: if dividing two integers, the result will be truncated
    printf("a %% b returns %d\n", a % b);
    //Remainder is 2 - only works with integers
    printf("a = b assigns to a the value of b, so returns a = %d\n", a = b);
    //a is now 5

    //Values are reset before applying operations
    a = 7; b = 5;
    a += b;
    printf("a += b means a = a + b so returns a = %d\n", a);
    //a is now 12

    a = 7; b = 5;
    a -= b;
    printf("a -= b means a = a - b so returns a = %d\n", a);
    //a is now 2

    a = 7; b = 5;
    a *= b;
    printf("a *= b means a = a * b so returns a = %d\n", a);
    //a is now 35

    a = 7; b = 5;
    a /= b;
    printf("a /= b means a = a / b so returns a = %d\n", a);
    //a is now 1

    a = 7; b = 5;
    a %= b;
    printf("a %%= b means a = a %% b so returns a = %d\n", a);
    //a is now 2
}




//chapter 2
void c2(){
    printf("\n\n");
    //Showing the usage of RELATIONAL operators, which confront the values of two expressions and return 0 (false) or 1 (true), with some examples
    printf("\n\nRELATIONAL OPERATORS (return 0=False, 1=True)\n\n");
    a = 7; b = 5;

    printf("a>b means a is bigger than b, returns %i\n",a>b);
    printf("a<b means a is smaller than b, returns %i\n",a<b);
    printf("a>=b means a is bigger or equal to b, returns %i\n",a>=b);
    printf("a<=b means a is smaller or equal to b, returns %i\n",a<=b);
    printf("a==b means a is equal to b, returns %i\n",a==b);
    printf("a!=b means a is NOT equal to b, returns %i\n",a!=b);

    //Showing the usage of LOGICAL operators, which return 0 (false) or 1 (true), with some examples
    printf("\n\nLOGICAL OPERATORS (a=1, b=0)\n\n");

    a=1; b=0;
    printf("Consider a and b two expressions\n");
    printf("a && b means logic AND, returns %i\n",a&&b);
    printf("a || b means logic OR, returns %i\n",a||b);
    printf("!a means logic NOT, returns (on a):%i\n",!a);

    //Showing the usage of BITWISE operators, which return 0 (false) or 1 (true), with some examples
    printf("\n\nBITWISE OPERATORS\n\n");

    printf("& means logic AND bit per bit\n");
    printf("| means logic OR bit per bit\n");
    printf("^ means logic XOR bit per bit\n");
    printf(">> means right shift\n");
    printf("<< means left shift\n");
    printf("~ means logic NOT bit per bit\n");

    //Examples of bitwise operators
    a=52, b=89;
    printf(" a = 52 [00110100]\n b = 89 [01011001]\n\n");
    printf("a&b returns %d\n", a&b);
    printf("a|b returns %d\n", a|b);
    printf("a^b returns %d\n", a^b);
    printf("a>>3 returns %d\n", a>>3);
    printf("a<<3 returns %d\n", a<<3);
    printf("~a returns %d\n", ~a);
}
//chapter 3
void c3(){
    printf("\n\n");
    //Operators with SIDE EFFECTS
    printf("\n\nSIDE EFFECTS\n\n");

    printf(" a = 7, b = 5\n\n");

    //When you have two operators with side effects in one instruction the output is unpredictable and depends on the compiler

    a=7, b=5;
    c = (a++) + b;
    //a could be incremented before or after the sum

    /*this could be read as
        c = a + b;
        a++;

        or

        a++;
        c= a + b;
    */

    printf("c = (a++) + b | The value of c is unpredictable, in this case c = %d\n", c);

    a=7, b=5;
    c = (a++) * b;
    printf("c = (a++) * b | The value of c is unpredictable, in this case c = %d\n", c);

    //What happens when OVERFLOW occurs?
    printf("\n\nOVERFLOW\n\n");

    //Overflowing int, short and float with values too big for them to be stored correctly
    int int01 = 929192191291299123;
    short int shortInt01= 567188181;
    float float01 = 81919191919191919;

    //int is overflowed and its value becomes negative (value reaches max value and starts back from negatives)
    printf("The integer variable int01 is declared equal to 929192191291299123. We print int01:\n int01 = %d\n", int01);
    printf("The value of int01 exceeds the limit range of the integer type (overflow)\n\n");

    //Same for a short int
    printf("The short integer variable shortInt01 is declared equal to 567188181. We print shortInt01:\n shortInt01 = %d\n", shortInt01);
    printf("The value of shortInt01 exceeds the limit range of the short integer type (overflow)\n\n");


    printf("The integer variable float01 is declared equal to 81919191919191919. We print float01:\n float01 = %d\n", float01);
    printf("The value of float exceeds the limit range of the float type (overflow)\n\n");

    //CASTING: changing variable type in a statement
    printf("\n\nCASTING\n\n");

    //float to int
    float01 = 57.98;
    printf(" float01 = %.2f\n", float01);
    printf("(int)float01 will only return the decimal part of float01 | float01 = %d\n", (int)float01);

    //int to float
    int m=80, n=36;
    float res;
    printf("\nGiven m = %d (int type), n = %d (int type)\n\n", m,n);
    res = m/n;
    printf("m/n returns %f\n", res);
    res = m/(float)n;
    printf("\nm/(float)n returns %f\n", res);
    res = (float)m/n;
    printf("\n(float)m/n returns %f\n", res);
    res = m/36.0;
    printf("\nm/36.0 returns %f\n", res);
}
//chapter 4
void c4(){
    printf("\n\n");
    //IMPLICIT CONVERSION
    char char01 = 'h';
    double double01 = 988998;
    int int01 = 123;
    float float01 = 567.8;
    printf("IMPLICIT CONVERSION (right cases):\n");

    printf("\n\nGiven the variables int01 = %d, char01 = %c, float01 = %f, double01 = %lf \n\n", int01, char01, float01, double01);

    int01 = char01;
    printf("int01 = char01 | int01 = %d\n", char01);
    //char01's value will be converted to type int

    int01 = 123;
    float01 = int01;
    printf("float01 = int01 | float01 = %f\n", float01);
    //int01's value will be converted to type float

    float01 = 567.8;
    double01 = float01;
    printf("double01 = float01 | double01 = %lf\n\n", double01);
    //float01's value will be converted to type double

    char01 = 'h';
    double01 = 988998;
    int01 = 123;
    float01 = 567.8;

    //When implicit conversion goes wrong
    printf("And wrong cases:\n");

    printf("char01 = int01 | char01 = %c \n", char01);
    //Value is not assigned

    int01 = 123;
    int01 = float01;
    printf("int01 = float01 | int01 = %d\n", int01);
    //Decimal part is lost

    //math.h LIBRARY FUNCTIONS
    printf("\n\nFunctions of Math.h library\n\n");
    double value1 = 21.7;
    int value2 = 2;
    int value3 = -17;

    //Round down
    printf("floor(%.1f) returns %.f\n", value1, floor(value1));

    //Round up
    printf("ceil(%.1f) returns %.f\n", value1, ceil(value1));

    //Floating point remainder of a division between two floats
    printf("fmod(%.1f, %d) returns %f\n", value1, value2, fmod(value1, value2));

    //Exponentiation
    printf("pow(%.1f, %d) returns %f\n", value1, value2, pow(value1, value2));

    //Trigonometric functions
    printf("sin(%.1f) returns %lf\n", value1, sin(value1*(M_PI/180)));
    printf("cos(%.1f) returns %lf\n", value1, cos(value1*(M_PI/180)));
    printf("tan(%.1f) returns %lf\n", value1, tan(value1*(M_PI/180)));

    //Inverse trigonometric functions
    printf("asin(%.1f) returns %lf\n", value1, asin(value1*(M_PI/180)));
    printf("acos(%.1f) returns %lf\n", value1, acos(value1*(M_PI/180)));
    printf("atan(%.1f) returns %lf\n", value1, atan(value1*(M_PI/180)));

    //Hyperbolic trigonometric functions
    printf("sinh(%.1f) returns %lf\n", value1, sinh(value1*(M_PI/180)));
    printf("cosh(%.1f) returns %lf\n", value1, cosh(value1*(M_PI/180)));
    printf("tanh(%.1f) returns %lf\n", value1, tanh(value1*(M_PI/180)));

    //Logarithms
    printf("log(%.1f) returns %lf\n", value1, log(value1));
    printf("log10(%.1f) returns %lf\n", value1, log10(value1));

    //Absolute value
    printf("fabs(%d) returns %f\n", value3, fabs(value3));

    //exp(x) = e^(x)
    printf("exp(%.1f) returns %f\n", value1, exp(value1));

    //Square root
    printf("sqrt(%.1f) returns %f\n", value1, sqrt(value1));
}


int main()
{   //a while cycle to explain the chapters (repeats until user exits) and a switch to get the input and call them
    short unsigned int chapter=5;
    while(chapter!=0)
    {   printf("Which chapter do you want to see? Type:\n");
        printf("1 for ARITHMETICAL operators\n");
        printf("2 for RELATIONAL operators, LOGICAL operators and BITWISE operators\n");
        printf("3 for SIDE EFFECTS, OVERFLOW and CASTING\n");
        printf("4 for IMPLICIT CONVERSIONS and examples of math.h\n");
        printf("0 to Exit\n");
        scanf("%i",&chapter);
        fflush(stdin);
        switch(chapter){
            case 1:
                c1();
                break;
            case 2:
                c2();
                break;
            case 3:
                c3();
                break;
            case 4:
                c4();
                break;
            case 0:     //will exit
                break;
            default:    //else ask again
                printf("\nInvalid choice, you can type only \'1\' to \'5\'\nIt's not that difficult, you can make it! Try again\n\n");
                chapter=5;
                break;
            }
            printf("\n\n");
        }
}
