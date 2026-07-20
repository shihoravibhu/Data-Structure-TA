// 53. Write a program to perform addition of two polynomial equations
// using Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *link;
};

struct Node *FIRST1 = NULL;
struct Node *FIRST2 = NULL;
struct Node *FIRST3 = NULL;

// Insert At Last in Polynomial 1 Ma
void insertAtLast1(int coeff, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (FIRST1 == NULL)
    {
        FIRST1 = newNode;
        return;
    }

    struct Node *save = FIRST1;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

// Insert At Last in Polynomial 2 Ma
void insertAtLast2(int coeff, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (FIRST2 == NULL)
    {
        FIRST2 = newNode;
        return;
    }

    struct Node *save = FIRST2;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}

// Insert At Last in Je Result Che Te Polynomial
void insertAtLast3(int coeff, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->link = NULL;

    if (FIRST3 == NULL)
    {
        FIRST3 = newNode;
        return;
    }

    struct Node *save = FIRST3;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newNode;
}


void display(struct Node *FIRST)
{
    if (FIRST == NULL)
    {
        printf("Empty Polynomial\n");
        return;
    }

    while (FIRST != NULL)
    {
        printf("%dx^%d", FIRST->coeff, FIRST->power);

        if (FIRST->link != NULL)
        {
            printf(" + ");
        }

        FIRST = FIRST->link;
    }

    printf("\n");
}

// Add
void addPolynomial()
{
    struct Node *save1 = FIRST1;
    struct Node *save2 = FIRST2;

    while (save1 != NULL && save2 != NULL)
    {
        // Same power Hoi Tyare
        if (save1->power == save2->power)
        {
            insertAtLast3(save1->coeff + save2->coeff, save1->power);

            save1 = save1->link;
            save2 = save2->link;
        }

        // Polynomial 1 Na Element Ni Power Moti Hoi Tyare Tyare
        else if (save1->power > save2->power)
        {
            insertAtLast3(save1->coeff, save1->power);

            save1 = save1->link;
        }

        // Polynomial 2 Na Element Ni Power Moti Hoi Tyare Tyare
        else
        {
            insertAtLast3(save2->coeff, save2->power);

            save2 = save2->link;
        }
    }

    // Baki Rahela terms of Polynomial 1 Na 
    while (save1 != NULL)
    {
        insertAtLast3(save1->coeff, save1->power);
        save1 = save1->link;
    }

    // Baki Rahela terms of Polynomial 2 Na 
    while (save2 != NULL)
    {
        insertAtLast3(save2->coeff, save2->power);
        save2 = save2->link;
    }
}

void main()
{
    // Polynomial 1
    // 5x^4 + 3x^2 + 2x + 7

    insertAtLast1(5, 4);
    insertAtLast1(3, 2);
    insertAtLast1(2, 1);
    insertAtLast1(7, 0);

    // Polynomial 2
    // 2x^5 + 6x^2 + 8

    insertAtLast2(2, 5);
    insertAtLast2(6, 2);
    insertAtLast2(8, 0);

    printf("Polynomial 1:\n");
    display(FIRST1);

    printf("Polynomial 2:\n");
    display(FIRST2);

    addPolynomial();

    printf("Result:\n");
    display(FIRST3);

   
}