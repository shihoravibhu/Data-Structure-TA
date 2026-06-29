#include <stdio.h>

void main()
{

    int n , rev=0 , rem;
    printf("Enter Number : ");
    scanf("%d", &n);    

    while (n!=0)
    {
        rem = n % 10 ;
        rev *= 10 + rem ;
        n /= 10 ;
    }

    printf("Reverse Number : %d" ,rev);


}