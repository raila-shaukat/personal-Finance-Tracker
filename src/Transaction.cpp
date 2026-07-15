#include "../include/Transaction.h"

Transaction::Transaction()
{
    id = 0;
    title = "";
    amount = 0;
    category = "";
    date = "";
    type = "";
}

Transaction::Transaction(
    int id,
    const std::string& title,
    double amount,
    const std::string& category,
    const std::string& date,
    const std::string& type)
{
    this->id = id;
    this->title = title;
    this->amount = amount;
    this->category = category;
    this->date = date;
    this->type = type;
}

int Transaction::getId() const
{
    return id;
}

std::string Transaction::getTitle() const
{
    return title;
}

double Transaction::getAmount() const
{
    return amount;
}

std::string Transaction::getCategory() const
{
    return category;
}

std::string Transaction::getDate() const
{
    return date;
}

std::string Transaction::getType() const
{
    return type;
}

void Transaction::setId(int id)
{
    this->id = id;
}

void Transaction::setTitle(const std::string& title)
{
    this->title = title;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

void Transaction::setCategory(const std::string& category)
{
    this->category = category;
}

void Transaction::setDate(const std::string& date)
{
    this->date = date;
}

void Transaction::setType(const std::string& type)
{
    this->type = type;
}