/*
preso in ingresso una lettera il programma indica se si tratta di una vocale o consonante
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char lettera;

    printf("Inserire una lettera e premere INVIO: ");
    scanf("%c", &lettera);
    fflush(stdin);
    switch(lettera) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("hai inserito una vocale");
            break;
        case 'q':
        case 'w':
        case 'r':
        case 't':
        case 'y':
        case 'p':
        case 's':
        case 'd':
        case 'f':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'z':
        case 'x':
        case 'c':
        case 'v':
        case 'b':
        case 'n':
        case 'm':
        case 'Q':
        case 'W':
        case 'R':
        case 'T':
        case 'Y':
        case 'P':
        case 'S':
        case 'D':
        case 'F':
        case 'G':
        case 'H':
        case 'J':
        case 'K':
        case 'L':
        case 'Z':
        case 'X':
        case 'C':
        case 'V':
        case 'B':
        case 'N':
        case 'M':
            printf("hai inserito una consonante");
            break;
        default:
            printf("non hai inserito una lettera dell'alfabeto");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
