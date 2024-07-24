/*
Develop a string manipulation toolkit in C that includes functions such as string concatenation, substring extraction, and palindrome checking. Utilize pointers for efficient string manipulation and implement a menu-driven interface for user interaction. (Note: Do not use any string library function)
*/
#include<stdio.h>
int len(char *ptr)
{
    int count = 0;
    while((*ptr) != '\0')
    {
        ++count;
        ptr++;
    }
    return count;
}
void concatenate(char *pd, char *ps)
{
    int len_pd = len(pd);
    int i;
    for (i=0; i<len(ps); i++)
    {
        *(pd+i+len_pd) = *(ps+i);
    }
    *(pd+len_pd+i) = '\0';
}
//string =          nguyen123
//begin = 3 = y
//distance = 3

//ptr = 0 = n
//=>ptr += str_begin => ptr = 3
//result =      yen
void substring(char *pd, char *ps, int str_begin, int distance)
{
    ps += str_begin;
    int i;
    for (i=0; i<distance; i++)
    {
        *(pd+i) = *(ps+i);
    }
    *(pd+i) = '\0';
}
//012345
//abcba\0
//abccba
int is_palindrome(char *ptr)
{
    int i = 0;
    int n = len(ptr);
    for (int i=0; i<n/2; i++)
    {
        if (*(ptr+i) == *(ptr+n-1-i))
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char str_s[30] = "";
    char str_d[30] = "";
    int start_number;
    int distance;
    int choice;
    while(1)
    {
        printf("^^^^ MENU ^^^^\n");
        printf("1.Concatenation\n");
        printf("2.Substring\n");
        printf("3.Check Palindrome\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter source string: ");
                scanf("%s", str_s);
                printf("Enter destination string: ");
                scanf("%s", str_d);
                concatenate(str_d, str_s);
                printf("After Concatenated: ");
                printf("%s\n",str_d);
                break;
            case 2:
                printf("Enter source string: ");
                scanf("%s", str_s);
                printf("Enter the start number: ");
                scanf("%d", &start_number);
                printf("Enter the distance: ");
                scanf("%d", &distance);
                substring(str_d, str_s, start_number, distance);
                printf("After Substring: ");
                printf("%s\n",str_d);
                break;
            case 3:
                printf("Enter a string: ");
                scanf("%s", str_s);
                if (is_palindrome(str_s))
                {
                    printf("The given string is Palindrome\n");
                }
                else
                {
                    printf("The given string is Palindrome\n");
                }
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Please enter a valid number\n");
                break;
        }
    }
}