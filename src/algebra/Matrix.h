//
// Created by Morrowind3 on 25/11/2021.
//

#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H


#include "MathsVector.h"
#include <vector>

using FloatVector = std::vector<double>;

class Matrix {
public:
    Matrix(int columns, int rows);
    Matrix(MathsVector vector); //NOLINT  implicit conversion intentional.
    explicit Matrix(const std::vector<FloatVector>& content);

    Matrix operator+ (const Matrix& vector) const;
    Matrix operator- (const Matrix& vector);
    Matrix operator* (const Matrix& other);
    MathsVector operator* (const MathsVector& vector); //Can return both a Matrix and a vector thanks to implicit conversion. 
    std::vector<double>& operator[](int pos);
    std::vector<double> operator[](int pos) const;
    void placeAt(int column, int row, double value);
    double& getAt(int x, int y);
    int getWidth() const;
    int getHeight() const;
    void resize(int columns, int rows);
    std::vector<double> getRow(int row);
private:
    std::vector<FloatVector> matrix;
};


#endif //LINALG_MATRIX_H

