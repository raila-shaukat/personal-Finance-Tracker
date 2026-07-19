#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include <string>

#include "Transaction.h"
#include "Budget.h"

class FinanceManager
{
private:
    std::string currentUser;

    std::vector<Transaction> transactions;
    std::vector<Budget> budgets;

    int nextTransactionId;
    int nextBudgetId;

public:
    FinanceManager(const std::string& username);

    // Transaction Management
    void addIncome();
    void addExpense();
    void viewTransactions();
    void editTransaction();
    void deleteTransaction();
    void showBalance();

    // Budget Management
    void addBudget();
    void viewBudgets();
    void editBudget();
    void deleteBudget();
    void checkBudgetStatus();

    // File Handling
    void saveTransactions();
    void loadTransactions();
};

#endif