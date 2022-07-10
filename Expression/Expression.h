#pragma once


#include "Table.h"

// This class is used to calculate expressions,
// which are passed as strings.

class Expression {
    // The "arguments" vector holds all the different
    // parts of the expression:
    // the numbers and the operators.
    std::vector<std::string> arguments;

private:

    // Checks if a char is a sign(operator).
    static bool isSign(char a);

    // Checks if a char os a bracket: "(" or ")".
    static bool isBracket(char a);

    // The available operations
    double multiply(size_t pos);
    double add(size_t pos);
    double power(size_t pos);
    double divide(size_t pos);
    double subtract(size_t pos);

    // Expressions in brackets are calculated
    // as whole new expressions.
    double calculateBracketsExpressions();

    //Breaks down the expression into arguments, so that
    // it can be calculated correctly
    void translate(const std::string& expression);

    // Bracket expressions are stored as
    // a single argument, so that they can be
    // calculated as a new expression.
    static void createBracketExpression(const std::string& expression, size_t& pos, size_t len, std::string& argument);  // An expression within brackets is stored as a whole argument and is later calculated as a separate expression

    // If a '-' is found the number after it is turned to negative
    // and the minus is replaced ny a plus,
    // thus the expression does not change.
    void createNegativeNumber(const std::string& expression, size_t& pos, size_t len, std::string& argument);

    // Separates the numbers in the expression.
    static void createNumber(const std::string& expression, size_t& pos, size_t len, std::string& argument);

    // Skips all blank spaces in the expression.
    static void skipBlankSpaces(const std::string& str, size_t size, size_t& idx);

    // Saves the current argument in the vector.
    bool saveArgument(std::string& argument);

    // Removes all "invalid" pluses,
    // added by the createNegativeNumber() function.
    void remove_plus();

    //Calculates the expression recursively.
    double performCalculation(double& value);

    // Constructor (private because the class is
    // a singleton).
    explicit Expression() = default;

public:
    // Objects cannot be copied.
    Expression(const Expression&) = delete;
    Expression& operator=(const Expression&) = delete;
    ~Expression() = default;

    // Get the instance of the class.
    static Expression& get();

    // Calculate an expression.
    double calculate(const std::string& expression);
};