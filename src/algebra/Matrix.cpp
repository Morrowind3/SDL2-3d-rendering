//
// Created by Morrowind3 on 25/11/2021.
//

#include "Matrix.h"

#include <utility>
#include "../../InvalidMatrixDimensionsException.h"

#define throwDimensionError(arg) throw InvalidMatrixDimensionsException(arg, __FILE__, __LINE__);

Matrix::Matrix(int columns, int rows) {
    matrix.resize(columns, FloatVector(rows));
}

Matrix::Matrix(const std::vector<FloatVector>& content) {
    matrix.resize(content.size(), FloatVector(content[0].size()));
    int column = 0;
    for(const auto& xVector : content){
        int row = 0;
        for(auto rowVal: xVector ){
            matrix[row++][column] = rowVal;
        }
        column++;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    if(getWidth() != other.getWidth() || getHeight() != other.getHeight()) throwDimensionError("Trying to add matrices with different dimensions");
    Matrix newMatrix{getWidth(), getHeight()};
    for(int c = 0; c < getWidth(); ++c){
        for(int row = 0; row < getHeight(); ++row){
            newMatrix.matrix[c][row] = matrix[c][row] + other.matrix.at(c).at(row);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(const Matrix& other) {
    if(getWidth() != other.getWidth() || getHeight() != other.getHeight()) throwDimensionError("Trying to add substract with different dimensions");

    Matrix newMatrix{getWidth(), getHeight()};
    for(int c = 0; c < matrix.size(); ++c){
        for(int row = 0; row < matrix.at(c).size(); ++row){
            newMatrix.matrix[c][row] = matrix[c][row] - other.matrix.at(c).at(row);

        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(const Matrix& _matrix) {
    if(getWidth() != _matrix.getHeight()) throwDimensionError("Multiplying Matrix of width " + std::to_string(getWidth()) + "with Matrix of height" + std::to_string(_matrix.getHeight()) );

    Matrix newMatrix{getHeight(), _matrix.getWidth()};
    for(int i = 0; i < _matrix.getWidth(); ++i)
    {
        for(int j = 0; j < getHeight(); ++j)
        {
            for(int k = 0; k < getWidth(); ++k)
            {
                newMatrix[i][j] += matrix[k][j] * _matrix[i][k];
            }
        }
    }

    return newMatrix;
}

Matrix Matrix::operator*(const MathsVector& vector) {
    if(getWidth() != 2) throwDimensionError("Multiplying Matrix of width " + std::to_string(getWidth()) + "with vector of height 2" );

    Matrix newMatrix{1, getHeight()};
    for(int row = 0; row < getHeight(); ++row){
        auto rowVector = getRow(row);
        float newVal = 0;
        newVal += rowVector[0] * vector.getX();
        newVal += rowVector[1] * vector.getY();
        newMatrix.matrix[0][row] = newVal;
    }
    return newMatrix;
}

float& Matrix::getAt(int x, int y) {
    return matrix[x][y];
}

void Matrix::placeAt(int column, int row, float value) {
    if(column+1 > getWidth()){
        resize(column+1, getHeight());
    }
    if(row+1 > getHeight()){
        resize(getWidth(), row+1);
    }

    matrix[column][row] = value;
}

int Matrix::getWidth() const {
    return matrix.size();
}

int Matrix::getHeight() const {
    return matrix.at(0).size();
}

void Matrix::resize(int columns, int rows) {
    if(columns != getWidth()){
        matrix.resize(columns, FloatVector(rows));
    } else {
        for(auto& column: matrix){
            column.resize(rows);
        }
    }
}

std::vector<float>& Matrix::operator[](int pos) {
    return matrix.at(pos);
}
std::vector<float> Matrix::operator[](int pos) const {
    return matrix[pos];
}
std::vector<float> Matrix::getRow(int row) {
    std::vector<float> rowVector;
    for(auto& column : matrix){
        float& value = column.at(row);
        rowVector.emplace_back(value);
    }
    return rowVector;
}




