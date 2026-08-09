// 74. WAP to implement Priority Queue.

#include <stdio.h>

#define SIZE 5

struct Node
{
    int data;
    int priority;
};

struct Node pq[SIZE];
int size = 0;

void enqueue(int data, int priority)
{
    if(size == SIZE)
    {
        printf("Priority Queue Full\n");
        return;
    }

    pq[size].data = data;
    pq[size].priority = priority;
    size++;

    printf("Inserted\n");
}

// Here We Implement Min Priority Queue So Pela Apde Smallest Priority Vada Element Ne Delete Kariye Chiye
void dequeue()
{
    if(size == 0)
    {
        printf("Priority Queue Empty\n");
        return;
    }

    int minIndex = 0;

    // Jeni Priority Smallest Che Teni Idx Find 
    for(int i = 1; i < size; i++)
    {
        if(pq[i].priority < pq[minIndex].priority)
        {
            minIndex = i;
        }
    }

    printf("Deleted : %d (Priority = %d)\n",
            pq[minIndex].data,
            pq[minIndex].priority);

    // Elements Ne Left Shift Kariya 
    for(int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display()
{
    if(size == 0)
    {
        printf("Priority Queue Empty\n");
        return;
    }

    printf("Data | Priority\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d | %d\n", pq[i].data, pq[i].priority);
    }
}

void main()
{
    enqueue(30, 2);
    enqueue(10, 1);
    enqueue(50, 3);
    enqueue(20, 0);

    display();  // 30 2
                // 10 1
                // 50 3
                // 20 0

    dequeue(); // obv. ahiya Apde Min Priority Queue Implement Kariyu Che To Pela Smallest Priority Vado Element Etle Ahiya 20 (Jeni Priority Smallest 0 Che) Te Delete Thase

    display(); // 30 2
               // 10 1
               // 50 3
}