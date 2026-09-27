// 95. Write a program to implement Quick Sort using Array. 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Algorithm of Quick Sort
// 1. Choose a pivot element from the array.
// 2. Partition the array into two sub-arrays: elements less than or equal to the pivot and elements greater than the pivot.
// 3. Recursively apply the above steps to the two sub-arrays.

int partition(int arr[] , int st , int en){

    int idx = st - 1 , pivot = arr[en];

    for(int j=st ; j<en ; j++){     // Traverse the array and rearrange elements based on pivot    

        if(arr[j] <= pivot){

            idx++;
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;

        }
    }

    idx++;
    
    // Place the pivot element at its correct position
    int temp = arr[en];
    arr[en] = arr[idx];
    arr[idx] = temp;

    return idx;
    
}

void quickSort(int arr[] ,int st ,int en){

    if(st < en){

        int pivot = partition(arr,st,en);

        quickSort(arr,st,pivot - 1);        // left half
        quickSort(arr,pivot + 1 , en);      // right half

    }

}

void main()
{
    int size;

    printf("Enter size of array: \n");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of array : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
        
    quickSort(arr, 0 , size-1);

    printf("Sorted Array: \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}