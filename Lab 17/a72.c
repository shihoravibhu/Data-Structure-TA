// 72. Write a menu driven program to implement following operations on a circular 
// queue using an Array 
// • Insert 
// • Delete 
// • Display all elements of the queue 

#include <stdio.h>

#define N 5

int CQ[N];
int FRONT = -1;
int REAR = -1;

void enqueue(int x)
{
    // Overflow Check Karva In Circular Queue
    if ((REAR + 1) % N == FRONT)
    {
        printf("Queue Overflow\n");
        return;
    }

    // Pelo element
    if (FRONT == -1)
    {
        FRONT = 0;
    }
    
    REAR = (REAR + 1) % N;
    

    CQ[REAR] = x;
}

void dequeue()
{
    if (FRONT == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int y = CQ[FRONT];

    // Jyare Only One J Element Hoi Tyare
    if (FRONT == REAR){
        FRONT = REAR = -1;
    }
    else{
        FRONT = (FRONT + 1) % N;
    }

    printf("Deleted : %d\n", y);
}

void display()
{
    if (FRONT == -1)
    {
        printf("Queue Is Empty\n");
        return;
    }

    int i = FRONT;

    printf("Queue : ");

    while (i != REAR){

        printf("%d ", CQ[i]);

        i = (i + 1) % N;   
    }

    printf("%d ", CQ[REAR]);

    printf("\n");
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    peek();

}