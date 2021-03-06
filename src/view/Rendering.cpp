#include <iostream>
#include "Rendering.h"
#include "RenderingStrategies/TopView.h"
#include "RenderingStrategies/SideView.h"

/* Geheugensteuntje
 * Matrix format
 *  x1 x2 x3 ....
 *  y1 y2 y3 ....
 *  z1 z2 z3 ....
 *  1  1  2  ....
 *
 *  Hierbij zit het volledige object in één matrix. Daarop roep je een bepaalde transformatiematrix op
 *
 *  Rendering: Elke waypoint verbind met de volgende waypoint. Laatste weer naar de eerste.
 *  Remember: Gaten in een model, vooral bij 2D, wordt vaak met een transparante texture gedaan, dus dit is prima.
 *
 */


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

void Rendering::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    renderingStrategy->drawMesh(mesh, origin);
}
void Rendering::drawMesh(const Mesh& mesh){
    renderingStrategy->drawMesh(mesh);
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

void Rendering::setColour(const std::string& colourCode) {
    int red, green, blue, alpha;
    sscanf_s(colourCode.c_str(), "%02x%02x%02x%02x", &red, &green, &blue, &alpha);
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_OPAQUE);
}






