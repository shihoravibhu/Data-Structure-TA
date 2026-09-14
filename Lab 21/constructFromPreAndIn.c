#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int preIndex = 0;

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// Find root in Inorder aa idx apse
int findPosition(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
        {
            return i;
        }
    }

    return -1;
}


// Construct Binary Tree
struct Node* constructTree(int preorder[], int inorder[],
                           int start, int end)
{
    // element pura
    if(start > end){
        return NULL;
    }

    // pelo element of Preorder = Root
    int rootValue = preorder[preIndex++];

    struct Node *root = createNode(rootValue);

    // Root Ne Find Kariyo Inorder Ma
    int position = findPosition(inorder, start, end, rootValue);

    // Everything before root ee Left Subtree ma
    root->left = constructTree(
        preorder,
        inorder,
        start,
        position - 1
    );

    // Everything after root ee Right Subtree ma
    root->right = constructTree(
        preorder,
        inorder,
        position + 1,
        end
    );

    return root;
}

void inorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

void preorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);
}


void main()
{
    int preorderArray[] = {1, 2, 4, 5, 3, 6, 7};

    int inorderArray[] = {4, 2, 5, 1, 6, 3, 7};

    int n = 7;

    struct Node *root = constructTree(
        preorderArray,
        inorderArray,
        0,
        n - 1
    );

    printf("Inorder  : ");
    inorder(root);

    printf("\nPreorder : ");
    preorder(root);
    
        //      1
        //    /   \
        //   2     3
        //  / \   / \
        // 4   5 6   7
}