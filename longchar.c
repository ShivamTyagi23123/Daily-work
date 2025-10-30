#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100] = "/home/shivamtyagi/auto-cpufreq/LICENSE";
    char longest_word[100] = {0};
    char current_word[100];
    int len_longest = 0, len_current = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            if (len_current < 99) {
                current_word[len_current++] = (char)ch;
            }
        } else {
            if (len_current > len_longest) {
                len_longest = len_current;
                for (int i = 0; i < len_current; i++) {
                    longest_word[i] = current_word[i];
                }
                longest_word[len_longest] = '\0';
            }
            len_current = 0;
        }
    }
    if (len_current > len_longest) {
        len_longest = len_current;
        for (int i = 0; i < len_current; i++) {
            longest_word[i] = current_word[i];
        }
        longest_word[len_longest] = '\0';
    }

    printf("Longest word: %s\n", longest_word);

    fclose(file);
    return 0;
}
