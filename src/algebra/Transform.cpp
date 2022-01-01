//
// Created by Morrowind3 on 01/01/2022.
//
#define _USE_MATH_DEFINES

#include "Transform.h"
#include <cmath>

void Transform::apply(Matrix& matrix) {
    matrix = transformationMatrix * matrix;
}

void Transform::scale(const MathsVector& scalar, float originX, float originY) {
    translate({originX*-1, originY*-1});
    scale(scalar);
    translate({originX, originY});
}


void Transform::scale(const MathsVector& scalar) {
    Matrix scale { {{scalar.getX(), 0, 0},
                             {0, scalar.getY(), 0},
                             {0, 0     , 1}}};
    transformationMatrix = scale * transformationMatrix;
}

void Transform::translate(const MathsVector& movement) {
    Matrix translate { {{1, 0, movement.getX()},
                               {0, 1, movement.getY()},
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

void Transform::rotate(double degrees, double originX, double originY) {
    translate({originX*-1, originY*-1});
    rotate(degrees);
    translate({originX, originY});
}

