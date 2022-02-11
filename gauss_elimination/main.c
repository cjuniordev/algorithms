#include <stdio.h>
#include <stdlib.h>

void freeMatriz(int **A, int m){
    for(int i=0; i<m; i++) free(A[i]);
}

void augmentMatrix(int **A, int *b, int m, int n, int **Ab){
    // A[m][n]
    for(int i=0; i<m; i++){
        Ab[i] = malloc((n+1) * sizeof(int));
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            Ab[i][j] = A[i][j];
        }
        Ab[i][n] = b[i];
    }
}

int main(){
    int row = 2, col = 2;
    int **A = (int **)malloc(row * sizeof(int*)), 
         *b = (int *)malloc(row * sizeof(int));    

    for(int i=0; i<row; i++){
        A[i] = malloc(col * sizeof(int));
    }

    A[0][0] = 1;
    A[0][1] = 3;
    A[1][0] = 4;
    A[1][1] = 4;
    b[0] = 35;
    b[1] = 60;

    int **augment = (int **)malloc(row * sizeof(int*));

    augmentMatrix(A, b, row, col, augment);

    for(int i=0; i<row; i++){
        for(int j=0; j<=col; j++){
            printf("%d\t", augment[i][j]);
        }
        printf("\n");
    }

    freeMatriz(A, row);
    freeMatriz(augment, row);

    return 0;
}