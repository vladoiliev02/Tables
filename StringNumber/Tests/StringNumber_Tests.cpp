#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "StringNumber.h"

TEST_CASE("String is a number")
{
    REQUIRE(StringNumber::isNumber("1") == true);
    REQUIRE(StringNumber::isNumber("1.5") == true);
    REQUIRE(StringNumber::isNumber("-1.85") == true);
    REQUIRE(StringNumber::isNumber("1123456789548984.225") == true);
    REQUIRE(StringNumber::isNumber("-18784654136164.256849") == true);

    REQUIRE(StringNumber::isNumber("a") == false);
    REQUIRE(StringNumber::isNumber("18784654136164.a5649") == false);
    REQUIRE(StringNumber::isNumber("-1878465413616a.256849") == false);
}

TEST_CASE("String is double")
{
    REQUIRE(StringNumber::isDouble("123.5") == true);
    REQUIRE(StringNumber::isDouble("-154.25") == true);
    REQUIRE(StringNumber::isDouble("456") == false);
}

TEST_CASE("String is unsigned")
{
    REQUIRE(StringNumber::isUnsigned("456") == true);
    REQUIRE(StringNumber::isUnsigned("-456") == false);
    REQUIRE(StringNumber::isUnsigned("45.6") == false);
}