#include <iostream>
#include <utility>
#include "Rendering.h"
#include "../algebra/Matrix.h"
#include "RenderingStrategies/TopView.h"
#include "RenderingStrategies/SideView.h"

/* Geheugensteuntje
 * Matrix format
 *  x1 x2 x3 ....
 *  y1 y2 y3 ....
 *  z1 z2 z3 ....
 *  1  1  1
 *
 *  Hierbij zit het volledige object in één matrix. Daarop roep je een bepaalde transformatiematrix op
 *
 *  Rendering: Elke waypoint verbind met de volgende waypoint. Laatste weer naar de eerste.
 *  Remember: Gaten in een model, vooral bij 2D, wordt vaak met een transparante texture gedaan, dus dit is prima.
 *
 */

//    int red, green, blue, alpha;
//    sscanf_s(vector.getColour().c_str(), "%02x%02x%02x%02x", &red, &green, &blue, &alpha);


void Rendering::drawGrid(float cellWidth, float cellHeight, float dimension) {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

    for(int i = 0; i < dimension / cellWidth; ++i){
        SDL_RenderDrawLineF(renderer, cellWidth*i, 0, cellWidth*i, dimension);
    }
    for(int i = 0; i < dimension / cellHeight; ++i){
        SDL_RenderDrawLineF(renderer, 0, cellHeight*i, dimension, cellHeight * i);
    }
}


void Rendering::setCenter(const MathsVector& _center) {
    center = _center;
    renderingStrategy->setCenter(center);
}

void Rendering::drawVector(const MathsVector& vector, const MathsVector& origin) {
    renderingStrategy->drawVector(vector, origin);
}
void Rendering::drawVector(const MathsVector& vector) {
    renderingStrategy->drawVector(vector);
}

void Rendering::drawMatrix(const Matrix& matrix, const MathsVector& origin) {
    renderingStrategy->drawMatrix(matrix, origin);
}
void Rendering::drawMatrix(const Matrix& matrix){
    renderingStrategy->drawMatrix(matrix);
}

void Rendering::setPerspective(Rendering::Perspective perspective) {
    switch(perspective){
        case TOP: renderingStrategy = std::make_unique<TopView>(TopView{renderer, center});
            break;
        case FRONT: renderingStrategy = std::make_unique<FrontView>(FrontView{renderer, center});
            break;
        case SIDE:  renderingStrategy = std::make_unique<SideView>(SideView{renderer, center});
            break;
    }

}

void Rendering::drawAxis(float width, float height, float guideMarkDistance) {
    renderingStrategy->drawAxis(width, height, guideMarkDistance);
}






