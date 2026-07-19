#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include "Transaction.h"

class Report
{
public:
    static void showFinancialSummary(
        const std::vector<Transaction>& transactions
    );

    static void showMonthlyReport(
        const std::vector<Transaction>& transactions
    );

    static void showCategoryReport(
        const std::vector<Transaction>& transactions
    );
};

#endif