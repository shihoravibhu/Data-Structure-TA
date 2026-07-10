// 44. Write a program to remove the duplicates nodes from given sorted Linked List. 
//  • Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
//  • Output: 1 → 6 → 13 → 27 

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
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST;

    FIRST = newNode;
}

void insertAtLast(int x)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

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

void removeDuplicate()
{

    if(FIRST == NULL){
        printf("\nList Is Empty");
        return;
    }
    
    struct Node *save = FIRST;

    while (save != NULL && save->link != NULL)
    {
        if (save->info == save->link->info){

            struct Node *temp = save->link;
            save->link = save->link->link;
            free(temp);
            
        }
        else{
            save = save->link;
        }
    }
}

void main()
{
    // insertAtFirst(9);
    insertAtFirst(8);
    insertAtFirst(8);
    insertAtFirst(8);
    insertAtFirst(8);
    // insertAtFirst(7);
    // insertAtFirst(6);
    // insertAtFirst(6);

    display();

    removeDuplicate();

    display();

}
