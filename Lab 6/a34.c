// 34. WAP to allocate and de-allocate memory for int, char and float variable at runtime.

#include<stdio.h>
#include<stdlib.h>

void main(){

    int *a = (int *) malloc(sizeof(int));
    char *b = (char *) malloc(sizeof(char));
    float *c = (float *) malloc(sizeof(float));

    if(a && b && c){
        *a = 77 ;
        *b = 'v';
        *c = 1.77;

        printf("%d\n",*a);
        printf("%c\n",*b);
        printf("%.2f\n",*c);

        free(a);
        free(b);
        free(c);
    }
    else{
        printf("Memory Allocation Failed\n");
    }
}