// 18. Write a program to calculate average of first n numbers

#include<stdio.h>

void main(){

    int n = 1 , m;

    printf("Enter number :");
    scanf("%d",&m);

    int a[m];

    for(int i=0 ; i<m ; i++){
        a[i]=n++;
    }

    int sum = 0 ;
    
    for(int i=0 ; i<m ; i++){
        sum+=a[i];
    }

    printf("%f",sum/m);





}