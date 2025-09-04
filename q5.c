#include <stdio.h>
int main() {
    int v1 = 0, v2 = 0, v3 = 0;
    char choice;
    int a = 1;
    printf("Voting System\n");
    printf("Candidates:\n"); 
    printf("Enter 1, 2, or 3 to vote for the respective candidate.\n");
    while (a) {
        printf("Your vote (1/2/3 or n to stop): ");
        scanf(" %c", &choice);
        if (choice == '1')
            v1++;
        else if (choice == '2')
            v2++;
        else if (choice == '3')
            v3++;
        else if (choice == 'n', choice == 'N')
            a = 0;
        else
            printf("Invalid input. Try again.\n");
    }
    printf("\nVoting Results:\n");
    printf("shivam:%d votes\n", v1);
    printf("Jay:%d votes\n", v2);
    printf("Paras:%d votes\n", v3);
    return 0;
}
