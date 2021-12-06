//
// Created by Morrowind3 on 25/11/2021.
//

#include "Matrix.h"
#include "../../InvalidMatrixDimensionsException.h"

#define throwDimensionError(arg) throw InvalidMatrixDimensionsException(arg, __FILE__, __LINE__);

Matrix::Matrix(int columns, int rows) {
    resize(columns,rows);
}

Matrix Matrix::operator+(const Matrix& vector) {
    for(int c = 0; c < matrix.size(); ++c){
        for(int row = 0; row < matrix.at(c).size(); ++row){
            matrix[c][row] += vector.matrix.at(c).at(row);
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& vector) {
    for(int c = 0; c < matrix.size(); ++c){
        for(int row = 0; row < matrix.at(c).size(); ++row){
            matrix[c][row] -= vector.matrix.at(c).at(row);
        }
    }
    return *this;
}

//hele rij met hele kolom
//ga alle kolommen af, dan volgende rij

Matrix Matrix::operator*(const Matrix& _matrix) {
    if(getWidth() != _matrix.getHeight()) throwDimensionError("Multiplying Matrix of width " + std::to_string(getWidth()) + "with Matrix of height" + std::to_string(_matrix.getHeight()) );

    Matrix newMatrix{getHeight(), _matrix.getWidth()};
    for(int i = 0; i < getHeight(); ++i){
        std::vector<float> row = getRow(i);
        float rowTotal = 0;
        for(int j = 0; j < _matrix.getWidth(); ++j){
            std::vector<float> otherMatrixColumn = _matrix.matrix[i];
            int columnEntry = 0;
            for(auto val : otherMatrixColumn){
                rowTotal += row[++columnEntry]*val;
            }
            newMatrix.matrix[j][i] = rowTotal;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(const MathsVector& vector) {
    if(getWidth() != 2) throwDimensionError("Multiplying Matrix of width " + std::to_string(getWidth()) + "with vector of height 2" );

    Matrix newMatrix{getHeight(), 1};
    for(int row = 0; row < getHeight(); ++row){
        auto rowVector = getRow(row);
        float newVal = 0;
        for(float val : rowVector){
            newVal += val * vector.getX();
            newVal += val * vector.getY();
        }
        newMatrix.matrix[0][row] = newVal;
    }

    return newMatrix;
}

float& Matrix::getAt(int x, int y) {
    return matrix[y][x];
}

void Matrix::placeAt(int column, int row, float value) {
    resize(column, row);
    matrix[column][row] = value;
}

int Matrix::getWidth() const {
    matrix.size();
}

int Matrix::getHeight() const {
    matrix.at(0).size();
}

void Matrix::resize(int columns, int rows) {
    if(rows > getHeight()){
        for(auto col : matrix){
            col.resize(rows);
        }
    }
    if(columns > getWidth()){
        matrix.resize(columns, FloatVector(rows));
    }
}

std::vector<float> Matrix::getRow(int row) {
    std::vector<float> rowVector;
    for(auto& column : matrix){
        float& value = column.at(row);
        rowVector.emplace_back(value);
    }
    return rowVector;
}


