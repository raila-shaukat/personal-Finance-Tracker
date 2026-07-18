#include "../include/FinanceManager.h"
#include "../include/InputValidator.h"
#include "../include/CategoryManager.h"
#include "../include/FileManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor
FinanceManager::FinanceManager(const string& username)
{
    currentUser = username;
    nextTransactionId = 1;

    loadTransactions();
}

// -------------------- Add Income --------------------

void FinanceManager::addIncome()
{
    string title = InputValidator::getValidTitle();
    double amount = InputValidator::getPositiveAmount();
    string category;
    string date;

    cout << "\n========== Add Income ==========\n";

    cin.ignore();

    do
    {
    cout << "Title: ";
    getline(cin, title);

    if (title.empty())
    {
        cout << "Title cannot be empty.\n";
    }

    } while (title.empty());

    while (true)
    {
    cout << "Amount: ";

    cin >> amount;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Invalid input! Please enter a numeric amount.\n";
        continue;
    }

    if (amount <= 0)
    {
        cout << "Amount must be greater than zero.\n";
        continue;
    }

    break;
    }

    cin.ignore();

    category = CategoryManager::selectCategory();

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

    saveTransactions();

    cout << "\nIncome Added Successfully!\n";
}

// -------------------- Add Expense --------------------

void FinanceManager::addExpense()
{
    string title;
    double amount;
    string category;
    string date;

    cout << "\n========== Add Expense ==========\n";

    cin.ignore();

    do
    {
    cout << "Title: ";
    getline(cin, title);

    if (title.empty())
    {
        cout << "Title cannot be empty.\n";
    }

    } while (title.empty());

    while (true)
    {
    cout << "Amount: ";

    cin >> amount;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Invalid input! Please enter a numeric amount.\n";
        continue;
    }

    if (amount <= 0)
    {
        cout << "Amount must be greater than zero.\n";
        continue;
    }

    break;
    }

    cin.ignore();

    category = CategoryManager::selectCategory();

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

    saveTransactions();

    cout << "\nExpense Added Successfully!\n";
}

// -------------------- View Transactions --------------------

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
        cout << "---------------------------------------\n";
    }
}

void FinanceManager::editTransaction()
{
    if (transactions.empty())
    {
        cout << "\nNo Transactions Found!\n";
        return;
    }

    int id;

    cout << "\nEnter Transaction ID to Edit: ";
    cin >> id;

    for (auto &transaction : transactions)
    {
        if (transaction.getId() == id)
        {
            string title;
            double amount;
            string category;
            string date;
            string type;

            cin.ignore();

            cout << "\n===== Edit Transaction =====\n";

            cout << "New Title: ";
            getline(cin, title);

            cout << "New Amount: ";
            cin >> amount;

            cin.ignore();

            cout << "New Category: ";
            getline(cin, category);

            cout << "New Date (DD-MM-YYYY): ";
            getline(cin, date);

            cout << "Type (Income/Expense): ";
            getline(cin, type);

            transaction.setTitle(title);
            transaction.setAmount(amount);
            transaction.setCategory(category);
            transaction.setDate(date);
            transaction.setType(type);

            saveTransactions();

            cout << "\nTransaction Updated Successfully!\n";

            return;
        }
    }

    cout << "\nTransaction Not Found!\n";
}

void FinanceManager::deleteTransaction()
{
    if (transactions.empty())
    {
        cout << "\nNo Transactions Found!\n";
        return;
    }

    int id;

    cout << "\nEnter Transaction ID to Delete: ";
    cin >> id;

    for (auto it = transactions.begin(); it != transactions.end(); it++)
    {
        if (it->getId() == id)
        {
            transactions.erase(it);

            saveTransactions();

            cout << "\nTransaction Deleted Successfully!\n";

            return;
        }
    }

    cout << "\nTransaction Not Found!\n";
}

// -------------------- Show Balance --------------------

void FinanceManager::showBalance()
{
    double balance = 0;

    for (const auto& transaction : transactions)
    {
        if (transaction.getType() == "Income")
            balance += transaction.getAmount();
        else
            balance -= transaction.getAmount();
    }

    cout << "\n========== Current Balance ==========\n";
    cout << "Current User : " << currentUser << endl;
    cout << "Balance      : PKR " << balance << endl;
}

// -------------------- Save Transactions --------------------

void FinanceManager::saveTransactions()
{
    string filename = "data/" + currentUser + ".txt";

    ofstream file(filename);

    if (!file.is_open())
        return;

    for (const auto& transaction : transactions)
    {
        file
            << transaction.getId() << ","
            << transaction.getTitle() << ","
            << transaction.getAmount() << ","
            << transaction.getCategory() << ","
            << transaction.getDate() << ","
            << transaction.getType()
            << endl;
    }

    file.close();
}

// -------------------- Load Transactions --------------------

void FinanceManager::loadTransactions()
{
    string filename = "data/" + currentUser + ".txt";

    ifstream file(filename);

    if (!file.is_open())
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string title;
        string amount;
        string category;
        string date;
        string type;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, amount, ',');
        getline(ss, category, ',');
        getline(ss, date, ',');
        getline(ss, type);

        Transaction transaction(
            stoi(id),
            title,
            stod(amount),
            category,
            date,
            type
        );

        transactions.push_back(transaction);

        transactions = FileManager::loadTransactions(currentUser);

    nextTransactionId = 1;

for (const auto& transaction : transactions)
{
    if (transaction.getId() >= nextTransactionId)
    {
        nextTransactionId = transaction.getId() + 1;
    }
}
    }

    file.close();
}