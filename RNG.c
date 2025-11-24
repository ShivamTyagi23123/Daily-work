#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c;

    srand(time(NULL)); 
    a = rand() % 9 + 1;
    b = rand() % 9 + 1;
    c = rand() % 9 + 1;

    printf("Numbers: %d %d %d\n", a, b, c);

    if (a == b && b == c) {
        printf("1st prize\n");
    } else if (a == b || b == c || a == c) {
        printf("2nd prize\n");
    } else {
        printf("Try again\n");
    }

    return 0;
}
