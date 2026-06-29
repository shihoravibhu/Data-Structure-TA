#include <stdio.h>

// recursion

int factorial(int n){

    if(n==0){
        return 1 ;
    }

    
    return n*factorial(n-1);
    
}

// Using loop 

void main(){

    int n , fac=1; 
    printf("Enter Number : ");
    scanf("%d",&n);

    // while(n != 0){
    //     fac *= n ;
    //     n-- ;
    // }

    // printf("Factorial : %d" , fac);



    // recursion
    printf("\nFactorial %d",factorial(n));

}
