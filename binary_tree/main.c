#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

void createNullNode(Node** no){
    (*no) = (Node*)malloc(sizeof(Node));
    (*no) = NULL;
}

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

void insert(Node* root, int n){
    Node *temp = root, *child, *parent;
    createNode(&child, n);
    createNullNode(&parent);
    while(temp != NULL){
        parent = temp;
        if(n < temp->data){
            temp = temp->left;
        } else{
            temp = temp->right;
        }
    }

    if(parent == NULL){
        createNode(&root, n);
    } else if(n < (parent->data)){
        parent->left = child;
    } else{
        parent->right = child;
    }
    
}

int main(){
    Node *root, *n1, *n2, *n3, *n4, *n5, *n6, *n7;

    createNode(&root, 61);
    insert(root, 51);
    insert(root, 63);
    insert(root, 11);
    insert(root, 55);
    insert(root, 70);
    insert(root, 65);
    /*
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
    n4->right = n6;*/

    show(root);

    int h = heightNode(root);
    printf("h: %d\n", h);

    return 0;
}