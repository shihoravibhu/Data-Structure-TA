// 22. WAP to print Pascal triangle.

//    0 1 2 3
//0   1
//1   1 1 
//2   1 2 1
//3   1 3 3 1

#include<stdio.h>

void main(){
    
    int n ;

    printf("Enter Rows:");
    scanf("%d" ,&n);

    int a[n][n];

    for(int i=0 ; i<n ; i++){

        for(int k = n - i ; k > 0 ; k--){
            printf(" ");
        }

        for(int j=0 ; j<=i ;j++){
            
            if(j==0 || j==i){
                a[i][j]=1;
            }
            else{
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            
            printf("%d " , a[i][j]);
        }

        printf("\n");
        
    }
    
    // for(int i=0 ; i<n ; i++){
    //     printf("\n");
    //     for(int j=0 ; j<n-i ; j++){
            
    //         printf(" ");
    //     }
    //     for(int k=0 ; k<=i ;k++){
            
    //         printf("%d ",a[i][k]);
    //     }
    // }

}

// #include<stdio.h>
// int fact(int n);
// int comb(int n, int r);

// int comb(int n, int r) {
//     return (fact(n)/(fact(n-r)*fact(r)));
// }
// int fact(int n) {
//     if(n == 1||n == 0) {
//         return 1;
//     }
//     return n*fact(n-1);
// }

// void main() {
//     int n;
//     printf("enter number of row = ");
//     scanf("%d",&n);

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n-i-1; j++) {
//             printf(" ");
//         }
//         for(int j=0; j<=i; j++) {
//             printf("%d ",comb(i,j));
//         }
//         printf("\n");
//     }
// }