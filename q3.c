#include <stdio.h>

int main() {
    int i, j;
    printf("Prime numbers from 1 to 20:\n");
    for (i = 2; i <= 20; i++) {
        int prime = 1;
        for (j = 2; j < i;j++) {
            if (i % j == 0) {
                prime = 0;
            }
        }
        if (prime)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

