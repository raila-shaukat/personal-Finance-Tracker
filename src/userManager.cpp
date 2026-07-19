#include "../include/UserManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/FileManager.h"
using namespace std;

UserManager::UserManager()
{
    users = FileManager::loadUsers();
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
    FileManager::saveUsers(users);
    cout << "Registration Successful!\n";
}

std::string UserManager::loginUser()
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
