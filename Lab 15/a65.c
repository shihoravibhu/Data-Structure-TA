// 65. Write a program to convert infix notation to postfix notation using stack.

#include<stdio.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

int input_Precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '^'){
        return 6;
    }
    else if(ch == '('){
        return 9;
    }
    else if(ch == ')'){
        return 0;
    }
    else{
        return 7;
    }
}

int stack_Precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 2;
    }
    else if(ch == '*' || ch == '/'){
        return 4;
    }
    else if(ch == '^'){
        return 5;
    }
    else if(ch == '('){
        return 0;
    }    
    else{
        return 8;
    }
}

int r(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
        return -1;
    }
    else{
        return 1;
    }
}

void revPol(char infix[]){
    
    int i = 0;
    int j = 0;
    int rank = 0;
    char postfix[100];
    push('(');

    while(i != strlen(infix)){
        
        char next = infix[i];

        if(top < 0){ 
            printf("Invalid Expression.");
            return;
        }

        while(stack_Precedence(stack[top]) > input_Precedence(next)){
            
            char temp = pop();
            postfix[j++] = temp;

            rank += r(temp);

            if(rank < 1){
                printf("Invalid Expression.");
                return;
            }
        }
        
        if(stack_Precedence(stack[top]) != input_Precedence(next)){
            push(next);
        }
        else{
            char temp = pop();
        }

        i++;
    }

    postfix[j] = '\0';

    if(rank != 1 || top != -1){
        printf("Invalid Expression.");
    }
    else{
        printf("%s" , postfix);
    }
}

void main(){
    char infix[100];

    printf("Enter Infix String : ");
    scanf("%s",infix);

    strcat(infix,")");

    revPol(infix);

}