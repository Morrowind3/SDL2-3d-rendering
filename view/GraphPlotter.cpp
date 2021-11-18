#include <iostream>
#include "GraphPlotter.h"


void GraphPlotter::drawVector(MathsVector vector) {
    int red, green, blue, alpha;
    sscanf_s(vector.getColour().c_str(), "%02x%02x%02x%02x", &red, &green, &blue, &alpha);
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);

    float centerAdjustedX = (centerX + vector.getX());
    float centerAdjustedY = (centerY - vector.getY());

    SDL_RenderDrawLineF(renderer, centerX, centerY, centerAdjustedX, centerAdjustedY);
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

