// 31.Read two 2x2 matrices and perform addition of matrices into third matrix and print it 

#include<stdio.h>

void main(){

    int a[2][2];
    int b[2][2];
    int c[2][2];

    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            printf("Enter Element a[%d][%d] :",i,j);
            scanf("%d" , &a[i][j]);
        }
    }

    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            printf("Enter Element b[%d][%d] :",i,j);
            scanf("%d" , &b[i][j]);
        }
    }
    
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            c[i][j] = a[i][j] + b[i][j] ;
        }
    }
    
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            
            printf("Enter Element c[%d][%d] = %d:",i,j,c[i][j]);
        }
        printf("\n");
    }


}