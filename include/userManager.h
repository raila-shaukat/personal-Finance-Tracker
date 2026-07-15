#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"

class UserManager
{
private:
    std::vector<User> users;

public:
    UserManager();

    void registerUser();
    bool loginUser();

    bool usernameExists(const std::string& username);

    void saveUsers();
    void loadUsers();
};

#endif