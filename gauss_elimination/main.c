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
    int k, m_pivot, n_pivot, pivot;

    // for(int i=0; i<m; i++){
        m_pivot = 0, n_pivot = 0;
        pivot = Ab[m_pivot][n_pivot];
        
        
        if(pivot != 0){
            for(int l=1; l<m; l++){
                k = Ab[m_pivot+l][n_pivot] / pivot;
                for(int j=0; j<n; j++){
                    Ab[m_pivot+l][j] = Ab[m_pivot+l][j] - (k * Ab[m_pivot][j]);
                }
            }
        }
    //}
    
}

int main(){
    int row = 3, col = 3;
    int **A = (int **)malloc(row * sizeof(int*)), 
         *b = (int *)malloc(row * sizeof(int));    

    alocateMatrix(A, row, col);

    // row 1
    A[0][0] = 1;
    A[0][1] = 3;
    A[0][2] = 1;
    // row 2
    A[1][0] = 4;
    A[1][1] = 4;
    A[1][2] = 4;
    // row 3 
    A[2][0] = 3;
    A[2][1] = 2;
    A[2][2] = 6;
    // b
    b[0] = 37;
    b[1] = 68;
    b[2] = 47;

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