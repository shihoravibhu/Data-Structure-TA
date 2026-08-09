// 73. Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue

#include <stdio.h>

#define SIZE 5

int deque[SIZE];

int front = -1;
int rear = -1;

// Insert at Front Mate
void insertFront(int val)
{
    if(front == 0){
        printf("Deque Full at Front\n");
        return;
    }

    // Pelo element
    if(front == -1){
        front = rear = 0;
    }
    else{
        front--;
    }

    deque[front] = val;
}

// Insert at Rear Mate
void insertRear(int val)
{
    if(rear == SIZE - 1)
    {
        printf("Deque Full at Rear\n");
        return;
    }

    // Pelo element
    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = val;
}

// Delete from Front Mate
void deleteFront()
{
    if(front == -1){
        printf("Deque Empty\n");
        return;
    }

    int y = deque[front];

    if(front == rear){          // Ek J Element Hoi Tyare
        front = rear = -1;
    }
    else{
        front++;
    }

    // return y;
    printf("Deleted : %d\n", y);
}

// Delete from Rear Mate
void deleteRear()
{
    if(rear == -1)
    {
        printf("Deque Empty\n");
        return;
    }

    int y = deque[rear];

    // Last element
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }

    // return y;
    printf("Deleted : %d\n", y);
}

void display()
{
    if(front == -1)
    {
        printf("Deque Empty\n");
        return;
    }

    printf("Deque : ");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", deque[i]);
    }

    printf("\n");
}

void main()
{
    int choice, val;

    do
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d", &val);
                insertFront(val);
                break;

            case 2:
                printf("Enter Value : ");
                scanf("%d", &val);
                insertRear(val);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exit");
                break;

            default:
                printf("Invalid Choice");
        }

    } while(choice != 6);

}