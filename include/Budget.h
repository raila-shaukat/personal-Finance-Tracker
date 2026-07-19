#ifndef BUDGET_H
#define BUDGET_H

#include <string>

class Budget
{
private:
    int id;
    std::string category;
    double limitAmount;

public:
    Budget();

    Budget(
        int id,
        const std::string& category,
        double limitAmount
    );

    int getId() const;

    std::string getCategory() const;

    double getLimitAmount() const;

    void setCategory(const std::string& category);

    void setLimitAmount(double amount);
};

#endif