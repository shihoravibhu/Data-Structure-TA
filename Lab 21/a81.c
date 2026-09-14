// 81. Write a program to construct a binary tree from given Postorder and Preorder traversal sequence. 

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode =
        (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int findIndex(int postOrder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (postOrder[i] == val)
        {
            return i;
        }
    }

    return -1;
}

struct TreeNode *buildTree(
    int preOrder[],
    int postOrder[],
    int preStart,
    int preEnd,
    int postStart,
    int postEnd)
{
    // No node
    if (preStart > preEnd)
    {
        return NULL;
    }

    // First element of preorder is root
    struct TreeNode *root = createNode(preOrder[preStart]);

    // Only one node
    if (preStart == preEnd){
        return root;
    }

    // Next preorder element is left subtree root
    int leftRoot = preOrder[preStart + 1];

    // Find left subtree root in postorder
    int index = findIndex(
        postOrder,
        postStart,
        postEnd,
        leftRoot
    );

    // Number of nodes in left subtree
    int leftSize = index - postStart + 1;

    // Build left subtree
    root->left = buildTree(
        preOrder,
        postOrder,
        preStart + 1,
        preStart + leftSize,
        postStart,
        index
    );

    // Build right subtree
    root->right = buildTree(
        preOrder,
        postOrder,
        preStart + leftSize + 1,
        preEnd,
        index + 1,
        postEnd - 1
    );

    return root;
}

int preIndex = 0;

struct TreeNode *buildTree2(int preOrder[],int postOrder[],int postStart,int postEnd){

    // No node
    if (postStart > postEnd){
        return NULL;
    }
    // First element of preorder ee root
    struct TreeNode *root = createNode(preOrder[preIndex]);
    preIndex++;

    // Only one node hoi tyare
    if (postStart == postEnd){
        return root;
    }

    int leftRoot = preOrder[preIndex];
    int index = findIndex(postOrder,postStart,postEnd,leftRoot);

    // Build left subtree
    root->left = buildTree2(preOrder, postOrder, postStart, index);
    // Build right subtree
    root->right = buildTree2(preOrder, postOrder, index + 1, postEnd - 1);

    return root;
}

void inOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);

    printf("%d ", root->data);

    inOrder(root->right);
}

void main()
{
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};

    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};

    int n = sizeof(preOrder) / sizeof(preOrder[0]);

    
    struct TreeNode *root = buildTree2(preOrder, postOrder, 0, n-1);
    
    // struct TreeNode *root = buildTree(
    //     preOrder,
    //     postOrder,
    //     0,
    //     n-1,
    //     0,
    //     n-1
    // );

    printf("Inorder Traversal : ");

    inOrder(root);

    printf("\n");

}

// Preorder:   1 | 2 4 5 | 3 6 7
                   
//            Root  Left   Right


// Postorder:  4 5 2 | 6 7 3 | 1
            
//             Left    Right   Root


// preIndex = 0

// TreeNode* construct (postStart, postEnd)
// if postStart > postEnd
// return NULL

// node = new TreeNode value preorder[preIndex]
// ++preIndex
// if postStart == postEnd
// return node
// postIndex = Search index of preorder[preIndex]
// in postorder traversal
// node->left = construct(postStart, postIndex)
// node->right = construct(postIndex+1, postEnd-1)
// return node