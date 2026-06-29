// 40. WAP to define a C structure named Student (roll_no, name, branch and
// batch_no) and also to access the structure members using Pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{

    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

void main()
{

    struct Student s1;

    struct Student *ptr = &s1;

    // (*ptr).roll_no == ptr->roll_no       This Both Are Same 
    
    printf("Enter s1 RollNumber : \n");
    scanf("%d", &ptr->roll_no);

    printf("Enter s1 Name : \n");
    scanf("%s", ptr->name);

    printf("Enter s1 Branch : \n");
    scanf("%s", ptr->branch);

    printf("Enter s1 BatchNo : \n\n");
    scanf("%d", &ptr->batch_no);

    printf("Entered Detail : \n");


    printf("RollNumber : %d\nName : %s\nBranch : %s\nBatchNo : %d", ptr->roll_no, ptr->name, ptr->branch, ptr->batch_no);
}