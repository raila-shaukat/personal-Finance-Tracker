#include <iostream>
#include "../include/User.h"

using namespace std;

int main()
{
    User user("Raila", "123456");

    cout << "Username: " << user.getUsername() << endl;
    cout << "Password: " << user.getPassword() << endl;

    return 0;
}
