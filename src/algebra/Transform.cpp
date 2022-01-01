//
// Created by Morrowind3 on 01/01/2022.
//

#include "Transform.h"

void Transform::apply(Matrix& matrix) {
    matrix = transformationMatrix * matrix;
}

void Transform::scaleFrom(const MathsVector& scalar, float originX, float originY) {
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

