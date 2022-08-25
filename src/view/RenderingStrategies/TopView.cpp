#include "TopView.h"
#include <limits>

void TopView::drawVector(const MathsVector& vector, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    double centerAdjustedX = origin.x + vector.x;
    double centerAdjustedZ = origin.z - vector.z;

    SDL_RenderDrawLineF(renderer, origin.x, origin.z, centerAdjustedX, centerAdjustedZ);
}

void TopView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    RenderingStrategy::drawMesh(mesh, origin, 'x', 'z');
}

void TopView::drawAxis(float width, float height, float guideMarkDistance) {
    RenderingStrategy::drawAxis(centerX, centerZ, width, height, guideMarkDistance);
}
