#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int count = 0, num;
    int sum = 0, even = 0, odd = 0, pos = 0, neg = 0;

    printf("Enter numbers (-999 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -999) break;

        int *temp = realloc(arr, (count + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Memory error\n");
            free(arr);
            return 1;
        }
        arr = temp;
        arr[count++] = num;

        sum += num;
        if (num % 2 == 0) even++; else odd++;
        if (num >= 0) pos++; else neg++;
    }

    printf("Sum = %d\n", sum);
    printf("Even = %d, Odd = %d\n", even, odd);
    printf("Positive = %d, Negative = %d\n", pos, neg);

    printf("Reverse: ");
    for (int i = count - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Alternate even and odd: ");
    int i = 0, j = 0;
    while (i < count || j < count) {
        while (i < count && arr[i] % 2 != 0) i++;
        if (i < count) printf("%d ", arr[i++]);
        while (j < count && arr[j] % 2 == 0) j++;
        if (j < count) printf("%d ", arr[j++]);
    }
    printf("\n");

    free(arr);
    return 0;
}
