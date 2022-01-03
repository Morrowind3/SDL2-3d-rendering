#ifndef THREEDEE_RENDERINGSTRATEGY_H
#define THREEDEE_RENDERINGSTRATEGY_H


#include <SDL_render.h>
#include <memory>
#include <utility>
#include "../../algebra/Matrix.h"

class RenderingStrategy {
public:
    RenderingStrategy(SDL_Renderer* _renderer, MathsVector defaultCenter = {0,0,0}): renderer(_renderer), centerX(defaultCenter.x), centerY(defaultCenter.y), centerZ(defaultCenter.z){};
    virtual void drawMatrix(const Matrix& matrix, const MathsVector& origin) = 0;
    void drawMatrix(const Matrix& matrix){ drawMatrix(matrix, {centerX, centerY, centerZ});};
    virtual void drawVector(const MathsVector& vector, const MathsVector& origin) = 0;
    void drawVector(const MathsVector& vector){ drawVector(vector, {centerX, centerY, centerZ});};
    virtual void drawAxis(float width, float height, float guideMarkDistance) = 0;
    void setCenter(const MathsVector& center);
protected:
    SDL_Renderer* renderer;
    static std::vector<MathsVector> extractVectors(const Matrix& matrix, double lastZ);
    static std::vector<MathsVector> extractVectors2D(const Matrix& matrix);
    double centerX = 0;
    double centerY = 0;
    double centerZ = 0;
    void drawAxis(float a, float b, float width, float height, float guideMarkDistance);
};


#endif //THREEDEE_RENDERINGSTRATEGY_H
