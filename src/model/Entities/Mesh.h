#ifndef THREEDEE_MESH_H
#define THREEDEE_MESH_H

#include <utility>
#include <numeric>

#include "../../algebra/Matrix.h"
#include "../../algebra/Transform.h"
#include "MeshPane.h"

struct Mesh {
    Mesh() = default;
    MathsVector center {0,0,0};
    void recalculateCentrepoint(); //TODO: I don't think this one is working perfectly
    void addPane(const std::vector<MathsVector>& meshPane){
        meshPanes.emplace_back(meshPane);
    };
    void transform(Transform& t);
    std::vector<MeshPane> meshPanes;

    int r, g, b, a;
};
#endif //THREEDEE_MESH_H
