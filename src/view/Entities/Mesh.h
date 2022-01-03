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
};
#endif //THREEDEE_MESH_H
