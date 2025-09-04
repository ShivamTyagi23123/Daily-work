#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("Enter two integers: ");
    scanf("%d %d", &a , &b);
    int c = a % 2;
    int d = b % 2; 
    if (c == 0)
        printf("%d\n", a * 2);
    else
        printf("%d\n", a * 3);

    if (d == 0)
        printf("%d\n", b * 2);
    else
        printf("%d\n", b * 3);

    return 0;
}
