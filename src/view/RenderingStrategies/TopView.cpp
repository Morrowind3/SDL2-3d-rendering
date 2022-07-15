#include "TopView.h"
#include <limits>

void TopView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    double centerAdjustedX = origin.x + vector.x;
    double centerAdjustedZ = origin.z - vector.z;

    SDL_RenderDrawLineF(renderer, origin.x, origin.z, centerAdjustedX, centerAdjustedZ);
}

void TopView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors;
    int zLayer = 0;
    int layerStart = 0;
    int layerEnd = mesh.zLayers[zLayer];

    while(zLayer < mesh.zLayers.size()){
        vectors  = extractVectors(mesh.matrix, layerStart, layerEnd);
        //draw Z-layer
        for(int i = 0; i < vectors.size(); ++i){
            double centerAdjustedX = origin.x + vectors[i].x;
            double centerAdjustedZ = origin.z - vectors[i].z;
            double nextCenterAdjustedX = origin.x + vectors[(i+1) % vectors.size()].x;
            double nextCenterAdjustedZ = origin.z - vectors[(i+1) % vectors.size()].z;
            SDL_RenderDrawLineF(renderer, nextCenterAdjustedX, nextCenterAdjustedZ, centerAdjustedX, centerAdjustedZ);
        }

        //connect to last Z-layer
        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedX = origin.x + vectors[i % vectors.size()].x;
            double centerAdjustedZ = origin.z - vectors[i % vectors.size()].z;
            double prevCenterAdjustedX = origin.x + prevVectors[i % prevVectors.size()].x;
            double prevCenterAdjustedZ = origin.z - prevVectors[i % prevVectors.size()].z;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjustedZ, prevCenterAdjustedX, prevCenterAdjustedZ);
        }
        prevVectors = vectors;
        layerStart = mesh.zLayers[zLayer++];
        layerEnd = mesh.zLayers[zLayer];
    }
}

void TopView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerZ, width, height, guideMarkDistance);
}
