// 47. Write a program to sort elements of a linked list. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

void insertAtLast(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = val;
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

    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL\n");
}

void sort()
{
    struct Node *i;
    struct Node *j;

    for (i = FIRST; i->link != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->info > j->info)
            {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Sort by changing links instead of swapping info

// void sort()
// {
//     if (FIRST == NULL || FIRST->link == NULL)
//     {
//         return;
//     }

//     int swapped;
//     struct Node **save;

//     do
//     {
//         swapped = 0;
//         save = &FIRST;

//         while ((*save)->link != NULL)
//         {
//             struct Node *FIRST = *save;
//             struct Node *second = (*save)->link;

//             if (FIRST->info > second->info)
//             {
//                 FIRST->link = second->link;
//                 second->link = FIRST;

//                 *save = second;

//                 swapped = 1;
//             }

//             save = &((*save)->link);
//         }

//     } while (swapped);
// }

// or

// void sort()
// {
//     if (FIRST == NULL || FIRST->link == NULL)
//         return;

//     int swapped;

//     do
//     {
//         swapped = 0;

//         struct Node *prev = NULL;
//         struct Node *curr = FIRST;

//         while (curr != NULL && curr->link != NULL)
//         {
//             struct Node *next = curr->link;

//             if (curr->info > next->info)
//             {
//                 // Swap links
//                 curr->link = next->link;
//                 next->link = curr;

//                 if (prev == NULL)
//                 {
//                     FIRST = next;
//                 }
//                 else
//                 {
//                     prev->link = next;
//                 }

//                 prev = next;
//                 swapped = 1;
//             }
//             else
//             {
//                 prev = curr;
//                 curr = curr->link;
//             }
//         }

//     } while (swapped);
// }

void main()
{
    insertAtLast(4);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(2);
    insertAtLast(5);
    insertAtLast(3);
    insertAtLast(1);
    insertAtLast(4);

    printf("Original List:\n");
    display();

    sort();

    printf("\nSorted List:\n");
    display();

}