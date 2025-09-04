#include <stdio.h>

int main() {
    int a = 0, b = 1, c , d;
    printf("Enter a number: ");
    scanf("%d", &d);
    if (d == 0 , d == 1) {
        printf("Fibonacci series number\n");
    }
    while (c < d) {
        c = a + b;
        a = b;
        b = c;
    }
    if (c == d) 
        printf("Fibonacci series number\n");
    else
        printf("Not a Fibonacci series number\n");

    return 0;
}
