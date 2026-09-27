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

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int nums[] = {2,0,2,1,1,0};
    int n = 6;

    bubbleSort(nums, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

}