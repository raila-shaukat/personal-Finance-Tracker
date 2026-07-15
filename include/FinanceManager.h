#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include "Transaction.h"

class FinanceManager
{
private:
    std::vector<Transaction> transactions;
    int nextTransactionId;

public:
    FinanceManager();

    void addIncome();
    void addExpense();
    void viewTransactions();
    void showBalance();
};

#endif