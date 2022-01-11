#include <stdio.h>

// Selection Sort

int selectionSort(int *list, int len){
}

int printList(int *list, int n){
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        if(i == (n-1)){
            printf("%d ]", list[i]);
        } else{
            printf("%d, ", list[i]);
        }  
    }
}

int main(){
    int myList[10] = {4, 1, 15, 8, 3, 2, 5, 8, 11, 10};

    return 0;
}