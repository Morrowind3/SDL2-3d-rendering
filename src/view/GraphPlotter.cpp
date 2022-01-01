#include <iostream>
#include <utility>
#include "GraphPlotter.h"
#include "../algebra/Matrix.h"

/* Geheugensteuntje
 * Matrix format
 *  x1 x2 x3 ....
 *  y1 y2 y3 ....
 *  1  1  1
 *
 *  Hierbij zit het volledige object in één matrix. Daarop roep je een bepaalde transformatiematrix op
 *
 *  Rendering: Elke waypoint verbind met de volgende waypoint. Laatste weer naar de eerste.
 *  Remember: Gaten in een model, vooral bij 2D, wordt vaak met een transparante texture gedaan, dus dit is prima.
 *
 */


void GraphPlotter::drawMatrix(const Matrix& matrix){
    drawMatrix(matrix, MathsVector{centerX, centerY});
}

void GraphPlotter::drawMatrix(const Matrix& matrix, const MathsVector& origin) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    std::vector<MathsVector> vectors = extractVectors(matrix);

    for(int i = 1; i < vectors.size(); ++i){
        float prevCenterAdjustedX = origin.getX() + vectors[i-1].getX();
        float prevCenterAdjustedY = origin.getY() - vectors[i-1].getY();
        float centerAdjustedX = origin.getX() + vectors[i].getX();
        float centerAdjustedY = origin.getY() - vectors[i].getY();
        SDL_RenderDrawLineF(renderer, prevCenterAdjustedX, prevCenterAdjustedY, centerAdjustedX, centerAdjustedY);
    }
    //connect last with first
    SDL_RenderDrawLineF(renderer, origin.getX() + vectors[vectors.size()-1].getX(),
                        origin.getY() - vectors[vectors.size()-1].getY(),
                        origin.getX() + vectors[0].getX(),
                        origin.getY() - vectors[0].getY());
}



void GraphPlotter::drawVector(MathsVector vector, const MathsVector& origin) {
    int red, green, blue, alpha;
    sscanf_s(vector.getColour().c_str(), "%02x%02x%02x%02x", &red, &green, &blue, &alpha);
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);

    float centerAdjustedX = origin.getX() + vector.getX();
    float centerAdjustedY = origin.getY() - vector.getY();

    SDL_RenderDrawLineF(renderer, origin.getX(), origin.getY(), centerAdjustedX, centerAdjustedY);
}

void GraphPlotter::drawVector(MathsVector vector) {
    drawVector(std::move(vector), MathsVector{centerX, centerY});
}

void GraphPlotter::drawAxis(float width, float height, float guideMarkDistance) {
    drawAxis(centerX, centerY, width, height, guideMarkDistance);
}

void GraphPlotter::drawAxis(float x, float y, float width, float height, float guideMarkDistance) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawLineF(renderer, x, y, x, y+height);
    SDL_RenderDrawLineF(renderer, x, y, x, y-height);
    SDL_RenderDrawLineF(renderer, x, y, x+width, y);
    SDL_RenderDrawLineF(renderer, x, y, x-width, y);
    //guide marks
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    if(guideMarkDistance > 0){
        for(int i  = 1; i < width/guideMarkDistance; ++i){
            //horizontal
            float offset = guideMarkDistance*i;
            SDL_RenderDrawLineF(renderer, x-offset, y, x-offset, y+10);
            SDL_RenderDrawLineF(renderer, x-offset, y, x-offset, y-10);
            SDL_RenderDrawLineF(renderer, x+offset, y, x+offset, y+10);
            SDL_RenderDrawLineF(renderer, x+offset, y, x+offset, y-10);
        }
        for(int i  = 1; i < height/guideMarkDistance; ++i){
            //vertical
            float offset = guideMarkDistance*i;
            SDL_RenderDrawLineF(renderer, x, y-offset, x+10, y-offset);
            SDL_RenderDrawLineF(renderer, x, y-offset, x-10, y-offset);
            SDL_RenderDrawLineF(renderer, x, y+offset, x+10, y+offset);
            SDL_RenderDrawLineF(renderer, x, y+offset, x-10, y+offset);
        }
    }
}

void GraphPlotter::drawGrid(float cellWidth, float cellHeight, float dimension) {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

    for(int i = 0; i < dimension / cellWidth; ++i){
        SDL_RenderDrawLineF(renderer, cellWidth*i, 0, cellWidth*i, dimension);
    }
    for(int i = 0; i < dimension / cellHeight; ++i){
        SDL_RenderDrawLineF(renderer, 0, cellHeight*i, dimension, cellHeight * i);
    }
}

void GraphPlotter::setCenter(float x, float y) {
    centerX = x;
    centerY = y;
}

std::vector<MathsVector> GraphPlotter::extractVectors(const Matrix& matrix) {
    std::vector<MathsVector> vectors;
    vectors.reserve(matrix.getWidth());
    for(int vector = 0; vector < matrix.getWidth(); ++vector){
        vectors.emplace_back(MathsVector{matrix[vector][0], matrix[vector][1]});
    }
    return vectors;
}


