#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
/*
                        1    <-- root
                      /  \
                    2     3  
                  / 
                4
*/

node * createNewNode(int);
void inOrderTraversal(node *);
void preOrderTraversal(node *);
void postOrderTraversal(node *);
int countLeaves(node* root);

int main(){

    node *root=createNewNode(1);
    root->left=createNewNode(2);
    root->left->left=createNewNode(4);
    root->right=createNewNode(3);

    printf("Number of Leaf Nodes : %d ",countLeaves(root));

    printf("\ninOrderTraversal : ");
    inOrderTraversal(root);
    printf("\npreOrderTraversal : ");
    preOrderTraversal(root);
    printf("\npostOrderTraversal : ");
    postOrderTraversal(root);
    return 0;
}

node * createNewNode(int data){
    node *n1=(node *)malloc(sizeof(node));
    n1->data=data;
    n1->left=NULL;
    n1->right=NULL;
    return n1;
}

void inOrderTraversal(node * root){
    //First visit LEFT then ROOT and Finally RIGHT 
    if (root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(node * root){
    //First visit ROOT then LEFT and Finally RIGHT 
    if (root==NULL)
        return;
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node * root){
    //First visit LEFT then RIGHT and Finally ROOT 
    if (root==NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}

int countLeaves(node* root){
    if (root==NULL)
        return 0;
    if (root->left==NULL && root->right==NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}