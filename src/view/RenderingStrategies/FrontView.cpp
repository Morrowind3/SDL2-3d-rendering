#include "FrontView.h"
#include <limits>

void FrontView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerY, width, height, guideMarkDistance);
}

void FrontView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
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
            double centerAdjustedY = origin.y - vectors[i].y;
            double nextCenterAdjustedX = origin.x + vectors[(i+1) % vectors.size()].x;
            double nextCenterAdjustedY = origin.y - vectors[(i+1) % vectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjustedY, nextCenterAdjustedX, nextCenterAdjustedY);
        }
        //connect to last Z-layer
        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedX = origin.x + vectors[i % vectors.size()].x;
            double centerAdjustedY = origin.y - vectors[i % vectors.size()].y;
            double prevCenterAdjustedX = origin.x + prevVectors[i % prevVectors.size()].x;
            double prevCenterAdjustedY = origin.y - prevVectors[i % prevVectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjustedY, prevCenterAdjustedX, prevCenterAdjustedY);
        }
        prevVectors = vectors;
        layerStart = mesh.zLayers[zLayer++];
        layerEnd = mesh.zLayers[zLayer];
    }

}

void FrontView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    float centerAdjustedX = origin.x + vector.x;
    float centerAdjustedY = origin.y - vector.y;

    SDL_RenderDrawLineF(renderer, origin.x, origin.y, centerAdjustedX, centerAdjustedY);
}

