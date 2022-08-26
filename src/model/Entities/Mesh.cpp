#include <memory>
#include <algorithm>
#include "Mesh.h"
#include <climits>
#include <iostream>

void Mesh::recalculateCentrepoint() {
    float minX, minY, minZ, maxX, maxY, maxZ;
    minX = minY = minZ = SDL_MAX_SINT16;
    maxX = maxY = maxZ = SDL_MIN_SINT16;
    for(const MeshPane& pane : meshPanes){
        for(float val: pane.xPoints){
            if(val < minX){
                minX = val;
            }
            if(val > maxX){
                maxX = val;
            }
        }
        for(float val: pane.yPoints){
            if(val < minY ){
                minY = val;
            }
            if(val > maxY){
                maxY = val;
            }
        }
        for(float val: pane.zPoints){
            if(val < minZ){
                minZ = val;
            }
            if(val > maxZ){
                maxZ = val;
            }
        }
    }

    float centerX = (minX + maxX) / 2;
    float centerY = (minY + maxY) / 2;
    float centerZ = (minZ + maxZ) / 2;
    center = {centerX, centerY, centerZ};
}

void Mesh::transform(Transform& t) {

    std::vector<MeshPane> newPanes;
    for(MeshPane pane : meshPanes){
        std::vector<MathsVector> newVertices;

        for(int i = 0; i < pane.xPoints.size(); ++i) {
            Matrix m{1, 4};
            m[0][0] = pane.xPoints[i];
            m[0][1] = pane.yPoints[i];
            m[0][2] = pane.zPoints[i];
            m[0][3] = 1;

            t.apply(m);
            newVertices.emplace_back(MathsVector{m[0][0], m[0][1], m[0][2]});
        }
        newPanes.emplace_back(newVertices);
    }
    meshPanes = newPanes;
}


