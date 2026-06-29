// 17. Write a program to calculate sum of numbers from m to n. 

#include <stdio.h>

void main()
{

    int m, n, sum = 0;

    int temp;

    printf("Enter m Starting Point :");
    scanf("%d", &m);
    temp = m;

    printf("Enter n Ending Point :");
    scanf("%d", &n);

    int a[n - m + 1];

    int size = sizeof(a) / sizeof(int);
    
    // or
    // int size = (n - temp + 1);

    for (int i = 0; i < size; i++)
    {

        a[i] = m;

        m++;
    }

    for (int j = 0; j < size; j++)
    {

        sum += a[j];
    }

    printf("sum : %d", sum);
}