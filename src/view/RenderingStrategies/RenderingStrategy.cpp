//
// Created by Morrowind3 on 02/01/2022.
//

#include <iostream>
#include "RenderingStrategy.h"
#include "../../../external/SDL2_gfx/SDL2_gfxPrimitives.h"

//Extracts vectors from a matrix to draw them. LastZ is used to only extract the next layer on the Z axis.
std::vector<MathsVector> RenderingStrategy::extractVectors(const Matrix& matrix, int layerStart, int layerEnd) {
        std::vector<MathsVector> vectors;
        vectors.reserve(matrix.getWidth());

        for(int vector = layerStart; vector < layerEnd; ++vector){
            vectors.emplace_back(MathsVector{matrix[vector][0], matrix[vector][1], matrix[vector][2]});
        }
    return vectors;
}

//TODO: Still account for Z!
void RenderingStrategy::drawMesh(const Mesh& mesh, const MathsVector& origin, char dimensionA, char dimensionB) {
    Uint8 origRed,origGreen,origBlue,origAlpha;
    SDL_GetRenderDrawColor(renderer,
                           &origRed, &origGreen, &origBlue,
                           &origAlpha);


    for(MeshPane pane: mesh.meshPanes){
        aaFilledPolygonRGBA(renderer, &pane.xPoints[0], &pane.yPoints[0], pane.xPoints.size(), mesh.r, mesh.g, mesh.b, mesh.a);
    }
}

void RenderingStrategy::drawAxis(float a, float b, float width, float height, float guideMarkDistance) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawLineF(renderer, a, b, a, b + height);
    SDL_RenderDrawLineF(renderer, a, b, a, b - height);
    SDL_RenderDrawLineF(renderer, a, b, a + width, b);
    SDL_RenderDrawLineF(renderer, a, b, a - width, b);
    //guide marks
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    if(guideMarkDistance > 0){
        for(int i  = 1; i < width/guideMarkDistance; ++i){
            //horizontal
            float offset = guideMarkDistance*i;
            SDL_RenderDrawLineF(renderer, a - offset, b, a - offset, b + 10);
            SDL_RenderDrawLineF(renderer, a - offset, b, a - offset, b - 10);
            SDL_RenderDrawLineF(renderer, a + offset, b, a + offset, b + 10);
            SDL_RenderDrawLineF(renderer, a + offset, b, a + offset, b - 10);
        }
        for(int i  = 1; i < height/guideMarkDistance; ++i){
            //vertical
            float offset = guideMarkDistance*i;
            SDL_RenderDrawLineF(renderer, a, b - offset, a + 10, b - offset);
            SDL_RenderDrawLineF(renderer, a, b - offset, a - 10, b - offset);
            SDL_RenderDrawLineF(renderer, a, b + offset, a + 10, b + offset);
            SDL_RenderDrawLineF(renderer, a, b + offset, a - 10, b + offset);
        }
    }
}

void RenderingStrategy::setCenter(const MathsVector& center) {
    centerX = center.x;
    centerY = center.y;
    centerZ = center.z;
}

void RenderingStrategy::onUpdate() {

}




