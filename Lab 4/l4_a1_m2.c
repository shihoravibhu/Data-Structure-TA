// 24. Write a program to insert a number at a given location in an array. 

#include <stdio.h>

void main()
{

    int arr[6];

    for(int i = 0 ; i < 5 ; i++){
        printf("Enter At arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    int idx , num;

    printf("\nidx : ");
    scanf("%d" , &idx);
    
    printf("\nnum : ");
    scanf("%d" , &num);

    for(int i = idx ; i < 5 ; i++){

        int temp = arr[i];
        arr[i] = num;
        num = temp;
    }

    arr[5] = num;

    for(int i=0 ; i<6 ; i++){
        printf("%d ",arr[i]);
    }

}