#include "Mesh.h"

void Mesh::setMatrix(Matrix _matrix) {
    double centerX = calculateAverage(_matrix.getRow(0));
    double centerY = calculateAverage(_matrix.getRow(1));
    double centerZ = calculateAverage(_matrix.getRow(2));

    center = {centerX, centerY, centerZ};
    matrix = std::move(_matrix);
}

double Mesh::calculateAverage(const std::vector<double>& row) {
    double avg = 0;
    for(const double& val : row){
        avg += val;
    }
    return avg / row.size();
}

