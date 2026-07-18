#include "../include/CategoryManager.h"
#include "../include/InputValidator.h"

#include <iostream>

using namespace std;

string CategoryManager::selectCategory()
{
    cout << "\n========== Categories ==========\n";
    cout << "1. Salary\n";
    cout << "2. Food\n";
    cout << "3. Transport\n";
    cout << "4. Shopping\n";
    cout << "5. Bills\n";
    cout << "6. Entertainment\n";
    cout << "7. Investment\n";
    cout << "8. Other\n";

    int choice = InputValidator::getMenuChoice(1, 8);

    switch (choice)
    {
    case 1: return "Salary";
    case 2: return "Food";
    case 3: return "Transport";
    case 4: return "Shopping";
    case 5: return "Bills";
    case 6: return "Entertainment";
    case 7: return "Investment";
    default: return "Other";
    }
}