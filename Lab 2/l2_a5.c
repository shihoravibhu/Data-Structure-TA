#include <stdio.h>
// #include <math.h>

void main()
{

    int n , flag = 0;
    printf("Enter Number : ");
    scanf("%d", &n);

    for(int i=2 ; i<=sqrt(n); i++){

        if(n % i == 0){

            printf("%d is not prime Number.",n);
            return;

        }

    }
  
    printf("%d is prime Number.",n);        
    
}