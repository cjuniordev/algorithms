#include <stdio.h>
#include <stdlib.h>

void alocateMatrix(int **A, int m, int n){
    for(int i=0; i<m; i++){
        A[i] = malloc(n * sizeof(int));
    }
}

void freeMatrix(int **A, int m){
    for(int i=0; i<m; i++) free(A[i]);
}

void augmentMatrix(int **A, int *b, int m, int n, int **Ab){
    // A[m][n]
    alocateMatrix(Ab, m, (n+1));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            Ab[i][j] = A[i][j];
        }
        Ab[i][n] = b[i];
    }
}

void gauss(int **Ab, int m, int n){
    int k, m_pivot = 0, n_pivot = 0;
    int pivot = Ab[m_pivot][n_pivot];

    if(pivot != 0){
        k = Ab[m_pivot+1][n_pivot] / pivot;
        for(int i=0; i<n; i++){
            Ab[m_pivot+1][i] = Ab[m_pivot+1][i] - (k * Ab[m_pivot][i]);
        }
    }
}

int main(){
    int row = 2, col = 2;
    int **A = (int **)malloc(row * sizeof(int*)), 
         *b = (int *)malloc(row * sizeof(int));    

    alocateMatrix(A, row, col);

    A[0][0] = 1;
    A[0][1] = 3;
    A[1][0] = 4;
    A[1][1] = 4;
    b[0] = 35;
    b[1] = 60;

    int **augment = (int **)malloc(row * sizeof(int*));
    augmentMatrix(A, b, row, col, augment);

    gauss(augment, row, col+1);

    for(int i=0; i<row; i++){
        for(int j=0; j<=col; j++){
            printf("%d\t", augment[i][j]);
        }
        printf("\n");
    }

    freeMatrix(A, row);
    freeMatrix(augment, row);

    return 0;
}