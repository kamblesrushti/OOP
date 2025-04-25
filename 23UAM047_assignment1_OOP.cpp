#include <iostream>
using namespace std;

int main() {
    int balance = 1000;
    int choice, amount;

    do {
        cout << "\nBank Menu" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Balance: $" << balance << endl;
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                balance += amount;
                cout << "Deposit successful. New balance: $" << balance << endl;
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                if (balance >= amount) {
                    balance -= amount;
                    cout << "Withdrawal successful. New balance: $" << balance << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}