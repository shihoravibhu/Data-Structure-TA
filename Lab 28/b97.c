// 97. You are given an array of positive integers and an integer K. Find the maxLength of 
// the longest subarray such that the sum of the subarray is less than or equal to K. 
// Input: 
// • An array arr[] of size N 
// • An integer K 
// Output: 
// • Length of the longest subarray with sum ≤ K

#include<stdio.h>

int max(int a , int b){

    return a > b ? a : b;

}

void main(){

    // arr = [2, 1, 3, 1, 1]
    // K = 5
    
    // ans : maxLen 3


    int n , k;

    printf("Enter Size Of The Array : \n");
    scanf("%d" , &n);

    printf("Enter K : \n");
    scanf("%d" , &k);

    int arr[n];

    for(int i = 0 ; i < n ; i++){

        printf("Enter Element arr[%d] : " , i);
        scanf("%d" , &arr[i]);

    }

    int maxLen = 0;

    int sum = 0;

    for(int i = 0 ; i < n ; i++){

        int ln = 0;
        sum = 0;

        for(int j = i ; j < n ; j++){
            
            sum += arr[j];
            
            if(sum <= k){
                ln++;
                maxLen = max(maxLen , ln);
            }
            else{
              
                break;
            }
        }
    }   

    printf("maxLen : %d" , maxLen);


}