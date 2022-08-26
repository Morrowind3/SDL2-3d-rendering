#ifndef THREEDEE_MESHPANE_H
#define THREEDEE_MESHPANE_H

#include <utility>
#include <vector>
#include "../../../external/SDL2_gfx/SDL2_gfxPrimitives.h"
#include "../../algebra/MathsVector.h"

struct MeshPane {
    public:
    explicit MeshPane(const std::vector<MathsVector>& vertices) {
        for(MathsVector vector : vertices){
            xPoints.emplace_back(vector.x);
            yPoints.emplace_back(vector.y);
            zPoints.emplace_back(vector.z);
        }
    }
    std::vector<double> yPoints;
    std::vector<double> xPoints;
    std::vector<double> zPoints;
};


#endif //THREEDEE_MESHPANE_H
