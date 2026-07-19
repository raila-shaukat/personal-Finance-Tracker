#include <iostream>

#include "../include/UserManager.h"
#include "../include/FinanceManager.h"

using namespace std;

int main()
{
    UserManager userManager;

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
            string loggedInUser = userManager.loginUser();

            if (loggedInUser != "")
            {
                FinanceManager financeManager(loggedInUser);

                int financeChoice;

                do
                {
                    cout << "\n========== Finance Menu ==========\n";
                    cout << "Logged in as: " << loggedInUser << endl;
                    cout << "1. Add Income\n";
                    cout << "2. Add Expense\n";
                    cout << "3. View Transactions\n";
                    cout << "4. Edit Transaction\n";
                    cout << "5. Delete Transaction\n";
                    cout << "6. Show Balance\n";
                    cout << "7. Add Budget\n";
                    cout << "8. View Budgets\n";
                    cout << "9. Edit Budget\n";
                    cout << "10. Delete Budget\n";
                    cout << "11. Budget Status\n";
                    cout << "12. Logout\n";
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
                        financeManager.editTransaction();
                        break;
                    
                    case 5:
                        financeManager.deleteTransaction();
                        break;
                    
                    case 6:
                        financeManager.showBalance();
                        break;
                    
                    case 7:
                        financeManager.addBudget();
                        break;
                    
                    case 8:
                        financeManager.viewBudgets();
                        break;
                    
                    case 9:
                        financeManager.editBudget();
                        break;
                    
                    case 10:
                        financeManager.deleteBudget();
                        break;
                    
                    case 11:
                        financeManager.checkBudgetStatus();
                        break;
                    
                    case 12:
                        cout << "\nLogged Out Successfully!\n";
                        break;
                    
                    default:
                        cout << "\nInvalid Choice!\n";
                    }

                } while (financeChoice != 12);
            }

            break;
        }

        case 3:
            cout << "\nThank you for using Personal Finance Tracker!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}