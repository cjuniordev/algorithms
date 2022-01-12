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

int main(){
    Node *root;
    Node *n1;
    Node *n2;
    Node *n3;
    Node *n4;
    Node *n5;
    Node *n6;
    Node *n7;

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
    printf("\n");

    return 0;
}