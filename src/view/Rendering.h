#ifndef THREEDEE_RENDERING_H
#define THREEDEE_RENDERING_H

#include <SDL_render.h>

#include <utility>
#include "../algebra/MathsVector.h"
#include "../algebra/Matrix.h"
#include "RenderingStrategies/RenderingStrategy.h"
#include "Camera.hpp"

class Rendering {
public:
    enum Perspective{
        TOP, FRONT, SIDE, CAMERA
    };

    explicit Rendering(SDL_Renderer* _renderer) : renderer(_renderer){};
    void setColour(const std::string& colourCode);
    void setPerspective (Perspective perspective);
    void setCenter(const MathsVector& center);
    void drawGrid(float width, float height, float dimension);
    void drawAxis(float width, float height, float guideMarkDistance);
    void drawVector(const MathsVector& vector);
    void drawVector(const MathsVector& vector, const MathsVector& origin);
    void drawMesh(const Mesh& mesh);
    void drawMesh(const Mesh& mesh, const MathsVector& origin);
    void onUpdate();

private:
    MathsVector center{0,0,0};
    SDL_Renderer* renderer;
    std::unique_ptr<RenderingStrategy> renderingStrategy;
};


#endif //THREEDEE_RENDERING_H
