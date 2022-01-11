#include <stdio.h>

// Binary Search

int binSearch(int list, int left, int right, int value){

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

int main(){
    int myList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printList(myList, 10);

    return 0;
}