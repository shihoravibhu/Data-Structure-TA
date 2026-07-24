// 58. Write a program to implement stack using singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

// Push Etle K InsertAtFirst
void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = val;
    newNode->link = FIRST;

    FIRST = newNode;
}

// Pop Etle K DeleteAtFirst
int pop()
{
    if (FIRST == NULL)
    {
        printf("Stack Is Empty\n");
        return -1;
    }

    struct Node *temp = FIRST;
    int x = FIRST->info;

    FIRST = FIRST->link;

    free(temp);

    return x;
}

int peek()
{
    if (FIRST == NULL)
    {
        printf("Stack Is Empty\n");
        return -1;
    }

    return FIRST->info;
}

void display()
{
    if (FIRST == NULL)
    {
        printf("Stack Is Empty\n");
        return;
    }

    struct Node *save = FIRST;

    printf("TOP -> ");

    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL\n");
}

void main()
{
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped Element = %d\n", pop());
    display();

    printf("Top Element = %d\n", peek());

    push(40);
    display();

    printf("Popped Element = %d\n", pop());
    display();

}