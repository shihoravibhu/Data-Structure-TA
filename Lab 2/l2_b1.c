#include <stdio.h>
#include <math.h>

void main()
{
    int st, en;
    printf("Enter starting and ending point : ");
    scanf("%d %d", &st, &en);

    for (int j = st + 1; j < en; j++)
    {

        int flag = 0;

        for (int i = 2; i <= sqrt(j); i++)
        {
            if (j % i == 0)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {

            printf("%d is prime Number.\n", j);
        }
    }
}