#ifndef THREEDEE_MESH_H
#define THREEDEE_MESH_H

#include <utility>
#include <numeric>

#include "../../algebra/Matrix.h"

struct Mesh {
    Mesh() = default;
    void setMatrix(Matrix matrix);
    MathsVector center {0,0,0};
    Matrix matrix {3,3};
    std::vector<int> zLayers; // The mesh will be connected on the Z-axis between each layer specified here. '4' will make 0-4 a layer, '8' 4-8 etc.
    void recalculateCentrepoint();
};
#endif //THREEDEE_MESH_H
