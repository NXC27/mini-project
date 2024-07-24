#include<stdio.h>

int main()
{
    int n;
    do
    {
        printf("Enter a mount of money: ");
        scanf("%d", &n);
    } while (n%10);
    
    int n100;
    int n50;
    int n10;

    //n = 270
    //  n/100 -> n = 2
    //  n%100 -> m = 70
    //  m/50  -> m = 1
    //  m%50  -> k = 20
    //  k/10 -> k = 2
    printf("=== Number of each note ===\n");
    n100 = n/100;
    printf("Number of notes 100: %d\n", n100);
    n50 = (n%100)/50;
    printf("Number of notes 50: %d\n", n50);
    n10 = (n%100)%50/10;
    printf("Number of notes 10: %d\n", n10);
    
    printf("=== Number of each note for each note case ===\n");
    printf("Number of notes 100: %d\n", n/100);
    printf("Number of notes 50: %d\n", n/50);
    printf("Number of notes 10: %d\n", n/10);
    
    return 0;
}