#include "../include/InputValidator.h"

#include <iostream>
#include <limits>

using namespace std;

double InputValidator::getPositiveAmount()
{
    double amount;

    while (true)
    {
        cout << "Amount: ";
        cin >> amount;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a numeric amount.\n";
            continue;
        }

        if (amount <= 0)
        {
            cout << "Amount must be greater than zero.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return amount;
    }
}

string InputValidator::getValidTitle()
{
    string title;

    while (true)
    {
        cout << "Title: ";
        getline(cin, title);

        if (!title.empty())
            return title;

        cout << "Title cannot be empty.\n";
    }
}

int InputValidator::getMenuChoice(int min, int max)
{
    int choice;

    while (true)
    {
        cout << "Enter Choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input!\n";
            continue;
        }

        if (choice < min || choice > max)
        {
            cout << "Please enter a number between "
                 << min << " and " << max << ".\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return choice;
    }
}