#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    return 0;
}
