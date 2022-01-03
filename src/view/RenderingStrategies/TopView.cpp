#include "TopView.h"
#include <limits>

void TopView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    double centerAdjustedX = origin.x + vector.x;
    double centerAdjustedZ = origin.z - vector.z;

    SDL_RenderDrawLineF(renderer, origin.x, origin.z, centerAdjustedX, centerAdjustedZ);
}

void TopView::drawMatrix(const Matrix& matrix, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    double lastZ = std::numeric_limits<double>::lowest();
    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors = extractVectors(matrix, lastZ);

    while(!vectors.empty()){
        vectors = extractVectors(matrix, lastZ);
        lastZ = vectors.empty() ? 0 : vectors[0].z;

        for(int i = 0; i < vectors.size(); ++i){
            double centerAdjustedX = origin.x + vectors[i].x;
            double centerAdjustedZ = origin.z - vectors[i].z;
            double nextCenterAdjustedX = origin.x + vectors[(i+1) % vectors.size()].x;
            double nextCenterAdjustedZ = origin.z - vectors[(i+1) % vectors.size()].z;
            SDL_RenderDrawLineF(renderer, nextCenterAdjustedX, nextCenterAdjustedZ, centerAdjustedX, centerAdjustedZ);
        }

        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedX = origin.x + vectors[i % vectors.size()].x;
            double centerAdjestedZ = origin.z - vectors[i % vectors.size()].z;
            double prevCenterAdjustedX = origin.x + prevVectors[i % prevVectors.size()].x;
            double prevCenterAdjustedZ = origin.z - prevVectors[i % prevVectors.size()].z;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjestedZ, prevCenterAdjustedX, prevCenterAdjustedZ);
        }
        prevVectors = vectors;
    }
}

void TopView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerZ, width, height, guideMarkDistance);
}
