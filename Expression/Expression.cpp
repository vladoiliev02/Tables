#include "Expression.h"
#include "StringNumber.h"

#include "cmath"


void Expression::translate(const std::string& expression)
{
    size_t len = expression.length();
    size_t pos = 0; // in all functions underneath pos is passed by reference and is changed int the function
    while (pos < len) {
        std::string argument; //Current argument in the expresion
        skipBlankSpaces(expression, len, pos);
        createNumber(expression, pos, len, argument); //Creates a number in string form
        if (saveArgument(argument))
            continue;

        // Makes expressions in brackets into new expressions
        if (expression[pos] == '(') {
            createBracketExpression(expression, pos, len, argument);
            if (saveArgument(argument))
                continue;
        }

        while (isSign(expression[pos]) && pos < len) {
            //Searches for operators: (+, -, *, /, ^, (, ))
            //if an operator is found it is pushed back as an argument
            argument.push_back(expression[pos]);
            if (expression[pos] == '-') {
                //If a minus is found turn the number to negative and replace the minus with a plus;
                createNegativeNumber(expression, pos, len, argument);
                if (saveArgument(argument))
                    break;
            }
            ++pos;// skip over the found sign
            skipBlankSpaces(expression, len, pos);
            if (isSign(expression[pos])) //If there are two signs next to each other
                throw std::invalid_argument("Invalid expression");

            saveArgument(argument);
            break;
        }
    }
    remove_plus(); //When the expression is translated and negative numbers are created some invalid pluses are added which are removed in this function
}

double Expression::calculate(const std::string& expression)
{
    if (expression.empty())
        throw std::invalid_argument("Expression is empty");
    if (!arguments.empty())
        arguments.clear();
    translate(expression);
    double value = 0;
    performCalculation(value);
    return value;
}

double Expression::performCalculation(double& value)
{
    if (value == 0 || value == -0) //Handles expressions in brackets
        value = calculateBracketsExpressions();

    if (arguments.size() <= 1)
        return value = strtod(arguments[0].c_str(), nullptr);
    if (arguments.size() == 2 && arguments[0] == "-") {
        arguments[0] += arguments[1];
        arguments.pop_back();
        if (arguments[0][1] == '-' && StringNumber::isNumber(arguments[0].c_str() + 2)) // for numbers like (--4)
            arguments[0].erase(arguments[0].begin(), arguments[0].begin() + 2);
        return value = strtod(arguments[0].c_str(), nullptr);
    }



    // Power
    for (size_t i = arguments.size() - 1; i > 0 && !arguments.empty(); --i) {
        if (arguments[i] == "^") {
            value = power(i);
            return performCalculation(value);
        }
    }
    //Division
    for (size_t i = 0; i < arguments.size() && !arguments.empty(); ++i) {
        if (arguments[i] == "/") {
            value = divide(i);
            return performCalculation(value);
        }
    }
    //Multiplication
    for (size_t i = 0; i < arguments.size() && !arguments.empty(); ++i) {
        if (arguments[i] == "*") {
            value = multiply(i);
            return performCalculation(value);
        }
    }
    //Subtraction
    for (size_t i = 0; i < arguments.size() && !arguments.empty(); ++i) {
        if (arguments[i] == "-") {
            value = subtract(i);
            return performCalculation(value);
        }
    }
    //Addition
    for (size_t i = 0; i < arguments.size() && !arguments.empty(); ++i) {
        if (arguments[i] == "+") {
            value = add(i);
            return performCalculation(value);
        }
    }
    throw std::bad_exception();
}

double Expression::multiply(size_t pos)
{
    double value =
            strtod(arguments[pos - 1].c_str(), nullptr)
            *
            strtod(arguments[pos + 1].c_str(), nullptr);
    arguments[pos] = std::to_string(value);
    arguments.erase(arguments.begin() + pos + 1);
    arguments.erase(arguments.begin() + pos - 1);
    return value;
}

double Expression::add(size_t pos)
{
    double value =
            strtod(arguments[pos - 1].c_str(), nullptr)
            +
            strtod(arguments[pos + 1].c_str(), nullptr);
    arguments[pos] = std::to_string(value);
    arguments.erase(arguments.begin() + pos + 1);
    arguments.erase(arguments.begin() + pos - 1);
    return value;
}

double Expression::power(size_t pos)
{
    double value = pow(
            strtod(arguments[pos - 1].c_str(), nullptr),
            strtod(arguments[pos + 1].c_str(), nullptr));
    arguments[pos] = std::to_string(value);
    arguments.erase(arguments.begin() + pos + 1);
    arguments.erase(arguments.begin() + pos - 1);
    return value;
}

double Expression::divide(size_t pos)
{
    double denominator = strtod(arguments[pos + 1].c_str(), nullptr);
    if (denominator == 0)
        throw std::invalid_argument("Division by 0");
    double value =
            strtod(arguments[pos - 1].c_str(), nullptr)
            /
            denominator;
    arguments[pos] = std::to_string(value);
    arguments.erase(arguments.begin() + pos + 1);
    arguments.erase(arguments.begin() + pos - 1);
    return value;
}

double Expression::subtract(size_t pos)
{
    double value =
            strtod(arguments[pos - 1].c_str(), nullptr)
            -
            strtod(arguments[pos + 1].c_str(), nullptr);
    arguments[pos] = std::to_string(value);
    arguments.erase(arguments.begin() + pos + 1);
    arguments.erase(arguments.begin() + pos - 1);
    return value;
}


bool Expression::isSign(char a)
{
    return a == '+' ||
           a == '-' ||
           a == '*' ||
           a == '/' ||
           a == '^';
}

bool Expression::isBracket(char a)
{
    return a == '(' || a == ')';
}

void Expression::skipBlankSpaces(const std::string& str, size_t size, size_t& idx)
{
    while (str[idx] == ' ' && idx < size) //Skip empty spaces
        ++idx;
}

void
Expression::createBracketExpression(const std::string& expression, size_t& pos, size_t len, std::string& argument)
{
    argument.push_back(expression[pos++]);
    size_t numberOfOpenedBrackets = 1;  // Every time a bracket is open the counter increases and when it is closed it decreases
    //If numberOfOpenedBrackets is 0 all brackets are closed correctly;
    while (pos < len && numberOfOpenedBrackets != 0) {
        skipBlankSpaces(expression, len, pos);
        if (expression[pos] == ')')
            numberOfOpenedBrackets--;
        if (expression[pos] == '(')
            numberOfOpenedBrackets++;
        argument.push_back(expression[pos++]);
    }
    skipBlankSpaces(expression, len, pos);
    if (numberOfOpenedBrackets > 0 || expression[pos] == ')')
        throw std::invalid_argument("Invalid brackets"); //If brackets are not closed correctly
}

void
Expression::createNegativeNumber(const std::string& expression, size_t& pos, size_t len, std::string& argument)
{
    arguments.emplace_back("+");
    ++pos;
    skipBlankSpaces(expression, len, pos);
    if (pos < len && isSign(expression[pos]))
        throw std::invalid_argument("Invalid expression(2 signs next to each other)");
    if (pos < len && StringNumber::isDigit(expression[pos]))
        createNumber(expression, pos, len, argument);
}

void Expression::createNumber(const std::string& expression, size_t& pos, size_t len, std::string& argument)
{
    while ((StringNumber::isDigit(expression[pos]) || expression[pos] == '.') && pos < len) { //Find a number and save it
        argument.push_back(expression[pos]);
        ++pos;
    }
    if (!argument.empty() && !StringNumber::isNumber(argument))
        throw std::invalid_argument("Invalid number in expression");
}

bool Expression::saveArgument(std::string& argument)
{
    if (!argument.empty()) {
        arguments.push_back(argument);
        return true;
    }
    return false;
}

void Expression::remove_plus()
{
    //This function removes all invalid pluses created when the
    //negative numbers in the expression are created
    size_t i = 0;
    while (i < arguments.size() && !arguments.empty()) {
        if (arguments[i] == "+") {
            if (i == 0 || i == arguments.size() - 1 ||
                (!StringNumber::isNumber(arguments[i + 1]) && !isBracket(arguments[i + 1].front())) ||
                (!StringNumber::isNumber(arguments[i - 1]) && !isBracket(arguments[i - 1].back()))) {
                arguments.erase(arguments.begin() + i);
                continue;
            }
        }
        ++i;
    }
}

Expression& Expression::get()
{
    static Expression instance;
    return instance;
}

double Expression::calculateBracketsExpressions()
{
    double value;
    for (size_t i = 0; i < arguments.size() && !arguments.empty(); ++i) {
        if (!arguments.empty() && arguments[i][0] == '(') { // Finds the expression.
            std::string newExpression(arguments[i].c_str() + 1); // Creates a new expression without the brackets.
            newExpression.pop_back(); // Removes the bracket at the back.
            Expression newExpr;
            value = newExpr.calculate(newExpression); // Calculates the new expression.
            arguments[i] = std::to_string(value); //Replaces the bracket expression with its value.
            i = 0;
            continue;
        }
    }
    return value;
}
