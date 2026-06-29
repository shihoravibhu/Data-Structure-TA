// 38. WAP to sort the array elements using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;

    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory Allocation Failed");
        return ;
    }

    for(int i = 0; i < n; i++)
    {
        printf("Enter Element arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    // Sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
   
}