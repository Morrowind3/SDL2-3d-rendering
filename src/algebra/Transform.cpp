//
// Created by Morrowind3 on 01/01/2022.
//
#define _USE_MATH_DEFINES

#include "Transform.h"
#include <cmath>

void Transform::apply(Matrix& matrix) {
    matrix = transformationMatrix * matrix;
}

void Transform::scale(const MathsVector& scalar, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    scale(scalar);
    translate({origin.x, origin.y, origin.z});
}


void Transform::scale(const MathsVector& scalar) {
    Matrix scale { {{scalar.x, 0, 0},
                             {0, scalar.y, 0},
                             {0, 0     , 1}}};
    transformationMatrix = scale * transformationMatrix;
}

void Transform::translate(const MathsVector& movement) {
    Matrix translate { {{1, 0, movement.x},
                               {0, 1, movement.y},
                               {0, 0 , 1}}};
    transformationMatrix = translate * transformationMatrix;
}

std::shared_ptr<Matrix> Transform::getTransformationMatrix() {
    return std::make_shared<Matrix>(transformationMatrix);
}

void Transform::rotate(double degrees) {
    double radius = (degrees * (M_PI/180));
    Matrix rotate { {{cos(radius), sin(radius)*-1, 0},
                    {sin(radius), cos(radius), 0},
                    {0, 0     , 1}}};
    transformationMatrix = rotate * transformationMatrix;
}

void Transform::rotate(double degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotate(degrees);
    translate({origin.x, origin.y, origin.z});
}

