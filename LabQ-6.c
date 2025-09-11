#include <stdio.h>
#define MAX 100

int main() 
{
    int arr[MAX], freq[MAX];
    int n, i, j, count;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }
    printf("Duplicate elements and their counts:\n");
    for (i = 0; i < n; i++) {
        if (freq[i] > 1) {
            printf("occurs times\n", arr[i], freq[i]);
        }
    }
    return 0;
}