// 30. WAP to replace lowercase characters by uppercase & vice-versa in a user 
// specified string. 

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){

    char str[10];

    printf("Enter String : ");
    scanf("%s",str);
    // scanf("%[^\n]",str);

    for(int i=0 ; i<strlen(str) ; i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }

    printf("%s",str);

}