// 57. Write a menu driven program to implement following operations on the Stack
// using an Array
// • PUSH, POP, DISPLAY
// • PEEP, CHANGE

#include <stdio.h>

int stack[100];
int size = 100;
int top = -1;

void push(int n)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = n;
    printf("Pushed %d\n", n);
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return -1;
    }

    return stack[top--];
    // printf("Popped element is: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return ;
    }
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

void peep(int idx) // idx means top thi ketlamo element
{
    if(idx <= 0 || top - idx + 1 < 0)
    {
        printf("Invalid index. Stack Underflow.\n");
        return;
    }
    printf("Peep %dth Element from Top is: %d\n", idx, stack[top - idx + 1]);
}

void change(int idx, int n)
{
    if(idx <= 0 || top - idx + 1 < 0)
    {
        printf("Invalid index. Stack Underflow.\n");
        return;
    }
    stack[top - idx + 1] = n;
    printf("Changed %dth element from Top to %d\n", idx, n);
}

void main()
{
    int choice, n, i, val;

    while (1)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n5.PEEP\n6.CHANGE\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &n);
            push(n);
            break;

        case 2:
            n = pop();
            if (n != -1)
                printf("Popped element is: %d\n", n);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program.\n");
            return ;

        case 5:
            printf("Enter ith element from top: ");
            scanf("%d", &i);
            peep(i);
            break;

        case 6:
            printf("Enter ith element from top and new value: ");
            scanf("%d %d", &i, &val);
            change(i, val);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }
}
