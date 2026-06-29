#include <stdio.h>

void main(){

    int y;

    printf("Enter Year : ");
    scanf("%d",&y);

    if(y % 100 !=0 && y % 4 == 0 || y % 400 == 0){
        printf("Year is Leap Year : %d",y);       
    }
    
    else{       
        printf("Year is not Leap Year : %d",y);
    }
}