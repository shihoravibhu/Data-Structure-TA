// 52. WAP to split a circular linked list into two halves.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;
struct Node *LAST = NULL;

void insertAtFirst(int n)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = n;

    if (FIRST == NULL)
    {
        FIRST = LAST = newNode;
        LAST->link = FIRST;
    }

    else
    {
        newNode->link = FIRST;
        FIRST = newNode;
        LAST->link = FIRST;
    }
}

void insertAtLast(int n)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = n;

    if (FIRST == NULL)
    {
        FIRST = LAST = newNode;
        LAST->link = FIRST;
    }

    else
    {
        newNode->link = FIRST;
        LAST->link = newNode;
        LAST = newNode;
    }
}

void display()
{

    struct Node *curr = FIRST;

    if (curr == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    do
    {

        printf("%d -> ", curr->info);
        curr = curr->link;
    } while (curr != FIRST);

    printf("%d\n", FIRST->info);
}

struct Node* split() {

    if (FIRST == NULL || FIRST->link == FIRST) {
        printf("Not enough elements to split.\n");
        return NULL;
    }

    struct Node* slow = FIRST;
    struct Node* fast = FIRST;

    // Use slow-fast with CSLL condition
    while (fast->link != FIRST && fast->link->link != FIRST) {
        slow = slow->link;
        fast = fast->link->link;
    }

    struct Node* FIRST2 = slow->link; // start of second half

    // peli half circular
    slow->link = FIRST;

    LAST->link = FIRST2;

    return FIRST2; // return the FIRST of the second half

    // biji half circular
    // struct Node* curr = FIRST2;
    // while (curr->link != FIRST) {
    //     curr = curr->link;
    // }
}


void main()
{

    insertAtFirst(12);
    insertAtFirst(6);
    insertAtFirst(9);
    insertAtFirst(18);
    insertAtFirst(5);
    insertAtFirst(25);

    display();

    display();
}