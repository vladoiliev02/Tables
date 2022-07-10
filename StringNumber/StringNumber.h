#pragma once

#include <string>

class StringNumber {
private:
    StringNumber() = default;
public:
    StringNumber(const StringNumber&) = delete;
    StringNumber& operator=(const StringNumber&) = delete;
    static StringNumber& get();

    static bool isNumber(const std::string& str);
    static bool isDigit(char a);
    static bool isDouble(const std::string& str);
    static bool isUnsigned(const std::string& str);
};