#include "SideView.h"
#include <limits>


void SideView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    RenderingStrategy::drawMesh(mesh, origin, 'z', 'y');
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
