#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User::User()
    {
    username = "";
    password = "";
    }
    User::User(string username, string password)
    {
    this->username = username;
    this->password = password;
    }

    void registerUser();
    bool login();
    void changePassword();
};

#endif