
// 96. Given an array nums with n objects colored red, white, or blue, sort them in
// place so that objects of the same color are adjacent, with the colors in the order 
// red, white, and blue. We will use the integers 0, 1, and 2 to represent the color 
// red, white, and blue, respectively. 
// Sample Example-1: 
// Input: nums = [2,0,2,1,1,0]    
// Output: [0,0,1,1,2,2] 
// Sample Example-2: 
// Input: nums = [2,0,1]    
// Output: [0,1,2] 

#include <stdio.h>

void sortColors(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high)
    {
        // If 0 Aviyo 
        if(a[mid] == 0)
        {
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;

            low++;
            mid++;
        }

        // If 1 Aviyo
        else if(a[mid] == 1)
        {
            mid++;
        }

        // If 2 Aviyo
        else
        {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;

            high--;
        }
    }
}

void main()
{
    int a[] = {2, 0, 2, 1, 1, 0};

    int n = 6;

    sortColors(a, n);

    printf("Sorted Array : ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

}