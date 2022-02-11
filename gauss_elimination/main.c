#include <stdio.h>
#include <stdlib.h>

void freeMatriz(int **M, int rows){
    for(int i=0; i<rows; i++) free(M[i]);
}

int main(){
    int col = 2;
    int row = 2;
    int **matriz = (int **)malloc(row * sizeof(int*));

    for(int i=0; i<row; i++){
        matriz[i] = malloc(col * sizeof(int));
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }


    freeMatriz(matriz, row);

    return 0;
}