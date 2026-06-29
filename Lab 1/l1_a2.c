#include <stdio.h>

void main(){

    int n ;

    printf("Enter Number : ");
    scanf("%d" , &n);

    if(n % 2 == 0){
        printf("Number is even %d",n);
    }
    else{        
        printf("Number is odd %d",n);
    }
}