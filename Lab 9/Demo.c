#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info ;
    struct Node* link;
};

struct Node* FIRST1 = NULL;
struct Node* FIRST2 = NULL;

void copy(){

    FIRST2 = (struct Node*) malloc(sizeof(struct Node));

    FIRST2->info = FIRST1->info;
    FIRST2->link = NULL;
    
    struct Node* save1 = FIRST1->link;
    struct Node* save2 = FIRST2;

    while(save1 != NULL){

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

        newNode->info = save1->info;
        newNode->link = NULL;

        save2->link = newNode;

        save1 = save1->link;
        save1 = save2->link;

    }
}

void rev(){

    struct Node* prev = NULL;
    struct Node* curr = FIRST1;
    struct Node* next = NULL;

    while(curr != NULL){
        next = curr->link;
        curr->link = prev;

        prev = curr;
        curr = next;
    }

    FIRST1 = prev;      
}
void main(){

}