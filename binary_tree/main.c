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
    Node *temp = root, *child, *parent; // init nodes
    createNode(&child, n);
    createNullNode(&parent);
    while(temp != NULL){
        parent = temp;
        if(n < temp->data){ // run in left if n < temp
            temp = temp->left;
        } else{ // else, run in right
            temp = temp->right;
        }
    }

    if(parent == NULL){
        createNode(&root, n);
    } else if(n < (parent->data)){
        parent->left = child; // if n < parent, parent has child in left
    } else{
        parent->right = child; // else, has child in right
    }
    
}

Node* binarySearchTree(Node* no, int n){
    if(no == NULL || no->data == n){
        return no;
    }
    if(n < no->data){
        return binarySearchTree(no->left, n);
    } else{
        return binarySearchTree(no->right, n);
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

    Node *res = binarySearchTree(root, 51);
    show(res);

    return 0;
}