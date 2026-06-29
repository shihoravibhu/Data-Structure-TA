#include <stdio.h>

void main(){

    int days , week , y;

    printf("Enter days : ");
    scanf("%d",&days);
    
    y = days / 365 ; 
    days = days - (y*365) ;
    
    week = days / 7 ;
    days = days - (week*7) ;
    
    printf("Enter y:week:days = %d %d %d",y , week , days);
    
    

}