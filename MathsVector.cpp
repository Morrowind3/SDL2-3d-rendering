//
// Created by Morrowind3 on 18/11/2021.
//

#include "MathsVector.h"

MathsVector MathsVector::operator+(const MathsVector& vector) {
    return MathsVector(x + vector.x, y + vector.y);
}

MathsVector MathsVector::operator-(const MathsVector& vector) {
    return MathsVector(x - vector.x, y - vector.y);
}

MathsVector MathsVector::operator*(const float scalar) {
    return MathsVector(x*scalar, y*scalar);
}

float MathsVector::getX() {
    return x;
}

float MathsVector::getY() {
    return y;
}

std::string MathsVector::getColour() {
    return colour;
}
