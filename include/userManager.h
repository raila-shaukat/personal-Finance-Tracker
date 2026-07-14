#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"

using namespace std;

class UserManager
{
private:
    vector<User> users;

public:
    void registerUser();
    bool loginUser();
};

#endif