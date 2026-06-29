// 35. WAP to get and print the array elements using Pointer. 

#include<stdio.h>
#include<stdlib.h>

void main(){
    
    int n;
    printf("Enter Size of Array : ");
    scanf("%d",&n);

    int *arr = (int *) malloc(n * sizeof(int));

    if(arr == NULL){

        printf("Mamory Allocation Failed\n");

    }

    else{

        printf("Enter Elements : \n");
        for(int i=0 ; i<n ; i++){
            printf("Enter Element arr[%d] :",i);
            scanf("%d",&arr[i]);
            //or
            scanf("%d",&*(arr + i));
            //or
            scanf("%d",(arr + i));
        }

        for(int i=0 ; i<n ; i++){
            printf("arr[%d] :%d \n",i,arr[i]);
            // or
            printf("%d\n", i[arr]);
            // or
            printf("%d\n", *(arr + i));
            
        }
        free(arr);
    }
}
