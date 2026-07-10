// 46. Write a program to reverse a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

void insertAtFirst(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST;

    FIRST = newNode;
}

void insertAtLast(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST = newNode;
        return;
    }

    struct Node *save = FIRST;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

void display()
{
    struct Node *save = FIRST;

    if (save == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL\n");
}

void reverse()
{
    if (FIRST == NULL)
    {
        return;
    }

    struct Node *prev = NULL;
    struct Node *save = FIRST;
    struct Node *next = NULL;

    while (save != NULL)
    {
        next = save->link;
        save->link = prev;

        prev = save;
        save = next;
    }

    FIRST = prev;
}

void main()
{
    insertAtFirst(9);
    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);

    display();

    reverse();

    display();

    
}