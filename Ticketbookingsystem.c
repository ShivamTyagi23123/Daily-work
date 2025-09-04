#include <stdio.h>

int main() {
    int a, b, c, more = 1;
    int totalTickets = 0;
    float totalCost = 0;

    printf("Welcome to the Cinema Ticket Booking System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Premium seat -> 200rs\n");
        printf("2. Standard seat -> 150rs\n");
        printf("3. Economy seat -> 100rs\n");
        printf("4. Exit\n");
        printf("Enter Seat type (1-4): ");
        scanf("%d", &a);

        if (a == 4) {
            break;
        }

        if (a != 1 && a != 2 && a != 3) {
            printf("Invalid seat type. Please try again.\n");
            continue;
        }

        printf("Enter number of seats: ");
        scanf("%d", &b);

        if (a == 1) {
            c = b * 200;
        } else if (a == 2) {
            c = b * 150;
        } else if (a == 3) {
            c = b * 100;
        }

        totalCost += c;
        totalTickets += b;

        printf("Subtotal so far: %.2f Rs for %d tickets.\n", totalCost, totalTickets);

        printf("Do you want to add more tickets? (1 for Yes / 0 for No): ");
        scanf("%d", &more);

        if (!more) {
            break;
        }
    }

    if (totalTickets >= 5) {
        totalCost = totalCost * 0.95;
        printf("\nCongratulations! You received a 5%% discount.\n");
    }

    printf("\nTotal tickets booked: %d\n", totalTickets);
    printf("Total cost: %.2f Rs\n", totalCost);
    printf("Thank you for booking!\n");
    return 0;
}
