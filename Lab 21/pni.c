#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value) {
    
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

// Global index lidhi k je starting from the last element thase
int postIndex;

struct Node* constructTree(int postorder[], int inorder[], int start, int end) {
    
    if (start > end) {
        return NULL;
    }

    // Pick current node from postorder traversal using postIndex etle postorder ma last element root thase
    int rootData = postorder[postIndex--];
    struct Node* root = createNode(rootData);

    // Root Ne Find Kariyo Inorder Ma
    int pos = search(inorder, start, end, rootData);

    // ahiya apde right no call pela kariyo karn k aa postorder ma right subtree ni value pela aave chhe
    root->right = constructTree(postorder, inorder, pos + 1, end);
    root->left  = constructTree(postorder, inorder, start, pos - 1);

    return root;
}

void main() {

    int postorderArray[] = {4, 5, 2, 6, 7, 3, 1};
    int inorderArray[] = {4, 2, 5, 1, 6, 3, 7};
    int n = sizeof(postorderArray) / sizeof(postorderArray[0]);

    // Initialize kari postIndex ne with the last index of postorder array
    postIndex = n - 1;

    struct Node* root = constructTree(postorderArray, inorderArray, 0, n - 1);

    printf("Inorder: ");
    inorder(root);
    printf("\n");
}