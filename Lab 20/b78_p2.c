// 78. Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is a binary tree in which the
// depth of the two subtrees of every node never differs by more than one.

// Extra 1 : Left Heavy, Right Heavy, Balanced

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int data;
    char c;     // l = left heavy, r = right heavy, b = balanced
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertNode()
{
    int data;

    printf("Enter the data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    struct TreeNode *newNode =
        (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->data = data;
    newNode->c = 'b';
    newNode->left = NULL;
    newNode->right = NULL;

    printf("Enter data for inserting in left of %d\n", data);
    newNode->left = insertNode();

    printf("Enter data for inserting in right of %d\n", data);
    newNode->right = insertNode();

    return newNode;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

int findHeight(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);

    if (lefth > righth)
    {
        root->c = 'l';
    }
    else if (righth > lefth)
    {
        root->c = 'r';
    }
    else
    {
        root->c = 'b';
    }

    return max(lefth, righth) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);

    if (abs(lefth - righth) > 1)   // Means Not Balanced
    {
        return false;
    }

    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);

    return isLeftBalanced && isRightBalanced;
}

void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d(%c) ", root->data, root->c);

        inorder(root->right);
    }
}

void main()
{
    struct TreeNode *root = NULL;

    printf("Create Binary Tree\n\n");

    root = insertNode();

    findHeight(root);

    printf("\nInorder Traversal with Balance Status:\n");
    inorder(root);

    printf("\n\n");

    if (isBalanced(root))
    {
        printf("Tree Is Height Balanced\n");
    }
    else
    {
        printf("Tree Is Not Height Balanced\n");
    }

}