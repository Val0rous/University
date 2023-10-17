#include <stdio.h>
#include <stdlib.h>

int main(){
	int array2x4x3[2][4][3] = { {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},  {{13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}}};
	int array1x4x3[4][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}, {100, 110, 120}};
	int x, y, z;

    printf("\n\n VISUALIZZA CONTENUTO array2x4x3 (accesso diretto):\n\n");
    for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", array2x4x3[z][x][y]);
            }
            printf(" | \n");
        }
        printf("\n\n");
    }

    printf("\n\n VISUALIZZA CONTENUTO array2x4x3 (accesso indiretto):\n\n");
    for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", *(*(*(array2x4x3+z)+x)+y));
            }
            printf(" | \n");
        }
        printf("\n\n");
    }

    printf("\n\n VISUALIZZA POSIZIONE array2x4x3 (accesso diretto):\n\n");
    for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", &array2x4x3[z][x][y]);
            }
            printf(" | \n");
        }
        printf("\n\n");
    }

    printf("\n\n VISUALIZZA POSIZIONE array2x4x3 (accesso indiretto):\n\n");
    for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", (*(*(array2x4x3+z)+x)+y));
            }
            printf(" | \n");
        }
        printf("\n\n");
    }

    printf("\n\n VISUALIZZA CONTENUTO array1x4x3 (accesso diretto):\n\n");
    //for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", array1x4x3[x][y]);
            }
            printf(" | \n");
        }
        printf("\n\n");
    //}

    printf("\n\n VISUALIZZA CONTENUTO array1x4x3 (accesso indiretto):\n\n");
    //for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", *(*(array1x4x3+x)+y));
            }
            printf(" | \n");
        }
        printf("\n\n");
    //}

    printf("\n\n VISUALIZZA POSIZIONE array1x4x3 (accesso diretto):\n\n");
    //for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", &array1x4x3[x][y]);
            }
            printf(" | \n");
        }
        printf("\n\n");
    //}

    printf("\n\n VISUALIZZA POSIZIONE array1x4x3 (accesso indiretto):\n\n");
    //for (z=0; z<2; z++){
        for (x=0; x<4; x++){
            for (y=0; y<3; y++){
                printf("\t | %3d", (*(array1x4x3+x)+y));
            }
            printf(" | \n");
        }
        printf("\n\n");
    //}


    printf("\n\n");
	system("pause");
	return 0;
}

