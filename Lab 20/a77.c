//  77. Write a program to check whether the given tree is symmetric or not. 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertNode() {
    
    int data;
    printf("Enter the data (-1 for no node): ");
    scanf("%d", &data);
    
    if (data == -1) {
        return NULL;
    }
    
    // create node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;    
    
    printf("Enter data for left child of %d: ", data);
    newNode->left = insertNode();
    
    printf("Enter data for right child of %d: ", data);
    newNode->right = insertNode();

    return newNode;
}


void inOrderTraversal(struct TreeNode* root){

    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);        
    }

}

bool isSymmentric(struct TreeNode* root1, struct TreeNode* root2) {

     if(root1 == NULL || root2 == NULL){
        // bey null
        if(root1 == NULL && root2 == NULL){
            return 1;
        }

        // anyone null
        else{
            return 0;
        }
    }

    return (root1->data == root2->data) && 
    isSymmentric(root1->left, root2->right) && 
    isSymmentric(root1->right, root2->left);
}

void main(){

    struct TreeNode* root = NULL;
    
    printf("Enter root 1 : ");
    printf("\n");
    
    root = insertNode(root);         

    printf("root 1 : ");
    inOrderTraversal(root);
    printf("\n");        

    if(root == NULL || isSymmentric(root->left,root->right)){

        printf("Tree Is Symmentric.");
    }
    else{
        
        printf("Tree Is Not Symmentric.");
    }

// 8 5 3 -1 -1 6 -1 -1 7 6 -1 -1 3 -1 -1 (Not Symmentric)

//       1
//     /  \
//    2    5
//   / \
//  3  4

    
}