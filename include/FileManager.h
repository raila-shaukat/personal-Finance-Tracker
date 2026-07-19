#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "User.h"
#include "Transaction.h"
#include "Budget.h"

class FileManager
{
public:
    // User
    static void saveUsers(const std::vector<User>& users);
    static std::vector<User> loadUsers();

    // Transactions
    static void saveTransactions(
        const std::string& username,
        const std::vector<Transaction>& transactions
    );

    static std::vector<Transaction> loadTransactions(
        const std::string& username
    );

    // Budgets
    static void saveBudgets(
        const std::string& username,
        const std::vector<Budget>& budgets
    );

    static std::vector<Budget> loadBudgets(
        const std::string& username
    );
};

#endif