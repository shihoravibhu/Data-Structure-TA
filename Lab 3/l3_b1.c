// 20. Write a program to find whether the array contains a duplicate number or not. 

#include<stdio.h>

void main(){

   int n , duplicate = 0;

    printf("Enter size of Array :");
    scanf("%d" ,&n);

    int a[n];

    for(int i=0 ; i<n ; i++){
        printf("Enter Number : a[%d] : " ,i);
        scanf("%d",&a[i]);
    }

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(a[i]==a[j]){
                duplicate = 1 ;
                break;
            }
        }
    }

    if(duplicate==1){
        printf("Yes Conatins Duplicate");
    }
    else{
        printf("Not Conatins Duplicate");

    }
}