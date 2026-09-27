// 92. Write a program to implement Selection Sort using Array.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void selectionSort(int arr[], int size){ 
    
    for(int i = 0; i < size-1; i++){

        int min = i;  // assume current i ee minimum chee

        for(int j = i+1; j < size; j++){

            if(arr[j] < arr[min]){
                min = j;  // min karta pan koi nano element madio 
            }

        }
        
        // Swap only once after finding the minimum
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
        
    selectionSort(arr, size);

    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}