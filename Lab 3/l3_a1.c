// 16. Write a program to read and display n numbers using an array. 

#include<stdio.h>

void main(){

    int n ;

    printf("Enter size of Array :");
    scanf("%d" ,&n);

    int a[n];

    for(int i=0 ; i<n ; i++){
        printf("Enter Number : a[%d] : " ,i);
        scanf("%d",&a[i]);
    }
    
    for(int i=0 ; i<n ; i++){
        printf("%d " ,a[i]);
    }

}