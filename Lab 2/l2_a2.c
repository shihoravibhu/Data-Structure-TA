#include <stdio.h>

void main(){

    int n , pow , ans=1;

    printf("Enter Number and power : ");
    scanf("%d %d",&n ,&pow);

    for (int i = 1; i <= pow; i++)
    {
        ans *= n ;
    }
    
    printf("ans : %d" ,ans);

        
}