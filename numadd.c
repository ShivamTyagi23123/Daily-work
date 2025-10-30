#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    int sum = 0;
    int num;
    while (fscanf(file, "%d", &num) == 1) {
        sum += num;
    }
    fclose(file);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    fprintf(file, "\n%d\n", sum);
    fclose(file);
    return 0;
}
