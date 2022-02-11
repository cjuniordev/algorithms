#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **M, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<=n; j++){
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

void alocateMatrix(int **A, int m, int n){
    for(int i=0; i<m; i++){
        A[i] = malloc(n * sizeof(int));
    }
}

void freeMatrix(int **A, int m){
    for(int i=0; i<m; i++) free(A[i]);
    free(A);
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

void swapLines(int *first, int *second){
  int temp = *first;
  *first = *second;
  *second = temp;
}

void gauss(int **Ab, int m, int n){
    int m_pivot, n_pivot, pivot;
    float k;

    for(int i=0; i<m; i++){
        m_pivot = i, n_pivot = i;
        pivot = Ab[m_pivot][n_pivot];
        
        if(pivot == 0){
            swapLines(Ab[m_pivot], Ab[m_pivot+1]);
            pivot = Ab[m_pivot][n_pivot];
        }

        if(pivot != 1){
            for(int j=0; j<=n; j++) Ab[m_pivot][j] = Ab[m_pivot][j] / pivot; // pivot == 1
            pivot = Ab[m_pivot][n_pivot];
        }

        for(int l=m_pivot+1; l<m; l++){ // get lines under pivot
            if(Ab[l][n_pivot] != 0){
                k = Ab[l][n_pivot] / pivot;
                for(int j=0; j<=n; j++){
                    Ab[l][j] = Ab[l][j] - (k * Ab[m_pivot][j]);
                }
            }
        }
    }
}

int main(){
    int row = 3, col = 3;
    int **A = (int **)malloc(row * sizeof(int*)), 
         *b = (int *)malloc(row * sizeof(int)),
        **augment = (int **)malloc(row * sizeof(int*));

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

    augmentMatrix(A, b, row, col, augment);

    printf("before:\n");
    printMatrix(augment, row, col);

    gauss(augment, row, col+1);

    printf("\nlater:\n");
    printMatrix(augment, row, col);

    printf("\n--------------------------------\n");

    row = 4, col = 4;
    A = (int **)realloc(A, row * sizeof(int*)), 
    b = (int *)realloc(b, row * sizeof(int)),
    augment = (int **)realloc(augment, row * sizeof(int*));

    alocateMatrix(A, row, col);

    // row 1
    A[0][0] = 0;
    A[0][1] = 2;
    A[0][2] = 6;
    A[0][3] = 6;
    // row 2
    A[1][0] = 1;
    A[1][1] = 6;
    A[1][2] = 7;
    A[1][3] = 3;
    // row 3 
    A[2][0] = 3;
    A[2][1] = 11;
    A[2][2] = 2;
    A[2][3] = -18;
    // row 3 
    A[3][0] = 2;
    A[3][1] = 9;
    A[3][2] = 2;
    A[3][3] = 8;
    // b
    b[0] = 34;
    b[1] = 62;
    b[2] = 93;
    b[3] = 30;

    augmentMatrix(A, b, row, col, augment);

    printf("\nbefore:\n");
    printMatrix(augment, row, col);

    gauss(augment, row, col+1);

    printf("\nlater:\n");
    printMatrix(augment, row, col);

    freeMatrix(A, row);
    freeMatrix(augment, row);
    free(b);

    return 0;
}