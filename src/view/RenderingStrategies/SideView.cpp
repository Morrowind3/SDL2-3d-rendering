#include "SideView.h"
#include <limits>

//TODO: Side view still has cross-connected lines
void SideView::drawMatrix(const Matrix& matrix, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    double lastZ = std::numeric_limits<double>::min();
    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors = extractVectors(matrix, lastZ);

    while(!vectors.empty()){
        vectors = extractVectors(matrix, lastZ);
        lastZ = vectors.empty() ? 0 : vectors[0].z;

        for(int i = 0; i < vectors.size(); ++i){
            double centerAdjustedZ = origin.z + vectors[i].z;
            double centerAdjustedY = origin.y - vectors[i].y;
            double nextCenterAdjustedZ = origin.z + vectors[(i + 1) % vectors.size()].z;
            double nextCenterAdjustedY = origin.y - vectors[(i + 1) % vectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedZ, centerAdjustedY, nextCenterAdjustedZ, nextCenterAdjustedY);
        }
        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedZ = origin.z + vectors[i % vectors.size()].z;
            double centerAdjustedY = origin.y - vectors[i % vectors.size()].y;
            double prevCenterAdjustedZ = origin.z + prevVectors[i % prevVectors.size()].z;
            double prevCenterAdjustedY = origin.y - prevVectors[i % prevVectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedZ, centerAdjustedY, prevCenterAdjustedZ, prevCenterAdjustedY);
        }
        prevVectors = vectors;
    }
}

void SideView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    float centerAdjustedZ = origin.z + vector.z;
    float centerAdjustedY = origin.y - vector.y;

    SDL_RenderDrawLineF(renderer, origin.z, origin.y, centerAdjustedZ, centerAdjustedY);
}

void SideView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerZ, centerY, width, height, guideMarkDistance);
}
