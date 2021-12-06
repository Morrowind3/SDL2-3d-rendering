//
// Created by Morrowind3 on 25/11/2021.
//

#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H


#include "MathsVector.h"
#include <vector>

using FloatVector = std::vector<float>;

class Matrix {
public:
    Matrix(int columns, int rows);
    Matrix operator+ (const Matrix& vector);
    Matrix operator- (const Matrix& vector);
    Matrix operator* (const Matrix& matrix);
    Matrix operator* (const MathsVector& vector);
    void placeAt(int column, int row, float value);
    float& getAt(int x, int y);
    int getWidth() const;
    int getHeight() const;
    void resize(int columns, int rows);
private:
    std::vector<float> getRow(int row);
    std::vector<FloatVector> matrix;
};


#endif //LINALG_MATRIX_H

