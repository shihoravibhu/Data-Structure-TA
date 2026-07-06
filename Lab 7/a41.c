// 41. Write a program to implement a node structure for singly linked list. Read the 
// info in a node, print the node. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void main()
{
    struct Node *first;

    first = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter Data : ");
    scanf("%d", &first->info);

    first->link = NULL;

    printf("\nNode Data : %d\n", first->info);

    free(first);

}