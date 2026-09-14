// 83. Write a program to implement phone book dictionary using Binary Search Tree 
// which provides following operations: 
// • Add new entry in phone book,  
// • Remove entry from phone book,  
// • Search phone number  
// • List all entries in ascending order of name and 
// • List all entries in descending order of name

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    char name[100];
    char phone[20];
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char NAME[], char PHONE[]){

    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    strcpy(newNode->name,NAME);
    strcpy(newNode->phone,PHONE);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

struct TreeNode* insertNode(struct TreeNode* root, char NAME[], char PHONE[]){

    if(root == NULL){                
        return createNode(NAME,PHONE);
    }

    if(strcmp(NAME,root->name) < 0){
        root->left = insertNode(root->left,NAME,PHONE);
    }
    else{
        root->right = insertNode(root->right,NAME,PHONE);
    }

    return root;
}

struct TreeNode* getInOrderSuccessor(struct TreeNode* root){        // leftMost Node (Smallest In RightSubtree)

    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;

}

struct TreeNode* DelNode(struct TreeNode* root,char NAME[]){

    if(root == NULL){
        return root;
    }

    if(strcmp(NAME,root->name) < 0){
        root->left = DelNode(root->left,NAME);
    }
    else if(strcmp(NAME,root->name) > 0){
        root->right = DelNode(root->right,NAME);
    }
    else{   // Node to be deleted found

        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // Case 2: One child
        if(root->left == NULL){
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct TreeNode* temp = getInOrderSuccessor(root->right);
        strcpy(root->name,temp->name);
        strcpy(root->phone,temp->phone);
        root->right = DelNode(root->right,temp->name);
    }

    return root;

}

struct TreeNode* Search(struct TreeNode* root,char NAME[]){

    if(root == NULL){
        return NULL; // Not found
    }

    if(strcmp(NAME,root->name) == 0){
        return root; // Found
    }
    else if(strcmp(NAME,root->name) < 0){
        return Search(root->left,NAME);
    }
    else{
        return Search(root->right,NAME);
    }

}

void inOrderTraversal(struct TreeNode* root){

    if(root != NULL){
        inOrderTraversal(root->left);
        printf("NAME: %s, PHONE: %s\n",root->name,root->phone);
        inOrderTraversal(root->right);        
    }

}

void reverseInOrderTraversal(struct TreeNode* root){

    if(root != NULL){
        reverseInOrderTraversal(root->right);
        printf("NAME: %s, PHONE: %s\n",root->name,root->phone);
        reverseInOrderTraversal(root->left);        
    }

}

void main(){

    struct TreeNode* root = NULL;

    root = insertNode(root,"Alice","1234567890");
    root = insertNode(root,"Bob","2345678901");
    root = insertNode(root,"Charlie","3456789012");
    root = insertNode(root,"David","4567890123");
    root = insertNode(root,"Eve","5678901234");

    printf("PHONE Book Entries in Ascending Order:\n");
    inOrderTraversal(root);

    printf("\nPHONE Book Entries in Descending Order:\n");
    reverseInOrderTraversal(root);

    char searchNAME[100];
    printf("\nEnter name to search: ");
    scanf("%s", searchNAME);
    
    struct TreeNode* found = Search(root, searchNAME);
    if(found){
        printf("Entry found - NAME: %s, PHONE: %s\n", found->name, found->phone);
    }
    else{
        printf("Entry not found for name: %s\n", searchNAME);
    }

    char deleteNAME[100];
    printf("\nEnter name to delete: ");
    scanf("%s", deleteNAME);
    
    root = DelNode(root, deleteNAME);
    
    printf("\nPHONE Book Entries after deletion:\n");
    inOrderTraversal(root);

    
}