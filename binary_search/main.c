#include <stdio.h>

// Binary Search

int binSearch(int *list, int left, int right, int value){

    if(left <= right){ 
        int i = (left+right)/2;
        if(list[i] == value) return i; // if find the element, return his index;
        
        if(list[i] < value){ // search in sublist [i+1:right]
            binSearch(list, i+1, right, value);
        } else{ // search in sublist [left:i+1]
            binSearch(list, left, i-1, value);
        }
    } else{
        return -1;
    }
}

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

void printResult(int v, int r){
    if(v == -1){
        printf("Searching %d in list... Value not found in list!\n", v);
    } else{
        printf("Searching %d in list... Value found in list[%d]!\n", v, r);
    }
}

int main(){
    int myList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printList(myList, 10);

    int value = 2;
    int result = binSearch(myList, 0, 9, value);
    printResult(value, result);

    return 0;
}