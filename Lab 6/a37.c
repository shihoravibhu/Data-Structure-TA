// 37. WAP to find the largest element in the array using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main()
{

    int n;
    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {

        printf("Mamory Allocation Failed\n");
    }

    else
    {

        printf("Enter Elements");
        for (int i = 0; i < n; i++)
        {
            printf("Enter Elemnet arr[%d] :", i);
            scanf("%d", &arr[i]);
        }

        int max = arr[0];
        
        for (int i = 0; i < n; i++)
        {

            if (max < arr[i])
            {
                max = arr[i];
            }
        }

        printf("Largest Element : %d", max);
        free(arr);
    }
}