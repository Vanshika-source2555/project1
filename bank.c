#include <stdio.h>

int verifyPin(int pin);
void displayBalance(int balance);
int deposit(int balance);
int withdraw(int balance);
int changePin(int pin);
int changeMobileNumber(int mobileNumber);
void displayAccountInfo(char name[50], int accountNumber, int mobileNumber, char email[50], int balance);

int main() {
    char name[50] = "vanshika";
    int accountNumber = 334585815;
    int mobileNumber = 7206161740;
    int pin = 1234;
    char email[50] = "vanshika567@gmail.com";
    int balance = 0; 
    printf("**** Welcome to Punjab National Bank ATM ****\n");
    pin = verifyPin(pin);  
    while (1) {
        int choice;
        printf("\nPress 1 for Account Balance\n");
        printf("Press 2 for Deposit Money\n");
        printf("Press 3 for Withdraw Money\n");
        printf("Press 4 for Change Your PIN\n");
        printf("Press 5 for Change Your Mobile Number\n");
        printf("Press 6 for Account Holder Information\n");
        printf("Press 7 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayBalance(balance);
        } else if (choice == 2) {
            balance = deposit(balance);
        } else if (choice == 3) {
            balance = withdraw(balance);
        } else if (choice == 4) {
            pin = changePin(pin); 
        } else if (choice == 5) {
            mobileNumber = changeMobileNumber(mobileNumber);
        } else if (choice == 6) {
            displayAccountInfo(name, accountNumber, mobileNumber, email, balance);
        } else if (choice == 7) {
            printf("Thank you for using our services\n");
            printf("Please exit your card\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

int verifyPin(int pin) {
    int enteredPin;
    printf("Enter your PIN: ");
    scanf("%d", &enteredPin);
    while (enteredPin != pin) {
        printf("Incorrect PIN. Try again: ");
        scanf("%d", &enteredPin);
    }
    return pin;  
}

void displayBalance(int balance) {
    printf("Your current balance is: %d\n", balance);
}

int deposit(int balance) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    balance=balance+amount;
    printf("Amount deposited successfully. New balance: %d\n", balance);
    return balance;  
}

int withdraw(int balance) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance = balance-amount;
        printf("Please collect your cash. New balance: %d\n", balance);
    }
    return balance;  
}

int changePin(int pin) {
    int newPin;
    printf("Enter new PIN: ");
    scanf("%d", &newPin);
    return newPin;  
}

int changeMobileNumber(int mobileNumber) {
    int newMobile;
    printf("Enter new mobile number: ");
    scanf("%d", &newMobile);
    return newMobile;  
}

void displayAccountInfo(char name[50], int accountNumber, int mobileNumber, char email[50], int balance) {
    printf("Account Holder Name: %s\n", name);
    printf("Account Number: %d\n", accountNumber);
    printf("Mobile Number: %d\n", mobileNumber);
    printf("Email: %s\n", email);
    printf("Current Balance: %d\n", balance);
}
