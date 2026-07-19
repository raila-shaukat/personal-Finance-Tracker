#include "../external/json/single_include/nlohmann/json.hpp"
#include "../include/FileManager.h"

#include <fstream>
#include <sstream>

using namespace std;
using json = nlohmann::json;
void FileManager::saveUsers(const vector<User>& users)
{
    json j = json::array();

    for (const auto& user : users)
    {
        j.push_back(
        {
            {"username", user.getUsername()},
            {"password", user.getPassword()}
        });
    }

    ofstream file("data/users.json");

    if(file.is_open())
        file << j.dump(4);

    file.close();
}

vector<User> FileManager::loadUsers()
{
    vector<User> users;

    ifstream file("data/users.json");

    if(!file.is_open())
        return users;

    json j;
    file >> j;

    for(const auto& item : j)
    {
        users.push_back(
            User(
                item["username"],
                item["password"]
            )
        );
    }

    file.close();

    return users;
}

// Save all transactions of a user
void FileManager::saveTransactions(
    const string& username,
    const vector<Transaction>& transactions)
{
    string filename = "data/" + username + ".txt";

    ofstream file(filename);

    if (!file.is_open())
        return;

    for (const auto& transaction : transactions)
    {
        file << transaction.getId() << ","
             << transaction.getTitle() << ","
             << transaction.getAmount() << ","
             << transaction.getCategory() << ","
             << transaction.getDate() << ","
             << transaction.getType()
             << endl;
    }

    file.close();
}

// Load all transactions of a user
vector<Transaction> FileManager::loadTransactions(
    const string& username)
{
    vector<Transaction> transactions;

    string filename = "data/" + username + ".txt";

    ifstream file(filename);

    if (!file.is_open())
        return transactions;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string title;
        string amount;
        string category;
        string date;
        string type;

        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, amount, ',');
        getline(ss, category, ',');
        getline(ss, date, ',');
        getline(ss, type);

        Transaction transaction(
            stoi(id),
            title,
            stod(amount),
            category,
            date,
            type
        );

        transactions.push_back(transaction);
    }

    file.close();

    return transactions;
}