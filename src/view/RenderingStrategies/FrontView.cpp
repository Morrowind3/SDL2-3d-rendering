#include "FrontView.h"
#include <limits>

void FrontView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerY, width, height, guideMarkDistance);
}

void FrontView::drawMatrix(const Matrix& matrix, const MathsVector& origin) {
    std::shared_ptr<double> lastZIndex = std::make_unique<double>(std::numeric_limits<double>::lowest());

    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors = extractVectors(matrix, lastZIndex);

    while(!vectors.empty()){
        for(int i = 0; i < vectors.size(); ++i){
            double centerAdjustedX = origin.x + vectors[i].x;
            double centerAdjustedY = origin.y - vectors[i].y;
            double nextCenterAdjustedX = origin.x + vectors[(i+1) % vectors.size()].x;
            double nextCenterAdjustedY = origin.y - vectors[(i+1) % vectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjustedY, nextCenterAdjustedX, nextCenterAdjustedY);
        }

        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedX = origin.x + vectors[i % vectors.size()].x;
            double centerAdjustedY = origin.y - vectors[i % vectors.size()].y;
            double prevCenterAdjustedX = origin.x + prevVectors[i % prevVectors.size()].x;
            double prevCenterAdjustedY = origin.y - prevVectors[i % prevVectors.size()].y;
            SDL_RenderDrawLineF(renderer, centerAdjustedX, centerAdjustedY, prevCenterAdjustedX, prevCenterAdjustedY);
        }
        prevVectors = vectors;
        vectors = extractVectors(matrix, lastZIndex);
    }

}

void FrontView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    float centerAdjustedX = origin.x + vector.x;
    float centerAdjustedY = origin.y - vector.y;

    SDL_RenderDrawLineF(renderer, origin.x, origin.y, centerAdjustedX, centerAdjustedY);
}

