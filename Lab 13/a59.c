// 59. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.

#include <stdio.h>

char stack[100];
int size = 100;
int top = -1;

void push(char ch)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = ch;
    // printf("Pushed %c\n", ch);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }
    top--;
    // printf("Popped element is: %c\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

void validString(char str[])
{

    int i = 0;

    // Push characters Jyasudhi 'c' is found Or String Puri Na Thai Tya Sidhi
    while (str[i] != '\0' && str[i] != 'c')
    {
        push(str[i]);
        i++;
    }

    if (str[i] != 'c')  // Aa Kyare Execute Thase ? Jyare String Ma c Hoi J Nai Tyare And Eni Peli Je While Loop Che Tya J String Puri Thai Gai Hoi Tyare
    { 
        printf("Its Not Valid String.");
        return;
    }

    i++;   // Skip c

    while (str[i] != '\0' && top != -1)
    {
        // Ahiya top == -1 Kariyu Che Karne String Puri Thata Pela J Stack Empty Thai Jai Tyare
        
        if (str[i] != stack[top]){  // Jovanu K Stack Rahel Char Ane Je String Ma Che Te Char Ee Jo Match Na Thata Hoi To Not Valid
            printf("Its Not Valid String.\n");
            return;
        }

        pop();
        i++;
    }

    if (top == -1 && str[i] == '\0')   // Check Karo K Stack Empty Thai Gyo Che Ne 
    {
        printf("Its Valid Valid String. %s", str);
    }
    else      
    {
        printf("its Not Valid String.");
    }
}

void main()
{

    char str[100];

    printf("Enter String.\n");
    scanf("%s", str);

    validString(str);
}