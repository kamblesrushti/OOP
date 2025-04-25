#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    // Default Constructor
    BankAccount() {
        accountHolder = "";
        accountNumber = 0;
        accountType = "";
        balance = 0.0;
    }

    // Parameterized Constructor
    BankAccount(string holder, int number, string type, double bal) {
        accountHolder = holder;
        accountNumber = number;
        accountType = type;
        balance = bal;
    }

    // Accessor Methods
    string getAccountHolder() { return accountHolder; }
    int getAccountNumber() { return accountNumber; }
    string getAccountType() { return accountType; }
    double getBalance() { return balance; }

    // Mutator Method
    void setAccountType(string newType) { accountType = newType; }

    // Functional Methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Depositing " << amount << "   New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawing " << amount << "   New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Details:" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Create BankAccount objects using default and parameterized constructors
    BankAccount account1;
    BankAccount account2("Srushti Kamble", 168756, "Savings", 5000.0);

    // Display initial account details
    account2.displayAccountDetails();

    // Deposit and withdraw money
    account2.deposit(2000.0);
    account2.withdraw(1500.0);

    // Update and display account details
    account2.setAccountType("Current");
    cout << "Updated Account Type to Current." << endl;
    account2.displayAccountDetails();

    return 0;
}
