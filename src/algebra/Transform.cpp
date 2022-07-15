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
    Matrix scale { {{scalar.x, 0, 0, 0},
                           {0, scalar.y, 0, 0},
                           {0, 0, scalar.z, 0},
                           {0, 0, 0       , 1}}};
    transformationMatrix = scale * transformationMatrix;
}

void Transform::translate(const MathsVector& movement) {
    Matrix translate { {{1, 0, 0, movement.x},
                               {0, 1, 0, movement.y},
                               {0, 0, 1, movement.z},
                               {0, 0, 0, 1         }}};
    transformationMatrix = translate * transformationMatrix;
}

std::shared_ptr<Matrix> Transform::getTransformationMatrix() {
    return std::make_shared<Matrix>(transformationMatrix);
}

void Transform::rotateX(double degrees) {
    double radius = (degrees * (M_PI/180));
    Matrix rotate { {
                    {1, 0, 0, 0},
                    {0, cos(radius), -sin(radius), 0},
                    {0, sin(radius), cos(radius), 0},
                    {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}

void Transform::rotateY(double degrees) {
    double radius = (degrees * (M_PI/180));
    Matrix rotate { {
                            {cos(radius), 0, sin(radius), 0},
                            {0, 1, 0, 0},
                            {-sin(radius),0 ,cos(radius), 0},
                            {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}
void Transform::rotateZ(double degrees) {
    double radius = (degrees * (M_PI/180));
    Matrix rotate { {
                            {cos(radius), -sin(radius), 0, 0},
                            {sin(radius), cos(radius),0 , 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}

void Transform::rotateX(double degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateX(degrees);
    translate({origin.x, origin.y, origin.z});
}
void Transform::rotateY(double degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateY(degrees);
    translate({origin.x, origin.y, origin.z});
}

void Transform::rotateZ(double degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateZ(degrees);
    translate({origin.x, origin.y, origin.z});
}


