// 75. Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node 
// • Delete a node 
// • Search a node 
// • Preorder Traversal 
// • Postorder Traversal 
// • Inorder Traversal 

#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val){

    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

struct TreeNode* insertNode(struct TreeNode* root,int val){

    if(root == NULL){                

        return createNode(val);
    }

    if(val < root->data){
        root->left = insertNode(root->left,val);
    }
    else{
        root->right = insertNode(root->right,val);
    }

    return root;

}

struct TreeNode* getInOrderSuccessor(struct TreeNode* root){        // leftMost Node (Smallest In RightSubtree)

    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;

}

struct TreeNode* DelNode(struct TreeNode* root,int val){

    // Base Case
    if(root == NULL){
        printf("Empty.");
        return NULL;
    }

    // Find Karva Pela
    if(val < root->data){
        root->left = DelNode(root->left,val);
    }
    else if(val > root->data){  // val right side
        root->right = DelNode(root->right,val);
    }
    else{       // if val == root->data matched

        if(root->left == NULL && root->right == NULL){      // case 1 (Node With zero child)
           
            free(root);   
            return NULL;         
        }
        else if(root->left == NULL){                        // case 2 (only right child)
            struct TreeNode* temp = root->right;
            free(root); 
            return temp;
        }      
        else if(root->right == NULL){                        // case 3 (only left child)
            struct TreeNode* temp = root->left;
            free(root); 
            return temp;
        }
        else{                               // case 4 Node with two child (Both Right And Left Exists)  
            
            // struct TreeNode* in = getInOrderSuccessor(root->right);
            // root->data = in->data;
            // root->right = DelNode(root->right,in->data);

            // or

            struct TreeNode *in = getInOrderSuccessor(root->right);

            in->left = root->left;

            struct TreeNode *temp = root->right;

            free(root);

            return temp;
        }
        
        return root;

    }
}

int Search(struct TreeNode* root,int val){

    if(root == NULL){
        return 0; // means val not found basically false 
    }

    if(root->data == val){
        return 1; // Val Found
    }
    else if(val < root->data){   // Val Left Side Chhe
        return Search(root->left,val);
    }
    else{       // Val Right Side Chhe
        return Search(root->right,val);
    }

}

void inOrderTraversal(struct TreeNode* root){

    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);        
    

}
void preOrderTraversal(struct TreeNode* root){

    if(root == NULL){
        return;
    }
    
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);      

}

void postOrderTraversal(struct TreeNode* root){

    if(root == NULL){
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);      
    printf("%d ",root->data);

}



void main(){

    struct TreeNode* root = NULL;

    root = insertNode(root,40);
    insertNode(root,20);
    insertNode(root,60);
    insertNode(root,70);
    insertNode(root,35);
    insertNode(root,18);

    inOrderTraversal(root);

    printf("\n");

    // root = DelNode(root,20);
    // inOrderTraversal(root);

    //  struct TreeNode* root = NULL;
    // int choice, val;

    // while(1){
    //     printf("\n--- Binary Search Tree Menu ---\n");
    //     printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d",&choice);

    //     switch(choice){
    //         case 1:
    //             printf("Enter value to insert: ");
    //             scanf("%d",&val);
    //             root = insertNode(root,val);
    //             break;
    //         case 2:
    //             printf("Enter value to delete: ");
    //             scanf("%d",&val);
    //             root = DelNode(root,val);
    //             break;
    //         case 3:
    //             printf("Enter value to search: ");
    //             scanf("%d",&val);
    //             if(Search(root,val))
    //                 printf("%d found in BST\n",val);
    //             else
    //                 printf("%d not found in BST\n",val);
    //             break;
    //         case 4:
    //             printf("Inorder: ");
    //             inOrderTraversal(root);
    //             printf("\n");
    //             break;
    //         case 5:
    //             printf("Preorder: ");
    //             preOrderTraversal(root);
    //             printf("\n");
    //             break;
    //         case 6:
    //             printf("Postorder: ");
    //             postOrderTraversal(root);
    //             printf("\n");
    //             break;
    //         case 7:
    //             exit(0);
    //         default:
    //             printf("Invalid choice!\n");
    //     }
    // }
    
}