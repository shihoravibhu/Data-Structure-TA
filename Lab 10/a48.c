// 48. WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

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

int count()
{
    int cnt = 0;

    struct Node *save = FIRST;

    while (save != NULL)
    {
        cnt++;
        save = save->link;
    }

    return cnt;
}

// void kthSwap(int k)
// {
//     int n = count();

//     if (k <= 0 || k > n)
//     {
//         printf("Invalid k\n");
//         return;
//     }

//     // Same node
//     if (2 * k - 1 == n)
//     {
//         printf("No Need To Swap\n");
//         return;
//     }

//     struct Node *prev1 = NULL;
//     struct Node *save1 = FIRST;

//     // kth node from beginning
//     for (int i = 1; i < k; i++)
//     {
//         prev1 = save1;
//         save1 = save1->link;
//     }

//     struct Node *prev2 = NULL;
//     struct Node *save2 = FIRST;

//     // kth node from end
//     for (int i = 1; i < n - k + 1; i++)
//     {
//         prev2 = save2;
//         save2 = save2->link;
//     }

//     // Connect previous nodes
//     if (prev1 != NULL)
//     {
//         prev1->link = save2;
//     }
//     else
//     {
//         FIRST = save2;
//     }

//     if (prev2 != NULL)
//     {
//         prev2->link = save1;
//     }
//     else
//     {
//         FIRST = save1;
//     }

//     // Swap links
//     struct Node *temp = save1->link;

//     save1->link = save2->link;
//     save2->link = temp;
// }

void kthSwap(int k)
{
    int n = count();

    if (k <= 0 || k > n)
    {
        printf("Invalid k\n");
        return;
    }

    // Same node
    if (2 * k - 1 == n)
    {
        printf("No Need To Swap\n");
        return;
    }

    struct Node *save1 = FIRST;

    // kth node from beginning
    for (int i = 1; i < k; i++)
    {
        save1 = save1->link;
    }

    struct Node *save2 = FIRST;

    // kth node from end
    for (int i = 1; i < n - k + 1; i++)
    {
        save2 = save2->link;
    }

    int temp = save1->info;
    save1->info = save2->info;
    save2->info = temp;   

    
}

void main()
{
    insertAtFirst(11);
    insertAtFirst(9);
    insertAtFirst(7);
    insertAtFirst(5);
    insertAtFirst(3);
    insertAtFirst(1);

    display();

    kthSwap(1);

    display();

}