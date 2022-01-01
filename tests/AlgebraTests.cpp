#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/algebra/MathsVector.h"
#include "../src/algebra/Matrix.h"

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
    Matrix A { {{3, 2, 6},
                       {12, -3, 23},
                       {-5, 10, -13}}};
    Matrix B {{{3, -7, 23},
                      {2, 12, -3},
                      {15,18, 53}}};

    SECTION("Add"){
        Matrix C = A + B;
        REQUIRE(C.getAt(0, 0) == 6);
        REQUIRE(C.getAt(1, 0) == -5);
        REQUIRE(C.getAt(2, 0) == 29);

        REQUIRE(C.getAt(0, 1) == 14);
        REQUIRE(C.getAt(1, 1) == 9);
        REQUIRE(C.getAt(2, 1) == 20);

        REQUIRE(C.getAt(0, 2) == 10);
        REQUIRE(C.getAt(1, 2) == 28);
        REQUIRE(C.getAt(2, 2) == 40);
    }
    SECTION("substract"){
        Matrix C = A - B;
        REQUIRE(C.getAt(0, 0) == 0);
        REQUIRE(C.getAt(1, 0) == 9);
        REQUIRE(C.getAt(2, 0) == -17);

        REQUIRE(C.getAt(0, 1) == 10);
        REQUIRE(C.getAt(1, 1) == -15);
        REQUIRE(C.getAt(2, 1) == 26);

        REQUIRE(C.getAt(0, 2) == -20);
        REQUIRE(C.getAt(1, 2) == -8);
        REQUIRE(C.getAt(2, 2) == -66);

        C = B - A;
        REQUIRE(C.getAt(0, 0) == 0);
        REQUIRE(C.getAt(1, 0) == -9);
        REQUIRE(C.getAt(2, 0) == 17);

        REQUIRE(C.getAt(0, 1) == -10);
        REQUIRE(C.getAt(1, 1) == 15);
        REQUIRE(C.getAt(2, 1) == -26);

        REQUIRE(C.getAt(0, 2) == 20);
        REQUIRE(C.getAt(1, 2) == 8);
        REQUIRE(C.getAt(2, 2) == 66);
    }
    SECTION("Multiple with matrix - same size"){
        Matrix C = A * B;
        REQUIRE((C.getHeight() == 3 && C.getWidth() == 3));
        REQUIRE(C.getAt(0, 0) == 103);
        REQUIRE(C.getAt(0, 1) == 375);
        REQUIRE(C.getAt(0, 2) == -190);

        REQUIRE(C.getAt(1, 0) == 111);
        REQUIRE(C.getAt(1, 1) == 294);
        REQUIRE(C.getAt(1, 2) == -79);

        REQUIRE(C.getAt(2,0) == 381);
        REQUIRE(C.getAt(2, 1) == 1504);
        REQUIRE(C.getAt(2, 2) == -834);

        C = B * A;
        REQUIRE(C.getAt(0, 0) == -190);
        REQUIRE(C.getAt(0, 1) == 165);
        REQUIRE(C.getAt(0, 2) == -4);

        REQUIRE(C.getAt(1, 0) == 257);
        REQUIRE(C.getAt(1, 1) == -62);
        REQUIRE(C.getAt(1, 2) == 506);

        REQUIRE(C.getAt(2,0) == -442);
        REQUIRE(C.getAt(2, 1) == 327);
        REQUIRE(C.getAt(2, 2) == -185);
    }
    SECTION("Multiple with matrix - different size"){
        A.placeAt(0, 3, 40);
        A.placeAt(1, 3, 5);
        A.placeAt(2, 3, 99);

        B.placeAt(3, 0, 10);
        B.placeAt(3, 1, -3);
        B.placeAt(3, 2, 3);

        Matrix C = A * B;
        REQUIRE((C.getHeight() == 4 && C.getWidth() == 4));
        REQUIRE(C.getAt(0, 0) == -190);
        REQUIRE(C.getAt(1, 0) == 257);
        REQUIRE(C.getAt(2, 0) == -442);
        REQUIRE(C.getAt(3, 0) == 120);

        REQUIRE(C.getAt(0, 1) == 165);
        REQUIRE(C.getAt(1, 1) == -62);
        REQUIRE(C.getAt(2, 1) == 327);
        REQUIRE(C.getAt(3, 1) == -25);

        REQUIRE(C.getAt(0, 2) == -4);
        REQUIRE(C.getAt(1, 2) == 506);
        REQUIRE(C.getAt(2, 2) == -185);
        REQUIRE(C.getAt(3, 2) == 255);

        REQUIRE(C.getAt(0, 3) == -315);
        REQUIRE(C.getAt(1, 3) == 1055);
        REQUIRE(C.getAt(2, 3) == -932);
        REQUIRE(C.getAt(3, 3) == 682);

        C = B * A;
        REQUIRE((C.getHeight() == 3 && C.getWidth() == 3));
        REQUIRE(C.getAt(0, 0) == 503);
        REQUIRE(C.getAt(1, 0) == 161);
        REQUIRE(C.getAt(2, 0) == 1371);

        REQUIRE(C.getAt(0, 1) == 255);
        REQUIRE(C.getAt(1, 1) == 279);
        REQUIRE(C.getAt(2, 1) == 1207);

        REQUIRE(C.getAt(0, 2) == -70);
        REQUIRE(C.getAt(1, 2) == -64);
        REQUIRE(C.getAt(2, 2) == -537);
    }
    SECTION("Multiply with vector"){
        MathsVector V{1,4};
        A.resize(2, 3);
        Matrix C = A * V;
        REQUIRE((C.getHeight() == 3 && C.getWidth() == 1));
        REQUIRE(C.getAt(0, 0) == 11);
        REQUIRE(C.getAt(0, 1) == 0);
        REQUIRE(C.getAt(0, 2) == 35);
    }
}

TEST_CASE("Transformation"){

}