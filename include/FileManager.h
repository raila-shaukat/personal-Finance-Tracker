#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "Transaction.h"

class FileManager
{
public:
    static void saveTransactions(
        const std::string& username,
        const std::vector<Transaction>& transactions);

    static std::vector<Transaction> loadTransactions(
        const std::string& username);
};

#endif