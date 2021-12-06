//
// Created by Morrowind3 on 18/11/2021.
//

#include "MathsVector.h"

MathsVector MathsVector::operator+(const MathsVector& vector) const {
    return MathsVector{x + vector.x,y + vector.y};

}

MathsVector MathsVector::operator-(const MathsVector& vector) const {
    return MathsVector{x - vector.x,y - vector.y};
}

MathsVector MathsVector::operator*(const float scalar) const {
    return MathsVector{x * scalar,y * scalar};
}

float MathsVector::getX() const {
    return x;
}

float MathsVector::getY() const {
    return y;
}

std::string MathsVector::getColour() {
    return colour;
}
