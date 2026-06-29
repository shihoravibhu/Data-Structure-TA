// 26. Write a program to insert a number in an array that is already sorted in an 
// ascending order.

#include <stdio.h>

void main()
{

    int a[6];

    for (int i = 0; i < 5; i++)
    {

        printf("Enter Element a[%d] :", i);
        scanf("%d", &a[i]);
    }

    int n, temp = 0;

    printf("Enter Element : ");
    scanf("%d", &n);

    // int idx = 0;

    // for(int i=0 ; i<5 ; i++){

    //     if(a[i] > n){
    //         idx = i ;
    //         break;
    //     }
    // }

    // for(int i=0 ; i<6 ; i++){

    //     if(i >= idx){
    //         int temp = a[i];
    //         a[i] = n;
    //         n = temp;
    //     }

    // }


    // OR


    for (int i = 0; i < 5; i++)
    {

        if (a[i] > n)
        {
            temp = a[i];
            a[i] = n;
            n = temp;
        }
    }
    
    a[5] = n;

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }


    // char ch[10] ;
    // scanf("%s",&ch);
    // printf("%s",ch);
}