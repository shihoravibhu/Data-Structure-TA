// 78. Given a binary tree, determine if it is height-balanced (A height-balanced binary 
// tree is a binary tree in which the depth of the two subtrees of every node never 
// differs by more than one). 

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
    
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    printf("Enter data for inserting in left of %d\n", data);
    newNode->left = insertNode();
    
    printf("Enter data for inserting in right of %d\n", data);
    newNode->right = insertNode();

    printf("\n");

    return newNode;
}

void inOrderTraversal(struct TreeNode* root){

    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);        
    
}

int max(int left, int right){

    if(left>right){
        return left;
    }
    else{
        return right;
    }
}

int findHeight(struct TreeNode* root){

    if(root == NULL){
        return 0;
    }

    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);

    return (max(lefth, righth)) + 1;
}

bool isHeightBalance(struct TreeNode* root){

    if(root == NULL){
        return true;
    }

    int h1 = findHeight(root->left);
    int h2 = findHeight(root->right);

    if(abs(h1-h2) > 1){
        return false;
    }

    bool isLeftBalanced = isHeightBalance(root->left);
    bool isRightBalanced = isHeightBalance(root->right);

    return isLeftBalanced && isRightBalanced;
}

void main(){

    struct TreeNode* root = NULL;
    
    printf("Enter root 1 : ");
    printf("\n");
    
    root = insertNode(root);         

    printf("root 1 : ");
    inOrderTraversal(root);
    printf("\n");        

    if(isHeightBalance(root)){
        printf("This Tree Is Balanced (TRUE)\n");
    }
    else{
        printf("This Tree Is Not Balanced (FALSE)\n");
    }
   

// 3 9 -1 -1 20 15 -1 -1 7 -1 -1 (Balanced)
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1 (Not Balanced)

//      1
//     / \
//    2   5
//   / \
//  3   4
    
}