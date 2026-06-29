// Armstrong number 153 = 1^3 + 5^3 + 3^3 == 153 between 1 to 1000
#include <stdio.h>
// #include <math.h>

void main()
{

    int n;

    for (int i = 2; i < 1000; i++)
    {

        int digits = 0, sum = 0, rem = 0 , temp;

        n = i;

        while (n != 0)
        {
            digits++;
            n /= 10;
        }

        temp = i;

        while (temp != 0)
        {
            rem = temp % 10;
            int power = 1;
            // sum += pow(rem,digits);

            for(int j = 1; j <= digits; j++)
            {
                power *= rem;
            }

            sum += power;

            temp /= 10;
        }

        if (sum == i)
        {
            printf("%d is Armstrong Number.\n", i);
        }
    }
}