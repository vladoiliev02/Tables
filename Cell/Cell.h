#pragma once

#include <iostream>
#include <string>

class Table;

class Position {
    //Position of the cell.
    //The position can be transformed to a "name of the cell.
    //The name of the cell is the position in the table,
    //for example the cell at table[0][0] has the name "A0".

    //The coordinates of the cell in the table:
    size_t x;
    size_t y;

protected:
    Position(size_t x, size_t y);

public:
    //Converts the name to a position, example: "A0" == table[0][0];
    static Position convertNameToPosition(const std::string& name);

    //Converts the position to name, example: table[0][0] == "A0"
    static std::string convertPositionToName(size_t x, size_t y);


    size_t getX() const;
    size_t getY() const;
};

class Cell : public Position {
    //A single cell in the table
protected:
    Cell(size_t x, size_t y);
    virtual void print(std::ostream& os) const = 0;

public:
    virtual ~Cell() = default;
    virtual Cell* dynamicCopy() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

    // Converts the value of the cell to a string
    virtual std::string cellValueToStr() const = 0;

    // Returns the value as a double, since all results should be double.
    virtual double getValue() const = 0;

    // If the cell is an equation, example: "=A0 + 5",
    // it is calculated in this function.
    virtual void calculateFormula(Table& table) {}

    // Returns the amount of space the cell needs to be printed
    // properly. This function is used to later decide how to,
    // align the columns in the table;
    virtual size_t cellWidth() const = 0;
};

class intCell : public Cell {
    // Cell that holds a value of type int.

    int value;
public:
    intCell(size_t x, size_t y, int value);
    Cell* dynamicCopy() override;

    void print(std::ostream& os) const override;
    std::string cellValueToStr() const override;
    double getValue() const override;
    size_t cellWidth() const override;
};

class doubleCell : public Cell {
    // Cell that holds a value of type double.

    double value;
public:
    doubleCell(size_t x, size_t y, double value);
    Cell* dynamicCopy() override;

    void print(std::ostream& os) const override;
    std::string cellValueToStr() const override;
    double getValue() const override;
    size_t cellWidth() const override;
};

class stringCell : public Cell {
    // Cell that holds a string.

    std::string str;
public:
    stringCell(size_t x, size_t y, std::string str);
    Cell* dynamicCopy() override;

    void print(std::ostream& os) const override;
    std::string cellValueToStr() const override;
    double getValue() const override;
    size_t cellWidth() const override;
};

class formulaCell : public Cell {
    // Cell for holding formulae.
    // This cell allows that every time a
    // cell that is a part of a formula changes its value,
    // the value of the equation changes;
    // For example, if we have a formula: "=A1+1",
    // the value of the cell holding the formula changes
    // every time the value of cell "A1" changes.

    std::string formula;
    double value = 0;

    void calculateFormula(Table& table) override;

public:
    formulaCell(size_t x, size_t y, std::string formula, Table& table);
    Cell* dynamicCopy() override;

    void print(std::ostream& os) const override;
    std::string cellValueToStr() const override;
    double getValue() const override;
    size_t cellWidth() const override;
};