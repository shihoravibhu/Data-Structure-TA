// Extra 2 : Level Of Node in Binary Tree
// set and find level of node in binary tree

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    int level;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertNode()
{
    int data;

    printf("Enter Data (-1 for no node) : ");
    scanf("%d", &data);

    if(data == -1)
    {
        return NULL;
    }

    struct TreeNode *newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->data = data;
    newNode->level = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("Enter Left of %d\n", data);
    newNode->left = insertNode();

    printf("Enter Right of %d\n", data);
    newNode->right = insertNode();

    return newNode;
}

void setLevel(struct TreeNode *root, int count)
{
    if(root == NULL)
    {
        return;
    }

    root->level = count;

    setLevel(root->left, count + 1);
    setLevel(root->right, count + 1);
}

int getLevel(struct TreeNode *root, int data)
{
    if(root == NULL)
    {
        return -1;
    }

    if(root->data == data)
    {
        return root->level;
    }

    int left = getLevel(root->left, data);

    if(left != -1)
    {
        return left;
    }

    int right = getLevel(root->right, data);

    if(right != -1)
    {
        return right;
    }

    return -1;
}

void inOrderTraversal(struct TreeNode* root){

    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);        
    
}

void main()
{
    struct TreeNode *root;

    root = insertNode();

    setLevel(root, 0);

    printf("\nNode Levels:\n");
    inOrderTraversal(root);

    int data;
    printf("Enter Node To Find Level : ");
    scanf("%d", &data);

    int ans = getLevel(root, data);

    if(ans == -1)
    {
        printf("Node Not Found\n");
    }
    else
    {
        printf("Level = %d\n", ans);
    }

}