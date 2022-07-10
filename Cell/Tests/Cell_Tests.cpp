#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Cell.h"
#include "Table.h"

TEST_CASE("Position tests")
{
    REQUIRE(Position::convertPositionToName(2, 5) == std::string("C5"));
    REQUIRE(Position::convertPositionToName(4, 25) == std::string("E25"));
    REQUIRE(Position::convertPositionToName(10, 155) == std::string("K155"));

    Position position = Position::convertNameToPosition("K155");
    REQUIRE(position.getX() == 10);
    REQUIRE(position.getY() == 155);

    position = Position::convertNameToPosition("E25");
    REQUIRE(position.getX() == 4);
    REQUIRE(position.getY() == 25);
}

TEST_CASE("Int Cell")
{
    intCell iCell(5, 2, 56);

    REQUIRE(iCell.cellWidth() == 2);
    REQUIRE(abs(iCell.getValue() - 56.0) < 0.000000001);
    REQUIRE(iCell.cellValueToStr() == "56");
    REQUIRE(iCell.getX() == 5);
    REQUIRE(iCell.getY() == 2);
}

TEST_CASE("Double Cell")
{
    doubleCell dCell(8, 3, -15.5);

    REQUIRE(dCell.cellWidth() == 5);
    REQUIRE(abs(dCell.getValue() - (-15.5)) < 0.000000001);
    REQUIRE(dCell.cellValueToStr() == "-15.500000");
    REQUIRE(dCell.getX() == 8);
    REQUIRE(dCell.getY() == 3);
}

TEST_CASE("String Cell")
{
    stringCell strCell(5, 0, "Hello world");

    REQUIRE(strCell.cellWidth() == 11);
    REQUIRE(abs(strCell.getValue() - 0.0) < 0.000000001);
    REQUIRE(strCell.cellValueToStr() == "Hello world");
    REQUIRE(strCell.getX() == 5);
    REQUIRE(strCell.getY() == 0);
}

TEST_CASE("Formula cell")
{
    Table t1(5);
    t1.editCell("F1", "=A1 + A2");

    t1.editCell("A1", 5.0);
    t1.editCell("A2", -3.5);

    REQUIRE(abs(t1.at(5, 1)->getValue() - 1.5) < 0.000000001);

    t1.editCell("A1", "Hello");

    REQUIRE(abs(t1.at(5, 1)->getValue() - (-3.5))< 0.000000001);

    t1.editCell("A2", 123.2);

    REQUIRE(abs(t1.at(5, 1)->getValue() - 123.2) < 0.000000001);
}