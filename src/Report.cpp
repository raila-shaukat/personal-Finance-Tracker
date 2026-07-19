#include "../include/Report.h"

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void Report::showFinancialSummary(
    const vector<Transaction>& transactions)
{
    double income = 0;
    double expense = 0;

    for (const auto& transaction : transactions)
    {
        if (transaction.getType() == "Income")
        {
            income += transaction.getAmount();
        }
        else
        {
            expense += transaction.getAmount();
        }
    }

    cout << "\n========== Financial Summary ==========\n";

    cout << fixed << setprecision(2);

    cout << "Total Income   : PKR " << income << endl;
    cout << "Total Expense  : PKR " << expense << endl;
    cout << "Current Balance: PKR " << income - expense << endl;
}

void Report::showMonthlyReport(const vector<Transaction>& transactions)
{
    map<string, double> monthlyIncome;
    map<string, double> monthlyExpense;

    for (const auto& transaction : transactions)
    {
        string date = transaction.getDate();

        // Expected format: DD-MM-YYYY
        string monthYear = date.substr(3);

        if (transaction.getType() == "Income")
        {
            monthlyIncome[monthYear] += transaction.getAmount();
        }
        else
        {
            monthlyExpense[monthYear] += transaction.getAmount();
        }
    }

    if (monthlyIncome.empty() && monthlyExpense.empty())
    {
        cout << "\nNo Transactions Found!\n";
        return;
    }

    cout << "\n========== Monthly Report ==========\n";

    cout << fixed << setprecision(2);

    for (const auto& month : monthlyIncome)
    {
        string currentMonth = month.first;

        double income = monthlyIncome[currentMonth];
        double expense = monthlyExpense[currentMonth];

        cout << "\nMonth: " << currentMonth << endl;
        cout << "Income : PKR " << income << endl;
        cout << "Expense: PKR " << expense << endl;
        cout << "Balance: PKR " << income - expense << endl;
    }

    // Display months that have expenses only
    for (const auto& month : monthlyExpense)
    {
        if (monthlyIncome.find(month.first) == monthlyIncome.end())
        {
            cout << "\nMonth: " << month.first << endl;
            cout << "Income : PKR 0.00" << endl;
            cout << "Expense: PKR " << month.second << endl;
            cout << "Balance: PKR -" << month.second << endl;
        }
    }
}

void Report::showCategoryReport(
    const vector<Transaction>& transactions)
{
    cout << "\n========== Category Report ==========\n";

    cout << "Feature will be completed in Step 4.\n";
}