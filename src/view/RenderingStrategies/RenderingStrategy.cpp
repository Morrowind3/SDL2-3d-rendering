//
// Created by Morrowind3 on 02/01/2022.
//

#include "RenderingStrategy.h"


std::vector<MathsVector> RenderingStrategy::extractVectors2D(const Matrix& matrix) {
    std::vector<MathsVector> vectors;
    vectors.reserve(matrix.getWidth());
    for(int vector = 0; vector < matrix.getWidth(); ++vector){
        vectors.emplace_back(MathsVector{matrix[vector][0], matrix[vector][1], matrix[vector][2]});
    }
    return vectors;
}


//Extracts vectors from a matrix to draw them. LastZ is used to only extract the next layer on the Z axis.
std::vector<MathsVector> RenderingStrategy::extractVectors(const Matrix& matrix, int lastZ) {
        std::vector<MathsVector> vectors;
        vectors.reserve(matrix.getWidth());

        int nextZ = std::numeric_limits<int>::max();
        for(int vector = 0; vector < matrix.getWidth(); ++vector){
            if(matrix[vector][2] > lastZ && matrix[vector][2] < nextZ){
                nextZ = matrix[vector][2];
            }
        }

        for(int vector = 0; vector < matrix.getWidth(); ++vector){
            if(matrix[vector][2] == nextZ){
                vectors.emplace_back(MathsVector{matrix[vector][0], matrix[vector][1], matrix[vector][2]});
            }
        }
        return vectors;
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

