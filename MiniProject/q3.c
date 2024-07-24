#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[30];
    int score;
} Student;
Student *add_student(Student *old_ptr, int *new_size)
{
    ++*new_size;
    Student *ptr_new = (Student *)realloc(old_ptr, *new_size*sizeof(Student)); 
    return ptr_new;
}
void update_student(Student *ptr, int size)
{
    char ch[30];
    printf("Enter student's name: ");
    scanf("%s", ch);
    for (int i=0; i<size; i++)
    {
        if (strcmp((ptr+i)->name, ch)==0)
        {
            printf("Enter new student's score: ");
            scanf("%d", &(ptr+i)->score);
            return;
        }
    }
    printf("Could not find out that student\n");
}
Student *delete_student(Student *ptr, int *size)
{
    char ch[30];
    printf("Enter student's name: ");
    scanf("%s", ch);
    for (int i=0; i<*size; i++)
    {
        if (strcmp((ptr+i)->name, ch)==0)
        {
            printf("Found out\n");
            for (int j=i; j<*size; j++)
            {
                *(ptr+j) = *(ptr+j+1);
            }
            --*size;
            Student *ptr_new = (Student *)realloc(ptr, *size*sizeof(Student)); 
            return ptr_new;
        }
    }
    printf("Could not find out that student\n");
}
int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    
    Student *ptr_s = (Student*) malloc (n*sizeof(Student));
    //import Student
    for (int i=0; i<n; i++)
    {
        printf("Enter student's name: ");
        scanf("%s", (ptr_s+i)->name);
        printf("Enter student's score: ");
        scanf("%d", &(ptr_s+i)->score);
    }
    //display
    for (int i=0; i<n; i++)
    {
        printf("======================================\n");
        printf("Student's name: %s\n", (ptr_s+i)->name);
        printf("Student's score: %d\n", (ptr_s+i)->score);
        printf("\n");
    }
    //add new Student
    Student *new_ptr_s;
    ptr_s = add_student(ptr_s, &n);
    printf("Enter new student's name: ");
    scanf("%s", (ptr_s+n-1)->name);
    printf("Enter new student's score: ");
    scanf("%d", &(ptr_s+n-1)->score);
    //display all student after added
    for (int i=0; i<n; i++)
    {
        printf("======================================\n");
        printf("Student's name: %s\n", (ptr_s+i)->name);
        printf("Student's score: %d\n", (ptr_s+i)->score);
        printf("\n");
    }
    //update student
    update_student(ptr_s, n);
    //display all student after updated
    for (int i=0; i<n; i++)
    {
        printf("======================================\n");
        printf("Student's name: %s\n", (ptr_s+i)->name);
        printf("Student's score: %d\n", (ptr_s+i)->score);
        printf("\n");
    }
    //delete student
    ptr_s = delete_student(ptr_s, &n);
    //display all student after deleted
    for (int i=0; i<n; i++)
    {
        printf("======================================\n");
        printf("Student's name: %s\n", (ptr_s+i)->name);
        printf("Student's score: %d\n", (ptr_s+i)->score);
        printf("\n");
    }
    free(ptr_s);
    return 0;
}