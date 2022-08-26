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
                           {0, 0, 0,        1}}};
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

void Transform::rotateX(float degrees) {
    float radius = (degrees * (M_PI/180));
    Matrix rotate { {
                    {1, 0, 0, 0},
                    {0, cosf(radius), -sinf(radius), 0},
                    {0, sinf(radius), cosf(radius), 0},
                    {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}

void Transform::rotateY(float degrees) {
    float radius = (degrees * (M_PI/180));
    Matrix rotate { {
                            {cosf(radius), 0, sinf(radius), 0},
                            {0, 1, 0, 0},
                            {-sinf(radius),0 ,cosf(radius), 0},
                            {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}
void Transform::rotateZ(float degrees) {
    float radius = (degrees * (M_PI/180));
    Matrix rotate { {
                            {cosf(radius), -sinf(radius), 0, 0},
                            {sinf(radius), cosf(radius),0 , 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1}}};
    transformationMatrix = rotate * transformationMatrix;
}

void Transform::rotateX(float degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateX(degrees);
    translate({origin.x, origin.y, origin.z});
}
void Transform::rotateY(float degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateY(degrees);
    translate({origin.x, origin.y, origin.z});
}

void Transform::rotateZ(float degrees, const MathsVector& origin) {
    translate({origin.x*-1, origin.y*-1, origin.z*-1});
    rotateZ(degrees);
    translate({origin.x, origin.y, origin.z});
}

void Transform::adjustTransformationMatrix(Matrix otherMatrix) {
    transformationMatrix = otherMatrix * transformationMatrix;
}


