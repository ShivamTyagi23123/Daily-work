#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    int sum = 0;
    int num = 0;
    int isnum = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
            isnum = 1;
        } else if (isnum) {
            sum += num;
            num = 0;
            isnum = 0;
        }
    }
    if (isnum) {
        sum += num;
    }
    fclose(file);
    file = fopen(filename, "a");
    printf("\n%d\n", sum);
    fclose(file);
    return 0;
}
