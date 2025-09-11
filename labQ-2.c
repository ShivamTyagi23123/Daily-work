#include <stdio.h>

int main() {
    int A1[16], A2[16];
    printf("Enter numbers for A1:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &A1[i]);
    }
    for(int i = 0; i < 5; i++) {
        A2[i] = A1[i];
    }
    printf("A2: ");
    for(int i = 0; i < 5; i++) {
        printf("%d", A2[i]);
    }
    return 0;
}
