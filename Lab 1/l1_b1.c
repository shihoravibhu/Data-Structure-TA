#include <stdio.h>

void main(){

    int s , min , h;

    printf("Enter seconds : ");
    scanf("%d",&s);
    
    h = s / 3600 ; 
    s = s - (h*3600) ;
    
    min = s / 60 ;
    s = s - (min*60) ;
    
    printf("Enter h:min:s = %d %d %d",h,min,s);
    
    

}