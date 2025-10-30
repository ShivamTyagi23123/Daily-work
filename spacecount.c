#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') {
            count++;
        }
    }
    printf("Number of spaces: %d\n", count);
    fclose(file);
    return 0;
}
