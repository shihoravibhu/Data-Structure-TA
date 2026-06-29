#include <stdio.h>

void main(){

    char ch ;

    printf("Enter charter : ");
    scanf("%c" ,&ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            printf("Charter %c is vowel",ch);
        }

        else{
            
            printf("Charter %c is not vowel",ch);
        }
}