#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include <string>
#include "Transaction.h"

class FinanceManager
{
private:
    std::vector<Transaction> transactions;

    std::string currentUser;      // Logged-in user
    int nextTransactionId;

public:
    // Constructor
    FinanceManager(const std::string& username);

    // Transaction Operations
    void addIncome();
    void addExpense();
    void viewTransactions();
    void editTransaction();
    void deleteTransaction();
    void showBalance();
    std::string selectCategory();
    // File Handling
    void saveTransactions();
    void loadTransactions();
};

#endif