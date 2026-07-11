// 49. WAP to perform given operation in the linked list. There exist a Linked List. Add 
// a node that contains the GCD of those two nodes between every pair adjacent 
// node of Linked List. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertAtFirst(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = first;

    first = newNode;
}

void insertAtLast(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
        return;
    }

    struct Node *save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

void display()
{
    struct Node *save = first;

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

int min(int a, int b)
{
    if (a < b)
        return a;

    return b;
}

int find_gcd(int a, int b)
{
    for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }

    return 1;
}

void gcd()
{
    if (first == NULL || first->link == NULL)
    {
        return;
    }

    struct Node *save = first;

    while (save->link != NULL)
    {
        int g = find_gcd(save->info, save->link->info);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->info = g;

        newNode->link = save->link;

        save->link = newNode;

        // Move to the next original node
        save = save->link->link;
    }
}

int main()
{
    insertAtFirst(12);
    insertAtFirst(6);
    insertAtFirst(9);
    insertAtFirst(18);
    insertAtFirst(5);
    insertAtFirst(25);

    display();

    gcd();

    display();

    return 0;
}