// 51. Write a menu driven program to implement following operations on the circular 
// linked list. 
// • Insert a node at the front of the linked list. 
// • Delete a node from specified position. 
// • Insert a node at the end of the linked list. 
// • Display all nodes.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node* link;
};

struct Node* FIRST = NULL;
struct Node* LAST = NULL;

void insertAtFirst(int val){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = val;

    if(FIRST == NULL){  // Jyare List Empty Hoi Tyare

        FIRST = LAST = newNode;
        LAST->link = FIRST;
        
    }
    else{

        newNode->link = FIRST;
        FIRST = newNode;
        LAST->link = FIRST;

    }

}

void insertAtLast(int val){
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = val;

    if(FIRST == NULL){  // Jyare List Is Empty Hoi Tyare

        FIRST = LAST = newNode;
        LAST->link = FIRST;
        
    }
    else{

        LAST->link = newNode;
        LAST = newNode;
        LAST->link = FIRST;

    }
}

void deleteAtFirst(){

    if(FIRST == NULL){
        printf("List Is Empty");
        return;
    }
    else if(FIRST == LAST){  // Jyare Only One Element Hoi Tyare 
        struct Node* temp = FIRST;
        FIRST = LAST = NULL;
        free(temp);
        return;
    }
    else{   // Ek Karta Vadhare Element Hoi Tyare

        struct Node* temp = FIRST;
        FIRST = FIRST->link;
        LAST->link = FIRST;
        free(temp);
        return;

    }
}

void display(){

    if(FIRST == NULL){
        printf("Empty");
        return;
    }

    struct Node* save = FIRST->link;

    printf("%d -> ",FIRST->info);

    while(save != FIRST){

        printf("%d -> " , save->info);
        save = save->link;

    }

    printf("%d\n" , save->info);

}

int count(){
    if(FIRST == NULL)
        return 0;

    struct Node* save = FIRST->link;

    int count = 1;

    while(save != FIRST){
        save = save->link;
        count++;
    }

    return count;
}

void deleteAtKthPosition(int k){

    int n = count();

    if(FIRST == NULL){
        return;
    }
    else if(k == 0){
        deleteAtFirst();
        return;
    }
    else if(k == n-1){
        // delete from last
        return;
    }
    else if(k < 0 || k >= n){
        printf("Invalid Index\n");
        return;
    }
    else{

        struct Node* save = FIRST;   //  1 2 3 4 5

        for(int i = 1 ; i < k ; i++){
           
            save = save->link;
        }

        struct Node* temp = save->link;
        
        save->link =  save->link->link;
        
        free(temp);
          
    }
}

void main(){

    // insertAtFirst(4);
    // insertAtFirst(3);
    // insertAtFirst(2);
    // insertAtFirst(1);

    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(4);

    display();

    deleteAtKthPosition(3);

    display();

}