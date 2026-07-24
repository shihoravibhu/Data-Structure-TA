// 63. Merge Intervals Problem Using 2D Array

#include <stdio.h>

// 2D Array Thi

int stack[100][2];
int top = -1;

void push(int x[])
{
    top++;
    stack[top][0] = x[0];
    stack[top][1] = x[1];
}

void pop()
{
    top--;
}

void sortIntervals(int arr[][2], int n)
{
    int temp1, temp2;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {

                temp1 = arr[j][0];
                temp2 = arr[j][1];

                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];

                arr[j + 1][0] = temp1;
                arr[j + 1][1] = temp2;
            }
        }
    }
}

void mergeIntervals(int arr[][2], int n)
{
    sortIntervals(arr, n);

    push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        // {{1,3},{2,4},{6,8},{9,10}}
        // Overlapping Thai Tyare
        if (arr[i][0] <= stack[top][1])
        {
            if (arr[i][1] > stack[top][1]) // (Ahiya Ek Vastu Jova Made Che K If Overlapping Is Occurring Then We Cannot Push Into Stack We Just Modify It)
            {
                stack[top][1] = arr[i][1];
            }
        }
        // Overlapping Na Hoi Tyare
        else
        {
            push(arr[i]);
        }
    }

    printf("\nMerged Intervals:\n");

    for (int i = 0; i <= top; i++)
    {
        printf("{%d,%d} ", stack[i][0], stack[i][1]);
    }
}

int main()
{
    int n;

    printf("Enter Number Of Intervals : ");
    scanf("%d", &n);

    int arr[n][2];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Start And End Of Interval %d : ", i + 1);
        scanf("%d%d", &arr[i][0], &arr[i][1]);
    }

    mergeIntervals(arr, n);

    return 0;
}