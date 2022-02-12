#include <stdio.h>
#include <stdlib.h>

float interpolation(int *v, int n, int left, int right, int x){ // x is a wanted search 
    float pos;

    float division = (float)(x - v[left]) / (float)(v[right] - v[left]);
    pos = left - ((left - right) * division); // interpolation

    return pos;
}

int main(){
    int n = 10;
    int *list = (int *)malloc(10 * sizeof(int));

    for(int i=0; i<n; i++){
        list[i] = 2*i;
    }

    for(int i=0; i<n; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    int r = (int)interpolation(list, n, 0, n-1, 6);
    printf("v[%d]: %d\n", r, list[r]);

    return 0;
}