//
// Created by Morrowind3 on 17/11/2021.
//

#ifndef LINALG_GRAPHPLOTTER_H
#define LINALG_GRAPHPLOTTER_H

#include <SDL_render.h>
#include "../algebra/MathsVector.h"

class GraphPlotter {
public:
    explicit GraphPlotter(SDL_Renderer* _renderer) : renderer(_renderer) { };
    void setCenter(float centerX, float centerY);
    void drawGrid(float width, float height, float dimension);
    void drawAxis(float width, float height, float guideMarkDistance);
    void drawVector(MathsVector vector);
private:
    void drawAxis(float x, float y, float width, float height, float guideMarkDistance);

    SDL_Renderer* renderer;
    float centerX = 0;
    float centerY = 0;
};


#endif //LINALG_GRAPHPLOTTER_H
