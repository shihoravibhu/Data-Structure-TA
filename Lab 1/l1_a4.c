#include <stdio.h>

void main(){

    int a,b,c,ans ;

    printf("Enter Three Number : ");
    scanf("%d %d %d",&a,&b,&c);

   ans = (a>b)?((a>c)?(a):(c)):((b>c)?(b):(c));

   printf("Largest Number : %d" ,ans);


}