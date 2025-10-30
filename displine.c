#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    char line[250];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    return 0;
}
