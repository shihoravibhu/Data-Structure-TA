// 94. Write a program to implement Merge Sort using Array. 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// two subarray ne merge karva mate nu function
void merge(int arr[],int size, int low,int mid,int high){

    int h,i,j,k;

    int b[size];

    h = low;        // left subArray no pointer
    i = low;       
    j = mid + 1;     // right subArray no pointer
    
    while(h <= mid && j <= high){       // Compare elements from both halves and copy smaller one into temp array b[] 

        if(arr[h] <= arr[j]){

            b[i] = arr[h];
            h++;

        }
        else{

            b[i] = arr[j];
            j++;
        }

        i++;
    }

    while(h <= mid){        // it means left subarray is exhausted, so we only copy remaining right subarray.

        b[i] = arr[h];
        h++;
        i++; 
    }
    
    while(j <= high){       // it means right subarray is exhausted, so we only copy remaining left subarray.

        b[i] = arr[j];
        j++;
        i++;
    }
    
    for(int i=low ; i<=high ; i++){

        arr[i] = b[i];
        
    }
}


void mergeSort(int arr[],int size, int low,int high){ 

    if(low < high){

        int mid = low + (high-low)/2;
        
        mergeSort(arr,size,low,mid);        // sort left half
        mergeSort(arr,size,mid + 1,high);   // sort right half

        merge(arr,size,low,mid,high);        // Merge the sorted halves
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
        
    mergeSort(arr,size, 0 , size-1);

    printf("Sorted Array: \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}