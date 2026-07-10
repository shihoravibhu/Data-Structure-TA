// 45. Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST1 = NULL;
struct Node *FIRST2 = NULL;

void insertAtFirst(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST1;

    FIRST1 = newNode;
}

void insertAtLast(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = NULL;

    if (FIRST2 == NULL)
    {
        FIRST2 = newNode;
        return;
    }

    struct Node *save = FIRST2;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

void display(struct Node *FIRST)
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

// M-1

// void copy()
// {
//     if (FIRST1 == NULL)
//     {
//         FIRST2 = NULL;
//         return;
//     }

//     FIRST2 = (struct Node *)malloc(sizeof(struct Node));
//     FIRST2->info = FIRST1->info;
//     FIRST2->link = NULL;

//     struct Node *oldtemp = FIRST1->link;
//     struct Node *newtemp = FIRST2;

//     while (oldtemp != NULL)
//     {
//         struct Node *copytemp = (struct Node *)malloc(sizeof(struct Node));

//         copytemp->info = oldtemp->info;
//         copytemp->link = NULL;

//         newtemp->link = copytemp;

//         oldtemp = oldtemp->link;
//         newtemp = newtemp->link;
//     }
// }

// M-2

// void copy()
// {
//     if (FIRST1 == NULL){

//         FIRST2 = NULL;
//         return;

//     }

//     FIRST2 = (struct Node *)malloc(sizeof(struct Node));

//     FIRST2->info = FIRST1->info;
//     FIRST2->link = NULL;

//     struct Node *save = FIRST1->link; // karn k pelo element to bani j gyon che so apde ahiya bija element thi startkarvanu che so
//     struct Node *save2 = FIRST2;

//     while (save != NULL)
//     {
//         struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

//         newNode->info = save->info;
//         newNode->link = NULL;

//         save2->link = newNode;

//         save2 = save2->link;
//         save = save->link;
//     }
// }

// M-3

void insertAtLast2(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = NULL;

    if (FIRST2 == NULL)
    {
        FIRST2 = newNode;
        return;
    }

    struct Node *save = FIRST2;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

void copy()
{
    if (FIRST1 == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    struct Node *save = FIRST1;

    while (save != NULL)
    {
        insertAtLast2(save->info);
        save = save->link;
    }
}

int main()
{
    insertAtFirst(9);
    insertAtFirst(8);
    insertAtFirst(8);
    insertAtFirst(8);
    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);
    insertAtFirst(6);

    copy();

    printf("Original List:\n");
    display(FIRST1);

    printf("\nCopied List:\n");
    display(FIRST2);

    return 0;
}