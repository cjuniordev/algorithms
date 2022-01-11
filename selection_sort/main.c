#include <stdio.h>

// Selection Sort

int printList(int *list, int n){
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        if(i == (n-1)){
            printf("%d ]\n", list[i]);
        } else{
            printf("%d, ", list[i]);
        }  
    }
}

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int selectionSort(int *list, int len){
    for(int i=0; i<len; i++){
        int smaller = list[i];
        for(int j=i+1; j<len; j++){
            if(list[j] < smaller){
                smaller = list[j];
                swap(&list[i], &list[j]);
                printList(list, len);
            }
        }
    }
}

int main(){
    int myList[10] = {4, 1, 15, 8, 3, 2, 5, 8, 11, 10};

    printList(myList, 10);
    selectionSort(myList, 10);
    printList(myList, 10);
    
    return 0;
}