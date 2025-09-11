#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A1[n];
    printf("Enter elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A1[i]);
    }
    printf("Elements in reverse order:\n");
    for(i = n - 1; i >= 0; i--) {
        printf("%d ", A1[i]);
    }
    return 0;
}