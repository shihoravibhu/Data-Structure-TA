// 43. WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int info;
    struct Node* link;
};

struct Node* FIRST1 = NULL;
struct Node* FIRST2 = NULL;

void insertAtFirst1(int x){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST1;
    FIRST1 = newNode;

}
void insertAtFirst2(int x){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = FIRST2;
    FIRST2 = newNode;

}
void insertAtLast1(int x){

    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    newNode->info = x;
    newNode->link = NULL;

    if(FIRST1 == NULL){
        FIRST1 = newNode;
        return;
    }
   
    struct Node* save = FIRST1;

    while(save->link != NULL){
        save = save->link;
    }

    save->link = newNode;

}

void deleteAtFirst(){

    if(FIRST1 == NULL){
        printf("Empty\n");
        return;
    }

    if(FIRST1->link == NULL){
        struct Node* temp = FIRST1;
        FIRST1 = NULL;
        free(temp);
        return;
    }
    struct Node* temp = FIRST1;
    FIRST1 = FIRST1->link;
    free(temp);


}
void deleteAtLast(){

    if(FIRST1 == NULL){
        printf("Empty\n");
        return;
    }

    if(FIRST1->link == NULL){
        struct Node* temp = FIRST1;
        FIRST1 = NULL;
        free(temp);
        return;
    }

    struct Node* save = FIRST1;

    while(save->link->link != NULL){
        save = save->link;
    }

    struct Node* temp = save->link;
    save->link = temp->link;
    free(temp);


}

int count(){

    struct Node* save = FIRST1;

    int i = 0;

    while(save != NULL){
        save = save->link;
        i++;
    }

    return i;
}

void deleteAtPosition(int idx){

    if(FIRST1 == NULL){
        printf("Empty\n");
        return;
    }

    if(idx < 0 || idx >= count()){
        printf("Not Valid Index\n");
        return;
    }

    if(idx == 0){
        deleteAtFirst();
        return;
    }

    struct Node* save = FIRST1;

    // 2 6 2 8 3 7     idx = 3
    // 0 1 2 3 4 5

    for(int i = 1 ; i < idx ; i++){
        save = save->link;
    }

    struct Node* temp = save->link;
    save->link = temp->link;
    free(temp);

}

bool isSame(){

    struct Node* save1 = FIRST1;
    struct Node* save2 = FIRST2;


    while(save1 != NULL && save2 != NULL){

        if(save1->info != save2->info){
            
            printf("Both Are Not Same\n");
            return false;
        }
        else{
            save1 = save1->link;
            save2 = save2->link;
        }
    }

    if(save1 == NULL && save2 == NULL){
        printf("Both Are Same\n");
        return true;
    }else{
        printf("Both Are Not Same\n");
        return false;
    }
}

void removeDuplicate(){

     if(FIRST1 == NULL){
        printf("\nList Is Empty");
        return;
    }

    struct Node* save = FIRST1;

    while(save->link != NULL){

        if(save->info == save->link->info){

            struct Node* temp = save->link;
            save->link = temp->link;
            free(temp);
        }
        else{
            save = save->link;
        }

    }


}


void main(){

}