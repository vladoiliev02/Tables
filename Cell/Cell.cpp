#include <cstring>
#include "Cell.h"
#include "Expression.h"
#include "StringNumber.h"
#include "Table.h"

Position::Position(size_t x, size_t y)
        : x(x), y(y)
{}

size_t Position::getX() const
{ return x; }

size_t Position::getY() const
{ return y; }

Cell::Cell(size_t x, size_t y)
        : Position(x, y)
{}

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    cell.print(os);
    return os;
}


Position Position::convertNameToPosition(const std::string& name)
{
    if (name.empty())
        throw std::invalid_argument("Invalid position");
    if (name.front() < 'A' || name.front() > 'Z')
        throw std::invalid_argument("Invalid Cell name");
    size_t x = (size_t) (name.front() - 'A');
    if (!StringNumber::isUnsigned(name.c_str() + 1))
        throw std::invalid_argument("Invalid Cell name");
    size_t y = std::strtoul(name.c_str() + 1, nullptr, 10);
    return {x, y};
}

std::string Position::convertPositionToName(size_t x, size_t y)
{
    std::string name;
    if (x > 25)
        throw std::invalid_argument("Bad cell position(Invalid row).");
    name.push_back((char) (x + 'A'));
    name += std::to_string(y);
    return name;
}


intCell::intCell(size_t x, size_t y, int value)
        : Cell(x, y), value(value)
{}

void intCell::print(std::ostream& os) const
{
    os << this->value;
}

std::string intCell::cellValueToStr() const
{
    return std::to_string(value);
}

double intCell::getValue() const
{
    return (double)value;
}

size_t intCell::cellWidth() const
{
    size_t len = 0;
    int temp = value;
    while (temp != 0) {
        temp /= 10;
        len++;
    }
    return len;
}

Cell* intCell::dynamicCopy()
{
    return new intCell(*this);
}

doubleCell::doubleCell(size_t x, size_t y, double value)
        : Cell(x, y), value(value)
{}

void doubleCell::print(std::ostream& os) const
{
    os << this->value;
}

std::string doubleCell::cellValueToStr() const
{
    return std::to_string(value);
}

double doubleCell::getValue() const
{
    return value;
}

size_t doubleCell::cellWidth() const
{
    std::string strValue = std::to_string(value);
    while (!strValue.empty() && strValue.back() == '0')
        strValue.pop_back();
    return strlen(strValue.c_str());
}

Cell* doubleCell::dynamicCopy()
{
    return new doubleCell(*this);
}

stringCell::stringCell(size_t x, size_t y, std::string str)
        : Cell(x, y), str(std::move(str))
{}

void stringCell::print(std::ostream& os) const
{
    os << this->str;
}

std::string stringCell::cellValueToStr() const
{
    return str;
}

double stringCell::getValue() const
{
    return 0;
}

size_t stringCell::cellWidth() const
{
    return strlen(str.c_str());
}

Cell* stringCell::dynamicCopy()
{
    return new stringCell(*this);
}

formulaCell::formulaCell(size_t x, size_t y, std::string formula, Table& table)
        : Cell(x, y), formula(std::move(formula))
{
    formulaCell::calculateFormula(table); //Calculates the value;
}

void formulaCell::print(std::ostream& os) const
{
    os << value;
}

std::string formulaCell::cellValueToStr() const
{
    return formula;
}

double formulaCell::getValue() const
{
    return value;
}

void formulaCell::calculateFormula(Table& table)
{
    std::string expression = table.createExpression(this->formula);
    expression.erase(expression.begin()); //Erase the '='
    value = Expression::get().calculate(expression);
}

size_t formulaCell::cellWidth() const
{
    std::string strValue = std::to_string(value);
    while (!strValue.empty() && strValue.back() == '0')
        strValue.pop_back();
    return strlen(strValue.c_str());
}

Cell* formulaCell::dynamicCopy()
{
    return new formulaCell(*this);
}

