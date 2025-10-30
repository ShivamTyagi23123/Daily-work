#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    long size = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        size++;
    }
    if (size == 0) {
        printf("The file is empty.\n");
    } else {
        printf("The file contains some text.\n");
    }
    fclose(file);
    return 0;
}
