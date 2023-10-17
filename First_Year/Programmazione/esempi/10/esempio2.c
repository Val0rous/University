#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrice[2][3] = { {10,20,30}, {40,50,60} };
    int transpose[3][2];

    int i, j;

//    // Storing elements of the matrix
//    printf("\nEnter elements of matrix:\n");
//    for(i=0; i<2; i++)
//    {
//        for(j=0; j<3; ++j)
//        {
//            printf("Enter int element a%d%d: ",i+1, j+1);
//            scanf("%d", &matrice[i][j]);
//        }
//    }

    // Displaying the matrix a[][] */
    printf("\nEntered Matrix: \n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d  ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // Finding the transpose of matrix a
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            transpose[j][i] = matrice[i][j];
        }
    }


    // Displaying the transpose of matrix a
    printf("\nTranspose of Matrix: \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d  ",transpose[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
