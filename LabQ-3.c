#include <stdio.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int A1[n];
    printf("Enter elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A1[i]);
    }
    printf("Unique elements are: ");
    for(int i = 0; i < n; i++) {
        int Unique = 1;
        for(int j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                Unique = 0;
                break;
            }
        }
        if(isUnique) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
