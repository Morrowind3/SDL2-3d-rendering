#ifndef LINALG_TRANSFORM_H
#define LINALG_TRANSFORM_H


#include <memory>
#include "Matrix.h"

class Transform {
public:
    Transform() = default;
    void apply(Matrix& matrix);
    void adjustTransformationMatrix(Matrix otherMatrix);

    void rotateX(float degrees, const MathsVector& origin);
    void rotateY(float degrees, const MathsVector& origin);
    void rotateZ(float degrees, const MathsVector& origin);
    void rotateX(float degrees);
    void rotateY(float degrees);
    void rotateZ(float degrees);
    void scale(const MathsVector& scalar, const MathsVector& origin);
    void scale(const MathsVector& scalar);
    void translate(const MathsVector& movement);
    std::shared_ptr<Matrix> getTransformationMatrix();
private:
    Matrix transformationMatrix { {{1, 0, 0, 0},
                                          {0, 1, 0, 0},
                                          {0, 0, 1, 0},
                                          {0, 0, 0, 1}}};

};


#endif //LINALG_TRANSFORM_H
