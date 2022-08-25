#include "FrontView.h"

void FrontView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerY, width, height, guideMarkDistance);
}


void FrontView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    RenderingStrategy::drawMesh(mesh, origin, 'x', 'y');
}

void FrontView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    float centerAdjustedX = origin.x + vector.x;
    float centerAdjustedY = origin.y - vector.y;

    SDL_RenderDrawLineF(renderer, origin.x, origin.y, centerAdjustedX, centerAdjustedY);
}

