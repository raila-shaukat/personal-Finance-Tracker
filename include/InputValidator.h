#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>

class InputValidator
{
public:
    static double getPositiveAmount();
    static std::string getValidTitle();
    static int getMenuChoice(int min, int max);
};

#endif