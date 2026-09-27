// 89. Write a program to implement a Linear Search using Array. 

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool linearSearch(int arr[],int size){

    int n;
    printf("Enter Search Element : ");
    scanf("%d" , &n);

    for(int i=0 ; i<size ; i++){
        if(arr[i] == n){
            return true;
        }
    }

    return false;
}

void main(){
    int arr[] = {1,2,3,4,5};

    if(linearSearch(arr,5)){
        printf("Available In Array");
    }
    else{
        
        printf("Not Available In Array");
    }
}