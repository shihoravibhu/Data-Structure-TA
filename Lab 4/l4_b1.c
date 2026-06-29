// 27. Write a program to delete a number from an array that is already sorted in an
// ascending order.

#include <stdio.h>

void main()
{

    int pos = -1;

    int a[5];

    for (int i = 0; i < 5; i++)
    {

        printf("Enter Element a[%d] :", i);
        scanf("%d", &a[i]);
    }

    int n;

    printf("Enter Element : ");
    scanf("%d", &n);

    for (int i = 0; i < 5; i++)
    {

        if (a[i] == n)
        {
            pos = i;
            break;
        }

        if (a[i] > n)
        {
            break;
        }
    }

    // printf("\n pos : %d \n" , pos);

    if (pos == -1)
    {
        printf("Element not found");
    }
    else
    {

        for (int i = pos; i < 4; i++)
        {
            a[i] = a[i + 1];
        }

        for (int i = 0; i < 4; i++)
        {
            printf("%d ", a[i]);
        }
    }
}