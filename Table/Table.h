#pragma once

#include <vector>

#include "Cell.h"
#include "Expression.h"

using tableCell = Cell*;

class Table {
    // The".csv" table is stored as a 2D matrix of Cell*.
    // Each row of this matrix can have a different size(width).

    tableCell** table = nullptr;    // The matrix.
    size_t height = 0;              // Number of rows.
    std::vector<size_t> width = {}; // Width of every row.

private:
    static tableCell** allocTable(size_t height);
    void deallocTable() noexcept;
    void copyTable(const Table& other);
    void copyCells(const Table& other);
    void moveCells(Table& other); // Strong exception guarantee
    void moveTable(Table&& other) noexcept;

    // The validatePosition() functions checks if the the coordinates
    // passed to it are in bounds. If the are out of bounds the table
    // is accordingly resized. It provides the strong exception
    // guarantee and if the table cannot be resized, no previous
    // data is lost.
    void validatePosition(size_t x, size_t y); //Strong except guarantee

    // Widens the row if the y coordinate is out of bounds.
    // This function also provides the strong exception guarantee.
    static void expandRow(size_t x, size_t y, Table& other); //Strong except guarantee

    // Searches for a cell by name and returns its
    // position in the table.
    Position findCell(const std::string& name);

public:
    explicit Table(size_t height);
    Table(size_t height, std::vector<size_t>  width);
    Table(const Table& other);
    Table(Table&& other) noexcept;
    Table& operator=(const Table& other);   //Strong exception guarantee
    Table& operator=(Table&& other) noexcept;
    ~Table();

    // These 2 operators are mainly used for std::fstream.
    // If you want to print the table on the console use
    // the print() function.
    friend std::ostream& operator<<(std::ostream& os, const Table& table);
    friend std::istream& operator>>(std::istream& is, Table& table);

    // Change the value of a cell to a new value.
    // All edit functions provide strong exception guarantee.
    void editCell(const std::string& name, double value); //Strong except guarantee
    void editCell(const std::string& name, int value); //Strong except guarantee
    void editCell(const std::string& name, const std::string& str); //Strong except guarantee

    // If a formula is passed as a cell value, for example:
    // "=A0 + 2", this function changes all cell names to
    // their values, so that the expression can be calculated.
    std::string createExpression(const std::string& expression);

    // Prints the table in an understandable way,
    // with aligned rows and columns.
    void print() const;

    // Calculates formula cells, so that if a cell is edited
    // the value of the formula changes.
    void recalculateFormulaCells();

    // Returns a pointer to a cell at position (x, y);
    // If position is invalid throws std::out_of_range();
    const Cell* at(size_t x, size_t y) const;
};