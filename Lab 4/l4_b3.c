// 29. Write a program to merge two unsorted arrays.

#include <stdio.h>

void main(){

    int n ;

    printf("Enter size of array : ");
    scanf("%d",&n);

    int a[n] , b[n] , c[2*n];

    for(int i=0 ; i<n ; i++){
        printf("Enter element a[%d] : ",i);
        scanf("%d" , &a[i]);
    }

    for(int i=0 ; i<n ; i++){
        printf("Enter element b[%d] : ",i);
        scanf("%d" , &b[i]);
    }

    for(int i=0 ; i<n ; i++){
        c[i]=a[i];
    }

    int j=0 ;
    for(int i=n ; i<2*n ; i++){
        c[i]=b[j];
        j++;
    }

    for(int i=0 ; i<2*n ;i++){
        printf("%d " , c[i]);
    }
    
}