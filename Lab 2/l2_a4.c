#include <stdio.h>

void main()
{

    int n ;
    printf("Enter Number : ");
    scanf("%d", &n);

    for(int i=1 ; i<=n ; i++){
        if(n % i == 0){
            printf("Factors : %d\n",i);
        }
    }
}