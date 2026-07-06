#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

// Method 1 Using Global Variable

struct Node *first = NULL;

void insertAtFirst(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

// Method 2 Pass Head and Return Head

struct Node* insertAtFirst(struct Node *first, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = first;

    first = newNode;

    return first;
}


// Method 3 Pass Double Pointer (Without Returning)

void insertAtFirst(struct Node **first, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = *first;

    *first = newNode;
}

void main()
{

    // For Method 1

    insertAtFirst(10);
    insertAtFirst(20);



    // For Method 2

    // struct Node *first = NULL;

    // first = insertAtFirst(first, 10);
    // first = insertAtFirst(first, 20);


    // For Method 3

    // struct Node *first = NULL;

    // insertAtFirst(&first, 10);
    // insertAtFirst(&first, 20);




}