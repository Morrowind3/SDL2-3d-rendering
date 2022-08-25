//
// Created by Morrowind3 on 02/01/2022.
//

#include "RenderingStrategy.h"

//Extracts vectors from a matrix to draw them. LastZ is used to only extract the next layer on the Z axis.
std::vector<MathsVector> RenderingStrategy::extractVectors(const Matrix& matrix, int layerStart, int layerEnd) {
        std::vector<MathsVector> vectors;
        vectors.reserve(matrix.getWidth());

        for(int vector = layerStart; vector < layerEnd; ++vector){
            vectors.emplace_back(MathsVector{matrix[vector][0], matrix[vector][1], matrix[vector][2]});
        }

    return vectors;
}

void RenderingStrategy::drawMesh(const Mesh& mesh, const MathsVector& origin, char dimensionA, char dimensionB) {
    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors;
    int zLayer = 0; //zLayer is a way of grouping vectors to connect them more cleanly.
    int layerStart = 0;
    int layerEnd = mesh.zLayers[zLayer];
    while(zLayer < mesh.zLayers.size()){
        vectors  = extractVectors(mesh.matrix, layerStart, layerEnd);

        //draw Z-layer
        for(int i = 0; i < vectors.size(); ++i){
            double centerAdjustedA = origin[dimensionA] + vectors[i][dimensionA];
            double centerAdjustedB = origin[dimensionB] - vectors[i][dimensionB];
            double nextCenterAdjustedA = origin[dimensionA] + vectors[(i + 1) % vectors.size()][dimensionA];
            double nextCenterAdjustedB = origin[dimensionB] - vectors[(i+1) % vectors.size()][dimensionB];
            SDL_RenderDrawLineF(renderer, centerAdjustedA, centerAdjustedB, nextCenterAdjustedA, nextCenterAdjustedB);
        }
        //connect to last Z-layerW
        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            double centerAdjustedA = origin[dimensionA] + vectors[i % vectors.size()][dimensionA];
            double centerAdjustedB = origin[dimensionB] - vectors[i % vectors.size()][dimensionB];
            double prevCenterAdjustedA = origin[dimensionA] + prevVectors[i % prevVectors.size()][dimensionA];
            double prevCenterAdjustedB = origin[dimensionB] - prevVectors[i % prevVectors.size()][dimensionB];
            SDL_RenderDrawLineF(renderer, centerAdjustedA, centerAdjustedB, prevCenterAdjustedA, prevCenterAdjustedB);
        }
        prevVectors = vectors;
        layerStart = mesh.zLayers[zLayer++];
        layerEnd = mesh.zLayers[zLayer];

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




