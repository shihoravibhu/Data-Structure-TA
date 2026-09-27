// 90. Write a program to implement a Binary Search using Array. (Iterative & recursive)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool binarySearch(int arr[], int size,int n)
{ // Interative

    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == n){
            return true;
        }
        else if (arr[mid] < n){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return false;
}

bool binarySearchRec(int arr[], int size, int left, int right,int n)        //Recurison
{   
    
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == n){
            return true;
        }
        else if (arr[mid] < n){
            return binarySearchRec(arr, size, mid + 1, right,n);
        }
        else{           
            return binarySearchRec(arr, size, left, mid - 1,n);
        }
    }
    return false;
}

void main()
{
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of array (Array Must Be Sorted): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n;
    printf("Enter Search Element : ");
    scanf("%d", &n);

    // if(binarySearch(arr,size,n)){
    //     printf("Available In Array");
    // }
    // else{

    //     printf("Not Available In Array");
    // }

    if (binarySearchRec(arr, size, 0, size - 1,n))
    {
        printf("Available In Array");
    }
    else
    {

        printf("Not Available In Array");
    }
}