#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include "Transaction.h"

class Report
{
public:
    static void monthlyReport(const std::vector<Transaction>& transactions);

    static void categoryReport(const std::vector<Transaction>& transactions);

    static void incomeExpenseReport(const std::vector<Transaction>& transactions);

    static void saveReport(const std::vector<Transaction>& transactions);
};

#endif