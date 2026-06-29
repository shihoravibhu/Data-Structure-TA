// 23. WAP to sort the N names in an alphabetical order.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{

   int n;
   printf("Enter n :");
   scanf("%d", &n);

   char arr[n][100];

   for (int i = 0; i < n; i++)
   {
      printf("Enter %d :",i);
      scanf("%s", arr[i]);
   }

   for (int i = 0; i < n - 1; i++)
   {
      for (int j = i+1; j < n; j++)
      {
         if (strcmp(arr[i], arr[j]) > 0)
         {
            char temp[50];

            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);

         }
      }
   }
   for (int i = 0; i < n; i++)
   {
      printf("%s\n", arr[i]);
   }
}