// 70. Write a menu driven program to implement following operations on the Queue
// using an Array
// • ENQUEUE
// • DEQUEUE
// • DISPLAY

#include <stdio.h>

#define N 100

int queue[N];
int front = -1, rear = -1;

void enqueue(int val)
{

    if (rear >= N - 1)
    {
        printf("Queue Is OverFlow.\n");
        return;
    }

    
    queue[++rear] = val;
    printf("%d Is Enqueued.\n", val);

    if (front == -1)
    {
        front = 0;
    }
}

void dequeue()
{

    if (front == -1)
    {
        printf("Queue Is UnderFlow.\n");
        return;
    }

    int y = queue[front];
    
    if (front == rear){      // only one element
        front = rear = -1;
    }
    else{
        front++;
    }

    // return y;
    printf("%d Is Dequeued.\n", y);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void main()
{

    int choice, val;
    while (1)
    {
    
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to Enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting..!\n");
            return;
        default:
            printf("Invalid Choice!\n");
        }
    }
}