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
            printf("%d ]", list[i]);
        } else{
            printf("%d, ", list[i]);
        }  
    }
}

void printResult(int *list, int v, int r){
    if(v == -1){
        printf("Searching %d in ", v);
        printList(list, 10);
        printf("... Value not found in list!\n");
    } else{
        printf("Searching %d in ", v);
        printList(list, 10);
        printf("... Value found in list[%d]!\n", r);
    }
}

int main(){
    int myList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int single[1] = {7};
    int pair[2] = {3, 7};
    int odd[11] = {1, 2, 3, 5, 7, 8, 9, 13, 27, 31, 43};
    int even[12] = {1, 2, 3, 5, 7, 8, 9, 13, 27, 31, 43, 70};
    int repeated[12] = {1, 2, 2, 5, 5, 5, 9, 13, 21, 21, 21, 21};
    
    int value = 2;
    int result = binSearch(myList, 0, 9, value);
    printResult(myList, value, result);

    value = 7;
    result = binSearch(single, 0, 1-1, value);
    printResult(single, value, result);

    value = 7;
    result = binSearch(pair, 0, 2-1, value);
    printResult(pair, value, result);

    value = 8;
    result = binSearch(odd, 0, 11-1, value);
    printResult(odd, value, result);

    value = 31;
    result = binSearch(even, 0, 12-1, value);
    printResult(even, value, result);

    value = 21;
    result = binSearch(repeated, 0, 12-1, value);
    printResult(repeated, value, result);

    return 0;
}