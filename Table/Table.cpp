#include "Table.h"
#include "Commands.h"
#include "StringNumber.h"

#include <iomanip>
#include <cstring>
#include <cassert>
#include <utility>

tableCell** Table::allocTable(size_t height)
{
    tableCell** table = new tableCell* [height];
    return table;
}

void Table::deallocTable() noexcept
{
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width[i]; ++j)
            delete table[i][j];
        delete[] table[i];
    }
    delete[] table;
    width.clear();
}

Table::Table(size_t height)
        : height(height)
{
    if (height == 0)
        throw std::invalid_argument("Height cannot be 0");
    table = allocTable(height);
    width.reserve(height);
    for (size_t i = 0; i < height; ++i) {
        table[i] = new tableCell[1];
        table[i][0] = nullptr;
        width.push_back(1);
    }
}

void Table::copyCells(const Table& other)
{
    if (height < other.height)
        throw std::invalid_argument("Table::copyCells() invalid height");
    for (size_t i = 0; i < other.height; ++i) {
        if (width[i] != 0)
            delete[] table[i];
        width[i] = other.width[i];
        if (width[i] != 0) {
            table[i] = new tableCell[width[i]];
            for (size_t j = 0; j < width[i]; ++j) {
                if (other.table[i][j])
                    table[i][j] = other.table[i][j]->dynamicCopy();
                else
                    table[i][j] = nullptr;
            }
        } else {
            table[i] = nullptr;
        }
    }
}

void Table::copyTable(const Table& other)
{
    table = allocTable(other.height);
    height = other.height;
    copyCells(other);
}

void Table::moveTable(Table&& other) noexcept
{
    table = other.table;
    height = other.height;
    width = std::move(other.width);

    other.table = nullptr;
    other.height = 0;
}

Table::Table(const Table& other)
{
    width.resize(other.height);
    for (size_t& i : width)
        i = 0;
    copyTable(other);
}

Table::Table(Table&& other) noexcept
{
    moveTable(std::move(other));
}

Table& Table::operator=(const Table& other)
{
    if (this != &other) {
        Table temp(other);
        deallocTable();
        moveTable(std::move(temp));
    }
    return *this;
}

Table& Table::operator=(Table&& other) noexcept
{
    if (this != &other) {
        deallocTable();
        moveTable(std::move(other));
    }
    return *this;
}

Table::~Table()
{
    deallocTable();
}

void Table::expandRow(size_t x, size_t y, Table& table)
{
    //If the cell's position is outside the table
    //The row is expanded;
    if (y >= table.width[x]) {
        size_t newRowSize = y + 1;
        tableCell* tempRow = new tableCell[newRowSize];
        for (size_t i = 0; i < table.width[x]; ++i)
            tempRow[i] = table.table[x][i];
        for (size_t i = table.width[x]; i < newRowSize; ++i)
            tempRow[i] = nullptr;
        table.width[x] = newRowSize;
        delete[] table.table[x];
        table.table[x] = tempRow;
    }
}

void Table::validatePosition(size_t x, size_t y)
{
    // This function checks if the passed
    // coordinates gave a valid position in the table.
    // If the position is out of bounds the table is enlarged,
    // and if there is not enough memory std::bad_alloc is thrown;
    // The function provides "Strong Exception Guarantee"!
    if (x >= height) {
        Table temp(x + 1, this->width);
        temp.moveCells(*this);
        expandRow(x, y, temp); //This function checks if expansion is needed
        *this = std::move(temp);
    } else {
        expandRow(x, y, *this);
    }
}

void Table::editCell(const std::string& name, double value)
{
    Position oldCell = findCell(name);
    Cell* newCell = new doubleCell(oldCell.getX(), oldCell.getY(), value);
    delete table[oldCell.getX()][oldCell.getY()];
    table[oldCell.getX()][oldCell.getY()] = newCell;
    recalculateFormulaCells(); //Recalculates all formulae
}

void Table::editCell(const std::string& name, int value)
{
    Position oldCell = findCell(name);
    Cell* newCell = new intCell(oldCell.getX(), oldCell.getY(), value);
    delete table[oldCell.getX()][oldCell.getY()];
    table[oldCell.getX()][oldCell.getY()] = newCell;
    recalculateFormulaCells(); //Recalculates all formulae
}

void Table::editCell(const std::string& name, const std::string& str)
{
    Position oldCell = findCell(name);
    Cell* newCell;
    if (str[0] != '=') {
        newCell = new stringCell(oldCell.getX(), oldCell.getY(), str);
    } else {
        newCell = new formulaCell(oldCell.getX(), oldCell.getY(), str, *this);
    }
    delete table[oldCell.getX()][oldCell.getY()];
    table[oldCell.getX()][oldCell.getY()] = newCell;
    recalculateFormulaCells(); //Recalculates all formulae
}


std::ostream& operator<<(std::ostream& os, const Table& table)
{
    for (size_t i = 0; i < table.height; ++i) {
        if (table.width[i] == 0) {
            os << ",\n";
            continue;
        }
        for (size_t j = 0; j < table.width[i]; ++j) {
            if (table.table[i][j])
                os << table.table[i][j]->cellValueToStr() << ',';
            else
                os << ',';
        }
        os << '\n';
    }
    return os;
}

Position Table::findCell(const std::string& name)
{
    Position temp = Position::convertNameToPosition(name);
    validatePosition(temp.getX(), temp.getY());
    return temp;
}

void Table::print() const
{
    if (!table)
        throw std::invalid_argument("No table to print");
    size_t MAX_TABLE_WIDTH = 0;
    size_t arrSize = width.size();
    for (size_t i = 0; i < arrSize; ++i)
        if (width[i] > MAX_TABLE_WIDTH)
            MAX_TABLE_WIDTH = width[i];
    std::vector<size_t> widthOfColumn;
    for (size_t i = 0; i < MAX_TABLE_WIDTH; ++i)
        widthOfColumn.push_back(3);
    size_t len;
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width[i]; ++j)
            if (table[i][j] && (len = table[i][j]->cellWidth()) > widthOfColumn[j])
                widthOfColumn[j] = len;
    }
    std::cout << "  |";
    for (size_t i = 0; i < MAX_TABLE_WIDTH; ++i)
        std::cout << std::setw(widthOfColumn[i]) << i << '|';
    std::cout << '\n';
    for (size_t i = 0; i < height; ++i) {
        std::cout << (char) (i + 'A') << " |";
        for (size_t j = 0; j < width[i]; ++j) {
            if (table[i][j])
                std::cout << std::setw(widthOfColumn[j]) << *table[i][j] << '|';
            else
                std::cout << std::setw(widthOfColumn[j] + 1) << '|';
        }
        for (size_t j = width[i]; j < MAX_TABLE_WIDTH; ++j)
            std::cout << std::setw(widthOfColumn[j] + 1) << '|';
        std::cout << '\n';
    }
}

std::string Table::createExpression(const std::string& expression)
{
    //This function replaces the cell names with their values
    std::string expr(expression);
    if (expr.empty())
        throw std::invalid_argument("Invalid expression (expression is empty)");
    for (size_t i = 0; i < expr.length(); ++i) {
        if ('A' <= expr[i] && expr[i] <= 'Z') { //Found a cell name
            size_t begin = i; // Position of the first char of the cell name in the string.
            std::string cellName;

            //Push back the letter
            cellName.push_back(expr[i++]);

            //Push back the number
            while (i < expr.length() && StringNumber::isDigit(expr[i])) {
                cellName.push_back(expr[i]);
                ++i;
            }

            //Get the cells position
            Position cellPos = Position::convertNameToPosition(cellName);
            validatePosition(cellPos.getX(), cellPos.getY());

            //Replace the name with the value
            expr.erase(expr.begin() + begin, expr.begin() + i);
            if (table[cellPos.getX()][cellPos.getY()]) {
                double cellValue = table[cellPos.getX()][cellPos.getY()]->getValue();
                std::string value;
                if (cellValue <
                    0) { //if the cell value is negative put brackets, otherwise the expression may become invalid.
                    value.push_back('(');
                    value += std::to_string(cellValue);
                    value.push_back(')');
                } else { // Value is positive
                    value = std::to_string(cellValue);
                }
                expr.insert(begin, value);
                i = 0;
            } else { // if the cell is a nullptr
                expr.insert(begin, "0");
                i = 0;
            }
        }
    }
    return expr;
}

std::istream& operator>>(std::istream& is, Table& table)
{
    size_t line_number = 0; //Current line
    while (!is.eof()) {
        size_t cell_number = 0; //Current cell
        std::string line;
        std::getline(is, line, '\n');
        if (line.empty())
            continue;
        size_t len = line.length();
        for (size_t i = 0; i < len; ++i) { //Find different cells
            std::string cell;
            while (i < len && line[i] != ',') //Create the cell
                cell.push_back(line[i++]);
            table.validatePosition(line_number, cell_number); //Put cell in the table
            if (!cell.empty()) {
                std::string cmd = "edit ";
                cmd += Position::convertPositionToName(line_number, cell_number);
                cmd += " \"";
                cmd += cell;
                cmd.push_back('"');
                Command command(cmd);
                command.edit(table);
            }
            ++cell_number;
        }
        ++line_number;
    }
    return is;
}

void Table::recalculateFormulaCells()
{
    for (size_t i = 0; i < height; ++i)
        for (size_t j = 0; j < width[i]; ++j)
            if (table[i][j])
                table[i][j]->calculateFormula(*this);
}

const Cell* Table::at(size_t x, size_t y) const
{
    if (x > height || y > width[x])
        throw std::out_of_range("Table::at() : Position is outside the table.");
    return table[x][y];
}

Table::Table(size_t height, std::vector<size_t>  width)
        : table(allocTable(height)), height(height),
          width(std::move(width))
{
    size_t widthSize = this->width.size();
    if (widthSize > height)
        throw std::invalid_argument("Table::Table(size_t height, std::vector<size_t> width) : width.size() too big.");

    for (size_t i = 0; i < widthSize; ++i) {
        table[i] = new tableCell[this->width[i]];
        for (size_t j = 0; j < this->width[i]; ++j)
            table[i][j] = nullptr;
    }

    for (size_t i = widthSize; i < height; ++i) {
        table[i] = new tableCell[1];
        table[i][0] = nullptr;
        this->width.push_back(1);
    }
}

void Table::moveCells(Table& other)
{
    if (height < other.height)
        throw std::invalid_argument("Table::moveCells() : height error");

    for (size_t i = 0; i < other.height; ++i)
        if (width[i] < other.width[i])
            throw std::invalid_argument("Table::moveCells() : table width error");

    for (size_t i = 0; i < other.height; ++i) {
        for (size_t j = 0; j < other.width[i]; ++j) {
            delete table[i][j];
            table[i][j] = other.table[i][j];
            other.table[i][j] = nullptr;
        }
    }
}

















