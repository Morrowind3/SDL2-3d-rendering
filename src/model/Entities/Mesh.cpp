#include <memory>
#include "Mesh.h"

void Mesh::setMatrix(Matrix _matrix) {
    matrix = std::move(_matrix);
}

void Mesh::recalculateCentrepoint() {
    auto static calculateAverage = [] (const std::vector<double>& row) {
        double avg = 0;
        for(const double& val : row){
            avg += val;
        }
        return avg / row.size();
    };

    double centerX = calculateAverage(matrix.getRow(0));
    double centerY = calculateAverage(matrix.getRow(1));
    double centerZ = calculateAverage(matrix.getRow(2));

    center = {centerX, centerY, centerZ};


}


