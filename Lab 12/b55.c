// 55. WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *FIRST = NULL;

void inserAtFirst(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if (FIRST == NULL)
    {
        FIRST = newNode;
    }
    else
    {
        newNode->rptr = FIRST;
        FIRST->lptr = newNode;
        FIRST = newNode;
    }
}

void insertAtEnd(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if (FIRST == NULL)
    {
        FIRST = newNode;
        return;
    }

    struct Node *save = FIRST;

    while (save->rptr != NULL)
    {
        save = save->rptr;
    }

    save->rptr = newNode;
    newNode->lptr = save;
}

void display()
{
    if (FIRST == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    struct Node *save = FIRST;

    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->rptr;
    }

    printf("NULL\n");
}

void deleteAtKthPosition(int k){

    int n = count();

    if(k == 0){
        deleteAtFront();
        return;        
    }
    else if(k == n-1){
        deleteAtEnd();
        return; 
    }
    else if(k < 0 || k >= n){
        printf("Invalid Index");
        return;
    }

    struct Node* save = FIRST;

    for(int i = 1 ; i < k ; i++){
        save = save->rptr;
    }

    struct Node* temp = save->rptr; // 1 2 3 4 5

    save->rptr = save->rptr->rptr;

    if(temp->rptr != NULL){
        temp->rptr->lptr = save;
    }
    
    free(temp);

}

void deleteAlternateNode()
{
    if (FIRST == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    struct Node *save = FIRST;

    while (save != NULL && save->rptr != NULL)
    {
        struct Node *temp = save->rptr;

        save->rptr = temp->rptr;

        if (temp->rptr != NULL)
        {
            temp->rptr->lptr = save;
        }

        free(temp);

        save = save->rptr;
    }
}

void main()
{
    inserAtFirst(8);
    inserAtFirst(7);
    inserAtFirst(6);
    inserAtFirst(5);
    inserAtFirst(4);
    inserAtFirst(3);
    inserAtFirst(2);
    inserAtFirst(1);

    display();

    insertAtEnd(9);

    display();

    deleteAlternateNode();

    display();

}