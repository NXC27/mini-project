#include<stdio.h>
#include<string.h>

typedef struct
{
    int id;
    char name[30];
    float monthly_salary;
    float yearly_salary;
} Employee;
float calc_yearly_salary(float monthly_salary)
{
    return monthly_salary*12;
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    Employee e[n];
    char ch[30];
    
    for (int i=0; i<n; i++)
    {
        printf("### Enter Employee Infomation ###\n");
        printf("Enter ID: ");
        scanf("%d", &e[i].id);
        printf("Enter name: ");
        scanf("%s", ch);
        strcpy(e[i].name, ch);
        printf("Monthly Salary: ");
        scanf("%f",&e[i].monthly_salary);
        e[i].yearly_salary = calc_yearly_salary(e[i].monthly_salary);
        printf("\n");
    }
    printf("=== === All Employee's Details === ===\n");
    for (int i=0; i<n; i++)
    {
        printf("Employee number %d:\n", i+1);
        printf("ID: %d\n", e[i].id);
        printf("Name: %s\n", e[i].name);
        printf("Monthly Salary: %f\n", e[i].monthly_salary);
        printf("Yearly Salary: %f\n", e[i].yearly_salary);
        printf("\n");
    }
    return 0;
}