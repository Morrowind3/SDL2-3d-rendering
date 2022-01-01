//
// Created by Morrowind3 on 01/01/2022.
//

#ifndef LINALG_TRANSFORM_H
#define LINALG_TRANSFORM_H


#include <memory>
#include "Matrix.h"

class Transform {
public:
    Transform() = default;
    void apply(Matrix& matrix);
    std::shared_ptr<Matrix> getTransformationMatrix();
    void rotate(double degrees, double originX, double originY);
    void rotate(double degrees);
    void scale(const MathsVector& scalar, float originX, float originY);
    void scale(const MathsVector& scalar);
    void translate(const MathsVector& movement);
private:
    Matrix transformationMatrix { {{1, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}}};

};


#endif //LINALG_TRANSFORM_H
