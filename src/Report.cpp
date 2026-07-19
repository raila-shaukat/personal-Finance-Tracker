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

void Report::showMonthlyReport(
    const vector<Transaction>& transactions)
{
    cout << "\n========== Monthly Report ==========\n";

    cout << "Feature will be completed in Step 3.\n";
}

void Report::showCategoryReport(
    const vector<Transaction>& transactions)
{
    cout << "\n========== Category Report ==========\n";

    cout << "Feature will be completed in Step 4.\n";
}