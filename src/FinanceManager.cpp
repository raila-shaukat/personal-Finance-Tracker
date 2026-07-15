#include "../include/FinanceManager.h"
#include <iostream>

using namespace std;

FinanceManager::FinanceManager()
{
    nextTransactionId = 1;
}

void FinanceManager::addIncome()
{
    string title;
    double amount;
    string category;
    string date;
    cout << "\n========== Add Income ==========\n";

    cout << "Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Amount: ";
    cin >> amount;

    cin.ignore();

    cout << "Category: ";
    getline(cin, category);

    cout << "Date (DD-MM-YYYY): ";
    getline(cin, date);

    Transaction income(
        nextTransactionId++,
        title,
        amount,
        category,
        date,
        "Income"
    );

    transactions.push_back(income);

    cout << "\nIncome Added Successfully!\n";
}

void FinanceManager::addExpense()
{
    string title;
    double amount;
    string category;
    string date;

    cout << "\n========== Add Expense ==========\n";

    cout << "Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Amount: ";
    cin >> amount;

    cin.ignore();

    cout << "Category: ";
    getline(cin, category);

    cout << "Date (DD-MM-YYYY): ";
    getline(cin, date);

    Transaction expense(
        nextTransactionId++,
        title,
        amount,
        category,
        date,
        "Expense"
    );

    transactions.push_back(expense);

    cout << "\nExpense Added Successfully!\n";
}

void FinanceManager::viewTransactions()
{
    if (transactions.empty())
    {
        cout << "\nNo Transactions Found!\n";
        return;
    }

    cout << "\n========== All Transactions ==========\n";

    for (const auto& transaction : transactions)
    {
        cout << "ID: " << transaction.getId() << endl;
        cout << "Title: " << transaction.getTitle() << endl;
        cout << "Amount: " << transaction.getAmount() << endl;
        cout << "Category: " << transaction.getCategory() << endl;
        cout << "Date: " << transaction.getDate() << endl;
        cout << "Type: " << transaction.getType() << endl;
        cout << "----------------------------------\n";
    }
}

void FinanceManager::showBalance()
{
    double balance = 0;

    for (const auto& transaction : transactions)
    {
        if (transaction.getType() == "Income")
        {
            balance += transaction.getAmount();
        }
        else
        {
            balance -= transaction.getAmount();
        }
    }

    cout << "\n========== Current Balance ==========\n";
    cout << "Balance: PKR " << balance << endl;
}