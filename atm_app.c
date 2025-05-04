#include <stdio.h>

#define reset "\x1B[0m"
#define red "\x1B[31m"
#define green "\x1B[32m"
#define cyan "\x1B[36m"
#define yellow "\x1B[33m"

int main() {
    int pin = 2346;
    int user_pin = 0;
    int choice = 0;
    int attempts = 3;
    int deposit = 0, withdraw = 0;
    int balance = 1000000; // Starting balance

    printf(cyan "\n******** WELCOME TO THE ATM ********\n" reset);
    printf("------------------------------------------------------\n");

    while (attempts > 0) {
        printf("\nPlease enter your 4-digit PIN: ");
        scanf("%d", &user_pin);

        if (user_pin == pin) {
            printf(green "\nACCESS GRANTED!\n" reset);

            do {
                printf(yellow "\nAvailable Transactions:\n" reset);
                printf("1. Check Balance\n");
                printf("2. Deposit Amount\n");
                printf("3. Withdraw Amount\n");
                printf("4. Quit Application\n");

                printf("\nPlease select an option (1-4): ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf(cyan "\nYour current balance is: %d\n" reset, balance);
                        break;

                    case 2:
                        printf("\nEnter the amount you want to deposit: ");
                        scanf("%d", &deposit);
                        if (deposit <= 0) {
                            printf(red "\nInvalid deposit amount. Please try again.\n" reset);
                        } else {
                            balance += deposit;
                            printf(green "\nDeposit successful! New balance: %d\n" reset, balance);
                        }
                        break;

                    case 3:
                        printf("\nEnter the amount you want to withdraw: ");
                        scanf("%d", &withdraw);
                        if (withdraw <= 0 || withdraw > balance) {
                            printf(red "\nInvalid withdrawal amount. Please try again.\n" reset);
                        } else {
                            balance -= withdraw;
                            printf(green "\nWithdrawal successful! New balance: %d\n" reset, balance);
                        }
                        break;

                    case 4:
                        printf(green "\nThe application will close now.\n" reset);
                        printf(cyan "\nTHANK YOU FOR YOUR TIME!\n" reset);
                        printf(yellow "\nHOPE TO SEE YOU AGAIN! GOODBYE.\n" reset);
                        return 0; // Exit the program

                    default:
                        printf(red "\nInvalid option selected. Please try again.\n" reset);
                }
                printf(cyan "\n------------------------------------------------------\n" reset);
            } while (choice != 4);

        } else {
            attempts--;
            if (attempts > 0) {
                printf(red "\nIncorrect PIN. You have %d attempt(s) left.\n" reset, attempts);
            } else {
                printf(red "\nAccess Denied. All attempts used. Goodbye!\n" reset);
            }
        }
    }

    return 0;
}
