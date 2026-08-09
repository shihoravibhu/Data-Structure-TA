// 74. WAP to implement Priority Queue.

// Ahiya Min Priority Queue No Code Karel Che Means 
// Je Smallest element Teni highest priority
// Ane Jeni Highest Priority Te Pela Delete Means (Delete the minimum element First)

// You Can Also Be Write Max Priority Queue No Code Etle K Ema Je Largest Element Teni Highest Priority

#include <stdio.h>

#define N 5   // maximum size of queue

int pq[N];
int size = 0;    // current size

// no need of front and rear

void insert(int val)
{
    if(size == N)
    {
        printf("Priority Queue Full\n");
        return;
    }

    pq[size] = val;
    size++;

    printf("Inserted\n");
}

// Delete highest priority Etle k Ahiya Apde Smallest Element Ne Delete
void delete()
{
    // empty chhe
    if(size == 0){
        printf("Priority Queue Empty\n");
        return;
    }

    // minimum element ni index
    int minIndex = 0;

    // Find Karo smallest element
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
        {
            minIndex = i;
        }
    }

    int y = pq[minIndex];

    // Shift elements left
    for(int i = minIndex; i < size-1; i++){
        pq[i] = pq[i + 1];
    }

    size--;

    // return y;
    printf("Deleted element: %d\n", y);
}

void display()
{
    if(size == 0)
    {
        printf("Priority Queue Empty\n");
        return;
    }

    printf("Priority Queue : ");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }

    printf("\n");
}

void main()
{
    int choice, val;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid Choice");
        }

    } while(choice != 4);

}