// 91. Write a program to implement Bubble using Array. 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size){ 

    for(int i=0 ; i<size-1 ; i++){
        for(int j=0 ; j<size-1-i ; j++){

            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
        
    bubbleSort(arr, size);

    printf("Sorted Array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}