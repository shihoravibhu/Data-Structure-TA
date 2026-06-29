// 24. Write a program to insert a number at a given location in an array. 

#include<stdio.h>

void main(){

    int a[5],b[6];

    for(int i=0 ; i<5 ; i++){

        printf("Enter Element a[%d] :",i);
        scanf("%d",&a[i]);
    }

    int idx,n;
    printf("Enter Location Index : ");
    scanf("%d",&idx);

    if(idx>0 && idx<5){
        printf("Enter Element : ");
        scanf("%d",&n);

        int j=0;
        for(int i=0 ; i<6 ; i++){            
            
            if(i==idx){
                b[i]=n;                
            }
            else{
                b[i]=a[j++];
            }
        }
    }
    else{
        printf("Enter Valid Index");
    }
    
    for(int i=0 ; i<6 ; i++){
        printf("%d ",b[i]);
    }


}