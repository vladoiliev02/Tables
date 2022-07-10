#include "StringNumber.h"

bool StringNumber::isDigit(char a)
{
    return '0' <= a && a <= '9';
}

bool StringNumber::isDouble(const std::string& str)
{
//    if (!isNumber(str))       // Not needed in this project,
//        return false;         // because when this function is called it is already know the string is a number.
    size_t len = str.size();
    for (size_t i = 0; i < len; ++i)
        if (str[i] == '.')
            return true;
    return false;
}

bool StringNumber::isNumber(const std::string& str)
{
    //This function checks if a string is a valid number
    if (str.empty() || (str[0] != '-' && !isDigit(str[0])) ||
        (str[0] == '-' && str.length() == 1))
        return false;
    size_t len = str.length();
    size_t i = 1; //The first is already checked
    while (i < len && str[i] != '.') { //if the number is a double and has a decimal point
        if (!isDigit(str[i]))
            return false;
        ++i;
    }
    ++i; //skip over the '.'
    while (i < len) {
        if (!isDigit(str[i]))
            return false;
        ++i;
    }
    return true;
}

StringNumber& StringNumber::get()
{
    static StringNumber instance;
    return instance;
}

bool StringNumber::isUnsigned(const std::string& str)
{
    if (!isNumber(str))
        return false;
    return (str.front() != '-' && !isDouble(str));
}
