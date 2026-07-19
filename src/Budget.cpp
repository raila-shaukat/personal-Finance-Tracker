#include "../include/Budget.h"

Budget::Budget()
{
    id = 0;
    category = "";
    limitAmount = 0;
}

Budget::Budget(
    int id,
    const std::string& category,
    double limitAmount)
{
    this->id = id;
    this->category = category;
    this->limitAmount = limitAmount;
}

int Budget::getId() const
{
    return id;
}

std::string Budget::getCategory() const
{
    return category;
}

double Budget::getLimitAmount() const
{
    return limitAmount;
}

void Budget::setCategory(const std::string& category)
{
    this->category = category;
}

void Budget::setLimitAmount(double amount)
{
    limitAmount = amount;
}