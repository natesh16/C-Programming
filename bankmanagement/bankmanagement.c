#include stdio.h
#include stdlib.h
#include string.h
#define MIN_AMOUNT 1000
#define MAX_CUSTOMERS 200

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} users;

users customers[MAX_CUSTOMERS];
int numCustomers = 0;

void createAccount() {
    if (numCustomers = MAX_CUSTOMERS) {
        printf(Maximum number of customers reached.n);
        return;
    }
    users newCustomer;
    printf(Enter account number );
    scanf(%d, &newCustomer.accountNumber);
    printf(Enter name );
    scanf( %[^n]s, newCustomer.name);
    printf(Enter initial balance );
    scanf(%f, &newCustomer.balance);
        if(newCustomer.balance  MIN_AMOUNT){
            printf(ACCOUNT MINIMUM INITAL IS 1000);
        }
        else{
            customers[numCustomers] = newCustomer;
            numCustomers++;
            printf(Account created successfully.n);
}
}

void deposit() {
    int accountNumber;
    float amount;
    int i;

    printf(Enter account number );
    scanf(%d, &accountNumber);

    for (i = 0; i  numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf(Enter amount to deposit );
            scanf(%f, &amount);

            customers[i].balance += amount;

            printf(Amount deposited successfully.n);
            return;
        }
    }

    printf(Account not found.n);
}

void withdraw() {
    int accountNumber;
    float amount;
    int i;

    printf(Enter account number );
    scanf(%d, &accountNumber);

    for (i = 0; i  numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf(Enter amount to withdraw );
            scanf(%f, &amount);

            if (customers[i].balance = amount) {
                customers[i].balance -= amount;
                printf(Amount withdrawn successfully.n);
            } else {
                printf(Insufficient balance.n);
            }
            return;
        }
    }

    printf(Account not found.n);
}

void displayAccountDetails() {
    int accountNumber;
    int i;

    printf(Enter account number );
    scanf(%d, &accountNumber);

    for (i = 0; i  numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf(Account Number %dn, customers[i].accountNumber);
            printf(Name %sn, customers[i].name);
            printf(Balance %.2fn, customers[i].balance);
            return;
        }
    }

    printf(Account not found.n);
}

int main() {
    int choice;

    while (1) {
        printf(nBank Management Systemn);
        printf(1. Create Accountn);
        printf(2. Depositn);
        printf(3. Withdrawn);
        printf(4. Display Account Detailsn);
        printf(5. Exitn);
        printf(Enter your choice );
        scanf(%d, &choice);

        switch (choice) {
            case 1
                createAccount();
                break;
            case 2
                deposit();
                break;
            case 3
                withdraw();
                break;
            case 4
                displayAccountDetails();
                break;
            case 5
                exit(0);
            default
                printf(Invalid choice. Please try again.n);
        }
    }

    return 0;
}

