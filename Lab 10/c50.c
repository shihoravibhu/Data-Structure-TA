// 50. Write a program to swap two consecutive nodes in the linked list. Don’t change 
// the values of nodes, implement by changing the link of the nodes. 
// Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
// Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 

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

// void swapPairs()
// {
//     if (FIRST == NULL || FIRST->link == NULL)
//     {
//         return;
//     }

//     struct Node *prev = NULL;
//     struct Node *save = FIRST;

//     FIRST = FIRST->link;

//     while (save != NULL && save->link != NULL)
//     {
//         struct Node *temp = save->link;
//         struct Node *nextPair = save->link->link;  

//         save->link = nextPair;
//         temp->link = save;

//         // Connect kariyu previous pair
//         if (prev != NULL)
//         {
//             prev->link = temp;
//         }

//         // next ma move
//         prev = save;
//         save = nextPair;
//     }
// }

void swapPairs(){
    
    if (FIRST == NULL || FIRST->link == NULL)
        return;

    struct Node *prev = NULL;
    struct Node *pelo = FIRST;  // save

    FIRST = FIRST->link;

    while (pelo != NULL && pelo->link != NULL)
    {
        struct Node *bijo = pelo->link;
        struct Node *trijo = bijo->link;

        pelo->link = trijo;
        bijo->link = pelo;

        if (prev != NULL)
            prev->link = bijo;

        prev = pelo;
        pelo = trijo;
    }
}

// void swapPairs(){
    
//     if (FIRST == NULL || FIRST->link == NULL){
//         return;
//     }          
    
//     struct Node * save=FIRST;

//     FIRST=FIRST->link;
    
//     struct Node* third;
//     struct Node* second;

//     while(save!=NULL && save->link!= NULL)
//     {
//         third=save->link->link;
//         second =save->link;
//         second->link=save;

//         if(third!=NULL && third->link!=NULL)
//         {
//             save->link=third->link;
//         }
//         else
//         {
//             save->link=third;
//         }
//         save=third;
//     }


// }

int main()
{
    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    display();

    swapPairs();

    display();

    return 0;
}