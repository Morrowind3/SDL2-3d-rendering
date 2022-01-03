#ifndef THREEDEE_RENDERING_H
#define THREEDEE_RENDERING_H

#include <SDL_render.h>
#include "../algebra/MathsVector.h"
#include "../algebra/Matrix.h"
#include "RenderingStrategies/RenderingStrategy.h"
#include "RenderingStrategies/FrontView.h"

class Rendering {
public:
    enum Perspective{
        TOP, FRONT, SIDE
    };

    explicit Rendering(SDL_Renderer* _renderer) : renderer(_renderer) { };

    void setColour(const std::string& colourCode);
    void setPerspective (Perspective perspective);
    void setCenter(const MathsVector& center);
    void drawGrid(float width, float height, float dimension);
    void drawAxis(float width, float height, float guideMarkDistance);
    void drawVector(const MathsVector& vector);
    void drawVector(const MathsVector& vector, const MathsVector& origin);
    void drawMatrix(const Matrix& matrix);
    void drawMatrix(const Matrix& matrix, const MathsVector& origin);

private:
    MathsVector center{0,0,0};
    SDL_Renderer* renderer;
    std::unique_ptr<RenderingStrategy> renderingStrategy = std::make_unique<FrontView>(FrontView{renderer, center});
};


#endif //THREEDEE_RENDERING_H
