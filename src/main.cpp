#include <iostream>
#include "../include/UserManager.h"
#include "../include/FinanceManager.h"

using namespace std;

int main()
{
    UserManager userManager;
    FinanceManager financeManager;

    int choice;

    do
    {
        cout << "\n========== Personal Finance Tracker ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            userManager.registerUser();
            break;

        case 2:
        {
            if (userManager.loginUser())
            {
                int financeChoice;

                do
                {
                    cout << "\n========== Finance Menu ==========\n";
                    cout << "1. Add Income\n";
                    cout << "2. Add Expense\n";
                    cout << "3. View Transactions\n";
                    cout << "4. Show Balance\n";
                    cout << "5. Logout\n";
                    cout << "Enter Choice: ";
                    cin >> financeChoice;

                    switch (financeChoice)
                    {
                    case 1:
                        financeManager.addIncome();
                        break;

                    case 2:
                        financeManager.addExpense();
                        break;

                    case 3:
                        financeManager.viewTransactions();
                        break;

                    case 4:
                        financeManager.showBalance();
                        break;

                    case 5:
                        cout << "Logged Out Successfully!\n";
                        break;

                    default:
                        cout << "Invalid Choice!\n";
                    }

                } while (financeChoice != 5);
            }

            break;
        }

        case 3:
            cout << "Thank you for using Personal Finance Tracker!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}