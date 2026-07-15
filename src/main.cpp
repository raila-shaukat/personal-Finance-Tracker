#include <iostream>
#include "../include/UserManager.h"

using namespace std;

int main()
{
    UserManager manager;

    int choice;

    do
    {
        cout << "\n===== Personal Finance Tracker =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.registerUser();
            break;

        case 2:
            manager.loginUser();
            break;

        case 3:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}