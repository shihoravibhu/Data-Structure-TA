#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// root Ne Find Kariyu in Inorder
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


struct Node* constructTree(int postorder[], int inorder[],
                           int start, int end,
                           int postStart, int postEnd)
{
    // base case means element pura 
    if(start > end)
    {
        return NULL;
    }

    // Last element of Postorder = Root
    int rootValue = postorder[postEnd];

    struct Node *root = createNode(rootValue);

    // root ni idx inorder ma find kari
    int position = findPosition(inorder, start, end, rootValue);

    // Number of elements in Left Subtree
    int leftSize = position - start;

    // Everything before root = Left Subtree
    root->left = constructTree(
        postorder,
        inorder,
        start,
        position - 1,
        postStart,
        postStart + leftSize - 1
    );

    // Everything after root = Right Subtree
    root->right = constructTree(
        postorder,
        inorder,
        position + 1,
        end,
        postStart + leftSize,
        postEnd - 1
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


void postorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}


void main()
{
    int postorderArray[] = {4, 5, 2, 6, 7, 3, 1};

    int inorderArray[] = {4, 2, 5, 1, 6, 3, 7};

    int n = 7;

    // Construct tree
    struct Node *root = constructTree(
        postorderArray,
        inorderArray,
        0,
        n - 1,
        0,
        n - 1
    );

    printf("Inorder  : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);


    // Constructed Tree:
    //
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
}