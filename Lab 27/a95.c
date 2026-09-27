// 95. Write a program to implement Quick Sort using Array.

#include <stdio.h>
#include <stdbool.h>

//Algo:
//1. Choose a pivot element from the array.
//2. Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
//3. Recursively apply the above steps to the sub-arrays.


#include <stdio.h>

void quick_sort(int K[], int LB, int UB) {
    
    int I, J, KEY, FLAG;

    if (LB < UB) {
        I = LB;
        J = UB + 1;
        KEY = K[LB];
        FLAG = 1;

        while (FLAG) {
            // Move I right while K[I] < KEY
            I = I+1;
            while (I <= UB && K[I] < KEY){
                I++;
            }

            // Move J left while K[J] > KEY
            J = J-1;
            while (K[J] > KEY){
                J--;
            }

            if (I < J) {
                int temp = K[I];
                K[I] = K[J];
                K[J] = temp;
            } 
            else {
                FLAG = 0;
            }
        }

        // pivot (KEY) ne correct position par
        int temp = K[LB];
        K[LB] = K[J];
        K[J] = temp;

        // Recursive calls
        quick_sort(K, LB, J - 1);
        quick_sort(K, J + 1, UB);
    }
}

void main() {
    int arr[20], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

