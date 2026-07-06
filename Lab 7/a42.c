// 42. Write a menu driven program to implement following operations on the singly
// linked list.
// • Insert a node at the front of the linked list.
// • Display all nodes.
// • Delete a first node of the linked list.
// • Insert a node at the end of the linked list.
// • Delete a last node of the linked list.
// • Delete a node from specified position.
// • count the number of nodes

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

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    
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

void display(){
    
    if (first == NULL){
        printf("List Is Empty\n");
        return;
    }
    
    struct Node *save = first;

    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

void deleteAtStart()
{

    if (first == NULL)
    {
        printf("List Is Empty");
        return;
    }

    struct Node* temp = first;
    
    first = first->link;

    free(temp);
}

void deleteAtEnd(){
    
    if (first == NULL)
    {
        printf("List Is Empty");
        return;
    }

    // If only one node
    if (first->link == NULL) {
        free(first);
        first = NULL;
        return;
    }

    struct Node* save = first;

    // Traverse to the second last node
    // Must Be Remember That If We Want To Delete A Node Then Apde Te (Je Node Delete Karvano Che) Teni Agalna Node Par Stop Thai Javanu  
    while(save->link->link != NULL){

        save = save->link;
    }

    struct Node* temp = save->link;
    save->link = NULL;
    free(temp);

}
int countNodes()
{

    int count = 0 ;
    struct Node *save = first;

    if (save == NULL)
    {
        printf("List Is Empty");
        return 0;
    }

    while (save != NULL)
    {
        save = save->link;
        count++;
    }

    return count ;

}
void deleteAtPosition(int idx)
{

    if(first == NULL){
        printf("Cannot Delete Becasue Liked List Is Empty");
        return;
    }

    if (idx == 0){
        deleteAtFirst();
        return;
    }
    
    if (idx < 0 || idx >= countNodes())
    {
        printf("Enter Valid Idx.\n");
        return;
    }

    struct Node *save = first;

    for (int i = 1; i < idx; i++)
    {
        save = save->link;
    }

    struct Node *temp = save->link; // 8 9 0 10
    save->link = save->link->link;
    free(temp);
    
}



void main(){

    int choice, value, position;
    
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Display all nodes\n");
        printf("3. Delete first node\n");
        printf("4. Insert at end\n");
        printf("5. Delete last node\n");
        printf("6. Delete node at specified position\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteAtStart();
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete node: ");
                scanf("%d", &position);
                deleteNodeFromPosition(position);
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 8:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int info;
//     struct Node *link;
// };

// struct Node* insertAtFirst(struct Node *first, int x) {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->info = x;
//     newNode->link = first;
//     return newNode;   // new first
// }

// struct Node* insertAtLast(struct Node *first, int x) {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->info = x;
//     newNode->link = NULL;

//     if (first == NULL) {
//         return newNode;   // new node is first
//     }

//     struct Node *save = first;
//     while (save->link != NULL) {
//         save = save->link;
//     }
//     save->link = newNode;
//     return first;
// }

// void display(struct Node *first) {
//     if (first == NULL) {
//         printf("List is empty\n");
//         return;
//     }
//     while (first != NULL) {
//         printf("%d -> ", first->info);
//         first = first->link;
//     }
//     printf("NULL\n");
// }

// struct Node* deleteAtStart(struct Node *first) {
//     if (first == NULL) {
//         printf("List is empty\n");
//         return NULL;
//     }
//     struct Node *temp = first;
//     first = first->link;
//     free(temp);
//     return first;
// }

// struct Node* deleteAtEnd(struct Node *first) {
//     if (first == NULL) {
//         printf("List is empty\n");
//         return NULL;
//     }
//     if (first->link == NULL) {
//         free(first);
//         return NULL;
//     }
//     struct Node *save = first;
//     while (save->link->link != NULL) {
//         save = save->link;
//     }
//     free(save->link);
//     save->link = NULL;
//     return first;
// }

// struct Node* deleteNodeFromPosition(struct Node *first, int n) {
//     if (first == NULL) {
//         printf("List is empty\n");
//         return NULL;
//     }
//     if (n < 1) {
//         printf("Invalid position\n");
//         return first;
//     }
//     if (n == 1) {
//         struct Node *temp = first;
//         first = first->link;
//         free(temp);
//         return first;
//     }

//     struct Node *save = first;
//     for (int i = 1; save != NULL && i < n - 1; i++) {
//         save = save->link;
//     }

//     if (save == NULL || save->link == NULL) {
//         printf("Position out of range\n");
//         return first;
//     }

//     struct Node *temp = save->link;
//     save->link = save->link->link;
//     free(temp);
//     return first;
// }

// int countNodes(struct Node *first) {
//     int count = 0;
//     while (first != NULL) {
//         first = first->link;
//         count++;
//     }
//     return count;
// }

// int main() {
//     struct Node *first = NULL;
//     int choice, value, position;

//     printf("\nMenu:\n");
//     printf("1. Insert at front\n");
//     printf("2. Display all nodes\n");
//     printf("3. Delete first node\n");
//     printf("4. Insert at end\n");
//     printf("5. Delete last node\n");
//     printf("6. Delete node at specified position\n");
//     printf("7. Count nodes\n");
//     printf("8. Exit\n");

//     while (1) {
//         printf("Enter choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter value to insert at front: ");
//                 scanf("%d", &value);
//                 first = insertAtFirst(first, value);
//                 break;
//             case 2:
//                 display(first);
//                 break;
//             case 3:
//                 first = deleteAtStart(first);
//                 break;
//             case 4:
//                 printf("Enter value to insert at end: ");
//                 scanf("%d", &value);
//                 first = insertAtLast(first, value);
//                 break;
//             case 5:
//                 first = deleteAtEnd(first);
//                 break;
//             case 6:
//                 printf("Enter position to delete node: ");
//                 scanf("%d", &position);
//                 first = deleteNodeFromPosition(first, position);
//                 break;
//             case 7:
//                 printf("Number of nodes: %d\n", countNodes(first));
//                 break;
//             case 8:
//                 return 0;
//             default:
//                 printf("Invalid choice. Please try again.\n");
//         }
//     }
// }
