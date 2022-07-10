#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Expression.h"

TEST_CASE("Calculations") {
    REQUIRE(abs(Expression::get().calculate(
            "5   +   3   -   2   /   2   +   1   *   8   *   ( 0   -   5   -   3 )   *   12   +   2") - (-759)) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("8  /    (-          4) /2") - (-1)) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("-5-(-5)") - 0) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("-5-(-5*3)") - 10) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("-5-(-5*(-3*(-3-8+(4+5^(2*3))))) + 5*3^2") - (-234230)) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("5*((2*3+1*(1+8*(9-3)+(8*7^2) - (3*5+6)))+(1+8*2))") - 2215) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("5*((2*3+1*(1+8*(9-3))+(8*7^(2 + 3*(5/(75 - 35*2))) - (3*5+6)))+(1+8*2))") - 672535) < 0.00000001);
    REQUIRE(abs(Expression::get().calculate("1+2.500000-5^(2-1/(5-(-(-4))))") - (-1.5)) < 0.00000001);

    REQUIRE_THROWS_AS(abs(
            Expression::get().calculate("5*(2*3+1*(1+8*(9-3))+(8*7^(2 + 3*(5/(75 - 35*2))) - (3*5+6)))+(1+8*2))") - 672535) < 0.00000001, std::invalid_argument);
    REQUIRE_THROWS_AS(abs(
            Expression::get().calculate("5*((2*3+1*(1+8*(9-3))+(8*7^(2 + 3*(5/(75 - 35*2)) - (3*5+6)))+(1+8*2))") - 672535) < 0.00000001, std::invalid_argument);
    REQUIRE_THROWS_AS(abs(Expression::get().calculate("-5--5*3)") - 10) < 0.00000001, std::invalid_argument);
    REQUIRE_THROWS_AS(Expression::get().calculate("5*((-3)"), std::invalid_argument);
    REQUIRE_THROWS_AS(Expression::get().calculate(""), std::invalid_argument);
    REQUIRE_THROWS_AS(Expression::get().calculate("5+(-3)/(-2-2-(-2) + 2)"), std::invalid_argument);

}
