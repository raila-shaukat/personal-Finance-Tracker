#include "../include/Report.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void Report::monthlyReport(const vector<Transaction>& transactions)
{
    if (transactions.empty())
    {
        cout << "\nNo transactions found.\n";
        return;
    }

    map<string, double> monthly;

    for (const auto& t : transactions)
    {
        string month = t.getDate().substr(0, 7);

        if (t.getType() == "Income")
            monthly[month] += t.getAmount();
        else
            monthly[month] -= t.getAmount();
    }

    cout << "\n====================================\n";
    cout << "         MONTHLY REPORT\n";
    cout << "====================================\n";

    for (const auto& m : monthly)
    {
        cout << left << setw(15) << m.first
             << "Balance : " << m.second << endl;
    }
}

void Report::categoryReport(const vector<Transaction>& transactions)
{
    if (transactions.empty())
    {
        cout << "\nNo transactions found.\n";
        return;
    }

    map<string, double> category;

    for (const auto& t : transactions)
    {
        if (t.getType() == "Expense")
            category[t.getCategory()] += t.getAmount();
    }

    cout << "\n====================================\n";
    cout << "      CATEGORY EXPENSE REPORT\n";
    cout << "====================================\n";

    for (const auto& c : category)
    {
        cout << left << setw(20)
             << c.first
             << c.second << endl;
    }
}

void Report::incomeExpenseReport(const vector<Transaction>& transactions)
{
    if (transactions.empty())
    {
        cout << "\nNo transactions found.\n";
        return;
    }

    double income = 0;
    double expense = 0;

    for (const auto& t : transactions)
    {
        if (t.getType() == "Income")
            income += t.getAmount();
        else
            expense += t.getAmount();
    }

    cout << "\n====================================\n";
    cout << "       FINANCIAL SUMMARY\n";
    cout << "====================================\n";

    cout << "Total Income  : " << income << endl;
    cout << "Total Expense : " << expense << endl;
    cout << "Balance       : " << income - expense << endl;
}

void Report::saveReport(const vector<Transaction>& transactions)
{
    if (transactions.empty())
    {
        cout << "\nNo transactions found.\n";
        return;
    }

    ofstream file("reports/report.txt");

    if (!file.is_open())
    {
        cout << "\nUnable to save report.\n";
        return;
    }

    double income = 0;
    double expense = 0;

    for (const auto& t : transactions)
    {
        if (t.getType() == "Income")
            income += t.getAmount();
        else
            expense += t.getAmount();
    }

    file << "====================================\n";
    file << "      PERSONAL FINANCE REPORT\n";
    file << "====================================\n\n";

    file << "Total Income  : " << income << endl;
    file << "Total Expense : " << expense << endl;
    file << "Balance       : " << income - expense << endl;

    file.close();

    cout << "\nReport saved successfully in reports/report.txt\n";
}