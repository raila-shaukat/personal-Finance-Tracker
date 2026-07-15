#include "../include/UserManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

UserManager::UserManager()
{
    loadUsers();
}

bool UserManager::usernameExists(const string& username)
{
    for (const auto& user : users)
    {
        if (user.getUsername() == username)
        {
            return true;
        }
    }

    return false;
}

void UserManager::registerUser()
{
    string username;
    string password;

    cout << "\n===== Register =====\n";

    cout << "Username: ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    User newUser(username, password);

    users.push_back(newUser);
    saveUsers();
    cout << "Registration Successful!\n";
}

string UserManager::loginUser()
{
    string username;
    string password;

    cout << "\n===== Login =====\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (const auto& user : users)
    {
        if (user.getUsername() == username &&
        user.getPassword() == password)
    {
    cout << "\n=====================================\n";
    cout << "Welcome, " << username << "!\n";
    cout << "Login Successful.\n";
    cout << "=====================================\n";

    return username;
    }
    }

    cout << "Invalid Username or Password!\n";
    return "";
}
void UserManager::saveUsers()
{
    ofstream file("data/users.txt");

    if (!file.is_open())
    {
        cout << "Error opening users file!\n";
        return;
    }

    for (const auto& user : users)
    {
        file << user.getUsername()
             << ","
             << user.getPassword()
             << endl;
    }

    file.close();
}
void UserManager::loadUsers()
{
    ifstream file("data/users.txt");

    if (!file.is_open())
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string username;
        string password;

        getline(ss, username, ',');
        getline(ss, password);

        users.push_back(User(username, password));
    }

    file.close();
}