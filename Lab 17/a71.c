// 71. Write a program to implement queue using singly linked list. 

#include <stdio.h>
#include <stdlib.h>

struct Node{
    
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value){   // Insert At Last

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL){
        
        front = rear = newNode;
    }
    else{

        rear->next = newNode;
        rear = newNode;
    }
    
    printf("%d enqueued to queue\n", value);
}

int dequeue(){   // Remove From Front

    if (front == NULL){

        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = front;

    int value = front->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;
        
    free(temp);
    return value;
}

int peek(){

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display(){

    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){

    int choice, value;
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value != -1)
                printf("Dequeued value: %d\n", value);
            break;
        case 3:
            value = peek();
            if (value != -1)
                printf("Front element: %d\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting program.\n");
            return;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

}