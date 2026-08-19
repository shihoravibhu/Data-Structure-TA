// Extra 3 : Find Level of Node in BST

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    int level;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data, int level)
{
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->data = data;
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* insertNode(struct TreeNode *root, int data)
{
    if(root == NULL)
    {
        return createNode(data, 0);
    }

    if(data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
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

    if(data < root->data)
    {
        return getLevel(root->left, data);
    }
    else
    {
        return getLevel(root->right, data);
    }
}

void main()
{
    struct TreeNode *root = NULL;
    int n, data;

    printf("Enter Number Of Nodes : ");
    scanf("%d", &n);

    printf("Enter Values : ");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    setLevel(root, 0);

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