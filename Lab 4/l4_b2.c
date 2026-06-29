// 28. Write a program to delete duplicate numbers from an array. 

#include <stdio.h>

void main()
{

    int a[5] , n=5;

    for (int i = 0; i < n; i++)
    {

        printf("Enter Element a[%d] :", i);
        scanf("%d", &a[i]);
    }

    
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (a[i] == a[j])
            {
                for(int k=j ; k<n-1 ; k++){
                    a[k] = a[k+1];
                }
                n--;
                j--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}