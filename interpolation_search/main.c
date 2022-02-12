#include <stdio.h>
#include <stdlib.h>

void printList(int *v, int n){ 
    for(int i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

float interpolation(int *v, int left, int right, int x){ // x is a wanted search 
    float pos;

    float division = (float)(x - v[left]) / (float)(v[right] - v[left]);
    pos = left - ((left - right) * division); // interpolation

    return pos;
}

int main(){
    int n = 10;
    int *list = (int *)malloc(10 * sizeof(int)), *list2 = (int *)malloc(10 * sizeof(int));

    for(int i=0; i<n; i++){
        list[i] = 2*i;
    }

    list2[0] = 1;
    list2[1] = 3;
    list2[2] = 5;
    list2[3] = 7;
    list2[4] = 8;
    list2[5] = 9;
    list2[6] = 13;
    list2[7] = 27;
    list2[8] = 31;
    list2[9] = 43;

    printList(list2, n);

    int r = (int)interpolation(list2, 0, n-1, 27);
    printf("v[%d]: %d\n", r, list2[r]);

    free(list);
    free(list2);

    return 0;
}