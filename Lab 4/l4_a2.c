// 25. Write a program to delete a number from a given location in an array.

#include <stdio.h>

void main()
{
    int n;

    printf("Enter Size Of Array : ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    int idx;

    printf("Enter Index To Delete : ");
    scanf("%d", &idx);

    if(idx < 0 || idx >= n)
    {
        printf("Invalid Index");
        return;
    }

    for(int i = idx; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Array After Deletion:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}