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
    int char_count = 0;
    int word_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        char_count++;
        if (ch == ' ' || ch == '\n') {
            word_count++;
        }
    }
    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    fclose(file);
    return 0;
}
