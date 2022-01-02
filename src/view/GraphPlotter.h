//
// Created by Morrowind3 on 17/11/2021.
//

#ifndef LINALG_GRAPHPLOTTER_H
#define LINALG_GRAPHPLOTTER_H

#include <SDL_render.h>
#include "../algebra/MathsVector.h"
#include "../algebra/Matrix.h"

class GraphPlotter {
public:
    explicit GraphPlotter(SDL_Renderer* _renderer) : renderer(_renderer) { };
    void setCenter(MathsVector center);
    void drawGrid(float width, float height, float dimension);
    void drawAxis(float width, float height, float guideMarkDistance);
    void drawVector(MathsVector vector);
    void drawVector(MathsVector vector, const MathsVector& origin);
    void drawMatrix(const Matrix& matrix);
    void drawMatrix(const Matrix& matrix, const MathsVector& origin);

private:
    void drawAxis(float x, float y, float width, float height, float guideMarkDistance);
    static std::vector<MathsVector> extractVectors(const Matrix& matrix);

    SDL_Renderer* renderer;
    double centerX = 0;
    double centerY = 0;
    double centerZ = 0;
};


#endif //LINALG_GRAPHPLOTTER_H
