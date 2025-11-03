    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_TRANSACTIONS 100

    typedef struct {
        int id;
        char type[20];
        float amount;
    } Transaction;

    Transaction transactionHistory[MAX_TRANSACTIONS];
    int transactionCount = 0;
    float balance = 0.0;
    int accountOpen = 0;
    int currentAccountNumber = 0;

    void buildFileName(char* filename, const char* prefix, int accountNum) {
        sprintf(filename, "%s_%d.txt", prefix, accountNum);
    }

    void loadDataForAccount(int accountNum) {
        char balanceFile[50], historyFile[50];
        buildFileName(balanceFile, "balance", accountNum);
        buildFileName(historyFile, "history", accountNum);

        FILE *fBalance = fopen(balanceFile, "r");
        if (fBalance != NULL) {
            fscanf(fBalance, "%f", &balance);
            fclose(fBalance);
            accountOpen = 1;
            currentAccountNumber = accountNum;
        } else {
            balance = 0.0;
            accountOpen = 0;
            currentAccountNumber = 0;
        }

        FILE *fHistory = fopen(historyFile, "r");
        if (fHistory != NULL) {
            transactionCount = 0;
            while (fscanf(fHistory, "%d %s %f", &transactionHistory[transactionCount].id, 
                    transactionHistory[transactionCount].type, 
                    &transactionHistory[transactionCount].amount) != EOF && 
                    transactionCount < MAX_TRANSACTIONS) {
                transactionCount++;
            }
            fclose(fHistory);
        } else {
            fprintf(fBalance, "%.2f\n", balance);
            fclose(fBalance);
        }

        FILE *fHistory = fopen(historyFile, "w");
        if (fHistory != NULL) {
            transactionCount = 0;
        }
    }

    void saveDataForAccount(int accountNum) {
        char balanceFile[50], historyFile[50];
        buildFileName(balanceFile, "balance", accountNum);
        buildFileName(historyFile, "history", accountNum);

        FILE *fBalance = fopen(balanceFile, "w");
        if (fBalance != NULL) {
            fprintf(fBalance, "%.2f\n", balance);
            fclose(fBalance);
        }

        FILE *fHistory = fopen(historyFile, "w");
        if (fHistory != NULL) {
            for (int i = 0; i < transactionCount; i++) {
                fprintf(fHistory, "%d %s %.2f\n", transactionHistory[i].id, 
                        transactionHistory[i].type, 
                        transactionHistory[i].amount);
            }
            fclose(fHistory);
        }
    }

    void openAccount() {
        int accNum;
        printf("Enter account number to open: ");
        scanf("%d", &accNum);

        char filename[50];
        buildFileName(filename, "balance", accNum);
        FILE *f = fopen(filename, "r");
        if (f != NULL) {
            fclose(f);
            printf("Account %d already exists.\n", accNum);
            return;
        }

        balance = 0;
        transactionCount = 0;
        accountOpen = 1;
        currentAccountNumber = accNum;
        saveDataForAccount(accNum);
        printf("Account %d opened successfully!\n", accNum);
    }

    void closeAccount() {
        if (!accountOpen) {
            printf("No account loaded to close.\n");
            return;
        }
        int accNum = currentAccountNumber;
        char balanceFile[50], historyFile[50];
        buildFileName(balanceFile, "balance", accNum);
        buildFileName(historyFile, "history", accNum);
        remove(balanceFile);
        remove(historyFile);
        printf("Account %d closed successfully!\n", accNum);
        balance = 0;
        transactionCount = 0;
        accountOpen = 0;
        currentAccountNumber = 0;
    }

    void selectAccount() {
        int accNum;
        printf("Enter account number to load: ");
        scanf("%d", &accNum);
        loadDataForAccount(accNum);
        if (accountOpen) {
            printf("Account %d loaded successfully!\n", accNum);
        } else {
            printf("Account %d not found.\n", accNum);
        }
    }

    void checkBalance() {
        if (!accountOpen) {
            printf("Open an account first.\n");
            return;
        }
        printf("Current Balance: $%.2f\n", balance);
    }

    void depositAmount() {
        if (!accountOpen) {
            printf("Open an account first.\n");
            return;
        }
        float amt;
        printf("Enter amount to deposit: ");
        scanf("%f", &amt);
        if (amt > 0) {
            balance += amt;
            transactionHistory[transactionCount++] = (Transaction){transactionCount+1, "Deposit", amt};
            saveDataForAccount(currentAccountNumber);
            printf("Deposited $%.2f\n", amt);
        } else {
            printf("Invalid amount!\n");
        }
    }

    void withdrawAmount() {
        if (!accountOpen) {
            printf("Open an account first.\n");
            return;
        }
        float amt;
        printf("Enter amount to withdraw: ");
        scanf("%f", &amt);
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            transactionHistory[transactionCount++] = (Transaction){transactionCount+1, "Withdraw", amt};
            saveDataForAccount(currentAccountNumber);
            printf("Withdrawn $%.2f\n", amt);
        } else {
            printf("Invalid amount or insufficient balance.\n");
        }
    }

    void displayTransactionHistory() {
        if (!accountOpen) {
            printf("No account loaded.\n");
            return;
        }
        printf("Transaction History:\n");
        for (int i=0; i<transactionCount; i++) {
            printf("ID: %d, %s: $%.2f\n", transactionHistory[i].id, transactionHistory[i].type, transactionHistory[i].amount);
        }
    }

    void identifyDefaulter() {
        if (!accountOpen) {
            printf("No account loaded.\n");
            return;
        }
        if (balance < 0)
            printf("Account is in default!\n");
        else
            printf("Account is not in default.\n");
    }

    int main() {
        loadDataForAccount(0);
        int choice;
        do {
            printf("\n--- Banking Menu ---\n");
            printf("1. Load Account\n");
            printf("2. Open New Account\n");
            printf("3. Close Current Account\n");
            printf("4. Check Balance\n");
            printf("5. Deposit\n");
            printf("6. Withdraw\n");
            printf("7. Show Transactions\n");
            printf("8. Identify Default\n");
            printf("9. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1: selectAccount(); break;
                case 2: openAccount(); break;
                case 3: closeAccount(); break;
                case 4: checkBalance(); break;
                case 5: depositAmount(); break;
                case 6: withdrawAmount(); break;
                case 7: displayTransactionHistory(); break;
                case 8: identifyDefaulter(); break;
                case 9: printf("Thanks! Exiting...\n"); break;
                default: printf("Invalid choice.\n");
            }
        } while(choice != 9);
        return 0;
    }
