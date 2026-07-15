#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    int id;
    std::string title;
    double amount;
    std::string category;
    std::string date;
    std::string type;   // Income or Expense

public:
    Transaction();

    Transaction(
        int id,
        const std::string& title,
        double amount,
        const std::string& category,
        const std::string& date,
        const std::string& type
    );

    // Getters
    int getId() const;
    std::string getTitle() const;
    double getAmount() const;
    std::string getCategory() const;
    std::string getDate() const;
    std::string getType() const;

    // Setters
    void setId(int id);
    void setTitle(const std::string& title);
    void setAmount(double amount);
    void setCategory(const std::string& category);
    void setDate(const std::string& date);
    void setType(const std::string& type);
};

#endif