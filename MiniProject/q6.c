#include<stdio.h>

int main()
{
    int n;
    float fine = 0;
    printf("Enter your day late: ");
    scanf("%d", &n);
    if (n>30)
    {
        printf("Your membership will be canceled\n");
        return 0;
    }
    else
    {
        switch(n)
        {
            case 1 ... 5:
                fine += (n*0.5);
                printf("%f\n", fine);
                break;
            case 6 ... 10:
                fine = 0.5*5 + 1*(n-5);
                printf("%f\n", fine);
                break;
            case 11 ... 30:
                fine = 0.5*5 + 1*5 + 5*(n-10);
                printf("%f\n", fine);
                break;
            default:
                printf("Enter a valid positive nmumber\n");
                break;
        }
        return 0;
    }
}