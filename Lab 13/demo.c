#include<stdio.h>
#define size 100

int stack[size];
int top = -1;

void push(int val){

    if(top >= size-1){
        printf("OverFlow\n");
        return;
    }

    top++;
    stack[top] = val;

}

int pop(){

    if(top == -1){
        printf("UnderFlow\n");
        return -1;
    }

    int p = stack[top];

    top--;

    return p;
}

void display(){

    if(top == -1){
        printf("Underflow\n");
        return;
    }

    for(int i = top ; i >= 0 ; i--){
        printf("%d " , stack[i]);
    }
}

int peep(int idx){

    int arrIdx = top - idx + 1;

    if(idx <= 0 || arrIdx < 0){
        printf("Invalid \n");
        return -1;
    }

    return stack[arrIdx];
}
void change(int idx , int n){

    int arrIdx = top - idx + 1;

    if(idx <= 0 || arrIdx < 0){
        printf("Invalid \n");
        return ;
    }

    stack[arrIdx] = n;

}