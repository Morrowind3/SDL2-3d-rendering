//
// Created by Morrowind3 on 18/11/2021.
//

#include "MathsVector.h"

MathsVector MathsVector::operator+(const MathsVector& vector) const {
    return MathsVector{x + vector.x,y + vector.y, vector.z};

}

MathsVector MathsVector::operator-(const MathsVector& vector) const {
    return MathsVector{x - vector.x,y - vector.y, vector.z};
}

MathsVector MathsVector::operator*(const double scalar) const {
    return MathsVector{x * scalar,y * scalar, z * scalar};
}


