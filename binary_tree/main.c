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

    printf("%d ", no->data);

    if(no->right != NULL)
        show(no->right);
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
    if(no == NULL)
        return NULL;
    if(no->data == n)
        return no;
    if(n < no->data){
        return binarySearchTree(no->left, n);
    } else{
        return binarySearchTree(no->right, n);
    }
}

int main(){
    Node *root;
    int numbers[7] = {61, 51, 63, 11, 55, 70, 65};

    for(int i=0; i<7; i++){
        if(i!=0){
            insert(root, numbers[i]);
        } else{
            createNode(&root, numbers[i]);
        }
    }

    Node *res = binarySearchTree(root, 51);
    if(res == NULL){
        printf("Nao encontrado");
    } else{
        printf("Encontrado\n");
        show(res);
    } 
    printf("\n");

    return 0;
}