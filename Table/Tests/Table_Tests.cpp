#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Table.h"

TEST_CASE("Add cell") {
    Table t1(1);
    REQUIRE_NOTHROW(t1.editCell("A0", "Hello"));
    REQUIRE(t1.at(0, 0)->cellValueToStr() == "Hello");
    REQUIRE_NOTHROW(t1.editCell("C3", 5));
    REQUIRE(abs(t1.at(2, 3)->getValue() - 5.0) < 0.000001);
    REQUIRE_NOTHROW(t1.editCell("E8", 4.58));
    REQUIRE(abs(t1.at(4, 8)->getValue() - 4.58) < 0.000001);
    REQUIRE_NOTHROW(t1.editCell("D3", "world"));
    REQUIRE(t1.at(3, 3)->cellValueToStr() == "world");

    REQUIRE_THROWS_AS(t1.editCell("f3", "error"), std::invalid_argument);

    REQUIRE_NOTHROW(t1.editCell("A0", 1));
    REQUIRE(abs(t1.at(0, 0)->getValue() - 1.0) < 0.00001);
    REQUIRE_NOTHROW(t1.editCell("A0", 2.5));
    REQUIRE(abs(t1.at(0, 0)->getValue() - 2.5) < 0.00001);
    REQUIRE_NOTHROW(t1.editCell("A0", "hello"));
    REQUIRE(t1.at(0, 0)->cellValueToStr() == "hello");
    REQUIRE_NOTHROW(t1.editCell("A0", 2));
    REQUIRE(abs(t1.at(0, 0)->getValue() - 2) < 0.00001);
}

TEST_CASE("Copy constructor and copy assigment operator")
{
    Table t1(1);
    REQUIRE_NOTHROW(t1.editCell("A0", "Hello"));
    REQUIRE_NOTHROW(t1.editCell("C3", 5));
    REQUIRE_NOTHROW(t1.editCell("E8", 4.58));
    REQUIRE_NOTHROW(t1.editCell("D3", "world"));

    Table t2(1);
    t2 = t1;

    REQUIRE(t2.at(0,0)->cellValueToStr() == "Hello");
    REQUIRE(t1.at(0,0)->cellValueToStr() == "Hello");

    REQUIRE(abs(t2.at(2, 3)->getValue() - 5.0) < 0.00001);
    REQUIRE(abs(t1.at(2, 3)->getValue() - 5.0) < 0.00001);

    REQUIRE(abs(t2.at(4, 8)->getValue() - 4.58) < 0.00001);
    REQUIRE(abs(t1.at(4, 8)->getValue() - 4.58) < 0.00001);

    REQUIRE(t2.at(3, 3)->cellValueToStr() == "world");
    REQUIRE(t1.at(3, 3)->cellValueToStr() == "world");


    Table t3(t1);

    REQUIRE(t3.at(0,0)->cellValueToStr() == "Hello");
    REQUIRE(t1.at(0,0)->cellValueToStr() == "Hello");

    REQUIRE(abs(t3.at(2, 3)->getValue() - 5.0) < 0.00001);
    REQUIRE(abs(t1.at(2, 3)->getValue() - 5.0) < 0.00001);

    REQUIRE(abs(t3.at(4, 8)->getValue() - 4.58) < 0.00001);
    REQUIRE(abs(t1.at(4, 8)->getValue() - 4.58) < 0.00001);

    REQUIRE(t3.at(3, 3)->cellValueToStr() == "world");
    REQUIRE(t1.at(3, 3)->cellValueToStr() == "world");
}

TEST_CASE("Move constructor and move assigment operator")
{
    Table t1(1);
    REQUIRE_NOTHROW(t1.editCell("A0", "Hello"));
    REQUIRE_NOTHROW(t1.editCell("C3", 5));
    REQUIRE_NOTHROW(t1.editCell("E8", 4.58));
    REQUIRE_NOTHROW(t1.editCell("D3", "world"));

    Table t2(1);
    t2 = std::move(t1);

    REQUIRE(t2.at(0,0)->cellValueToStr() == "Hello");
    REQUIRE(abs(t2.at(2, 3)->getValue() - 5.0) < 0.00001);
    REQUIRE(abs(t2.at(4, 8)->getValue() - 4.58) < 0.00001);
    REQUIRE(t2.at(3, 3)->cellValueToStr() == "world");

    Table t3(std::move(t2));
    REQUIRE(t3.at(0,0)->cellValueToStr() == "Hello");
    REQUIRE(abs(t3.at(2, 3)->getValue() - 5.0) < 0.00001);
    REQUIRE(abs(t3.at(4, 8)->getValue() - 4.58) < 0.00001);
    REQUIRE(t3.at(3, 3)->cellValueToStr() == "world");
}
