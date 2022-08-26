//
// Created by Morrowind3 on 18/11/2021.
//

#include "MathsVector.h"
#include <cmath>

MathsVector MathsVector::operator+(const MathsVector& vector) const {
    return MathsVector{x + vector.x,y + vector.y, vector.z};

}

MathsVector MathsVector::operator-(const MathsVector& vector) const {
    return MathsVector{x - vector.x,y - vector.y, vector.z};
}

MathsVector MathsVector::operator*(const double scalar) const {
    return MathsVector{x * scalar,y * scalar, z * scalar};
}

MathsVector MathsVector::calculateCrossProduct(MathsVector& other) const {
    return {
            (this->y * other.z) - (this->z * other.y),
            (this->z * other.x) - (this->x * other.z),
            (this->x * other.y) - (this->y * other.x)
    };
}

float MathsVector::calculateDotProduct(MathsVector& other) const {
    return (this->x * other.x) + (this->y * other.y) + (this->z* other.z);

}
float MathsVector::getLength() const {
    float a = x * x;
    float b = y * y;
    float c = z * z;
    return std::sqrt(a + b + c);
}

MathsVector MathsVector::getUnitVector() const {
    float length = getLength();
    if(length == 0) {
        return {0,0,0};
    }
    return {this->x / length, this->y / length, this->z / length};
}


