#include "Mesh.h"

void Mesh::setMatrix(Matrix _matrix) {
    double centerX, centerY, centerZ;
    centerX = centerY = centerZ = 0;

    for(double& val : _matrix.getRow(0)){
        centerX += val;
    }
    for(double& val : _matrix.getRow(1)){
        centerY += val;
    }
    for(double& val : _matrix.getRow(2)){
        centerZ += val;
    }

    center = {centerX, centerY, centerZ};
    matrix = std::move(_matrix);
}

