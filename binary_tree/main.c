#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

void createNode(Node** no, int n){
    (*no) = (Node*)malloc(sizeof(Node));
    (*no)->data = n;
    (*no)->left = NULL;
    (*no)->right = NULL;
}

void show(Node* no){ // show in pos-order
    if(no->left != NULL)
        show(no->left);

    if(no->right != NULL)
        show(no->right);

    printf("%d\n", no->data);
}

int heightNode(Node* no){
    int hr=0, hl=0; // height left and right = 0
    if(no->left != NULL)
        hl = heightNode(no->left) ; // getting heigth of left node
    if(no->right != NULL)
        hr = heightNode(no->right); // getting heigth of right node

    if(hr > hl)
        return hr+1;

    return hl+1;
}

int main(){
    Node *root, *n1, *n2, *n3, *n4, *n5, *n6, *n7;

    createNode(&root, 0);
    createNode(&n1, 1);
    createNode(&n2, 2);
    createNode(&n3, 3);
    createNode(&n4, 4);
    createNode(&n5, 5);
    createNode(&n6, 6);
    createNode(&n7, 7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n7;
    n4->left = n5;
    n4->right = n6;

    show(root);

    int h = heightNode(root);
    printf("h: %d\n", h);

    return 0;
}