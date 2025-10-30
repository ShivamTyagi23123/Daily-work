#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    char longest_word[100];
    longest_word[0] = '\0';
    char word[100];
    while (fscanf(file, "%s", word) == 1) {
        if (strlen(word) > strlen(longest_word)) {
            strcpy(longest_word, word);
        }
    }
    printf("Longest word: %s\n", longest_word);
    fclose(file);
    return 0;
}