// 54. Write a menu driven program to implement following operations on the doubly 
// linked list. 
// • Insert a node at the front of the linked list. 
// • Delete a node from specified position. 
// • Insert a node at the end of the linked list. (Home Work) 
// • Display all nodes. (Home Work) 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* rptr;
    struct Node* lptr;
};

struct Node* FIRST = NULL;

void inserAtFirst(int val){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = val;
    newNode->rptr = NULL;
    newNode->lptr = NULL;
    
    if(FIRST == NULL){
        FIRST = newNode;
    }
    else{

        newNode->rptr = FIRST;
        FIRST->lptr = newNode;
        FIRST = newNode;

    }
}

void insertAtEnd(int val){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = val;
    newNode->rptr = NULL;
    newNode->lptr = NULL;

    if(FIRST == NULL){
        FIRST = newNode;

        return;
    }
    
    struct Node *save = FIRST;

    while(save->rptr != NULL){
        save = save->rptr;
    }

    save->rptr = newNode;
    newNode->lptr = save;

}

void deleteAtFront(){

    if(FIRST == NULL){
        printf("Empty");
        return;
    }
    else if(FIRST->rptr == NULL){   // Ek Element Mate

        struct Node* temp = FIRST;
        FIRST = NULL;
        free(temp);
        return;
    }

    struct Node* temp = FIRST;
    FIRST = FIRST->rptr;
    FIRST->lptr = NULL;
    free(temp);

}

void display(){

    if(FIRST == NULL){
        printf("List Is Empty\n");
        return;
    }

    struct Node* save = FIRST;

    while(save != NULL){

        printf("%d <-> " , save->info);

        save = save->rptr;
    }

    printf("NULL\n");

}

int count(){

    int count = 0;

    struct Node* save = FIRST;

    while(save != NULL){
        save = save->rptr;
        count++;
    }


    return count;
}

void deleteAtEnd(){

    if(FIRST == NULL){
        printf("Empty");
        return;
    }
    else if(FIRST->rptr == NULL){   // Ek Element Mate

        struct Node* temp = FIRST;
        FIRST = NULL;
        free(temp);
        return;
    }

    struct Node* save = FIRST;

    while(save->rptr->rptr != NULL){
        save = save->rptr;
    }

    struct Node* temp = save->rptr;
    save->rptr = NULL;
    temp->lptr = NULL;

    free(temp);

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

    temp->rptr->lptr = save;
    free(temp);

    // if(temp->rptr != NULL){  //  no need coz we are handling deleteFromEnd separately
        // temp->rptr->lptr = save;
    // }
    

}

void main(){

    int choice, val, pos;

    do
    {
        printf("1. Insert At First\n");
        printf("2. Insert At End\n");
        printf("3. Delete At Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d", &val);

                inserAtFirst(val);
                break;

            case 2:
                printf("Enter Value : ");
                scanf("%d", &val);

                insertAtEnd(val);
                break;

            case 3:
                printf("Enter Position : ");
                scanf("%d", &pos);

                deleteAtKthPosition(pos);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);


}