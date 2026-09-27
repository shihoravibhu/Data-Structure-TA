// 93. Write a program to implement Insertion Sort using Array.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void insertionSort(int arr[], int size){ 

    for(int i=1 ; i<size ; i++){

        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
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
        
    insertionSort(arr, size);

    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}