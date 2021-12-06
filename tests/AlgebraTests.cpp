#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/algebra/MathsVector.h"

TEST_CASE("Vectors"){
    MathsVector A {3, 9};
    MathsVector B{4, 10};
    SECTION("Add"){
        MathsVector C = A + B;
        REQUIRE(C.getX() == 7);
        REQUIRE(C.getY() == 19);
    }
    SECTION("Substract"){
        MathsVector C = A - B;
        REQUIRE(C.getX() == -1);
        REQUIRE(C.getY() == -1);
        C = B - A;
        REQUIRE(C.getX() == 1);
        REQUIRE(C.getY() == 1);
    }
    SECTION("Multiply with Scalar"){
        MathsVector C = A * 4;
        REQUIRE(C.getX() == 12);
        REQUIRE(C.getY() == 36);
    }
}

TEST_CASE("Matrices"){
    SECTION("Add"){
        REQUIRE(true); //Assertion
    }
    SECTION("substract"){
        REQUIRE(true); //Assertion
    }
    SECTION("Multiple with matrix"){
        REQUIRE(true); //Assertion
    }
    SECTION("Multiply with vector"){
        REQUIRE(true); //Assertion
    }
}
