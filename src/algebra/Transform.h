#ifndef LINALG_TRANSFORM_H
#define LINALG_TRANSFORM_H


#include <memory>
#include "Matrix.h"

class Transform {
public:
    Transform() = default;
    void apply(Matrix& matrix);
    void apply(MathsVector& matrix);
    void adjustTransformationMatrix(Matrix otherMatrix);

    void rotateX(double degrees, const MathsVector& origin);
    void rotateY(double degrees, const MathsVector& origin);
    void rotateZ(double degrees, const MathsVector& origin);
    void rotateX(double degrees);
    void rotateY(double degrees);
    void rotateZ(double degrees);
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
