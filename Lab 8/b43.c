// 43. WAP to check whether 2 singly linked lists are same or not. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST1 = NULL;
struct Node *FIRST2 = NULL;

void insertAtFirst1(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST1;

    FIRST1 = newNode;
}

void insertAtFirst2(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST2;

    FIRST2 = newNode;
}

void display(struct Node *first)
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

void compare()
{
    struct Node *save1 = FIRST1;
    struct Node *save2 = FIRST2;

    int issame = 0;

    while (save1 != NULL && save2 != NULL)
    {
        if (save1->info != save2->info)
        {
            issame = 1;
            break;
        }

        save1 = save1->link;
        save2 = save2->link;
    }

    if (save1 == NULL && save2 == NULL && issame == 0)
        printf("Linked List Is Same\n");
    else
        printf("Linked List Is Not Same\n");
}

void main()
{
    insertAtFirst1(9);
    insertAtFirst1(8);
    insertAtFirst1(7);
    insertAtFirst1(6);

    insertAtFirst2(9);
    insertAtFirst2(8);
    insertAtFirst2(7);
    insertAtFirst2(6);

    display(FIRST1);
    display(FIRST2);

    compare();

    
}