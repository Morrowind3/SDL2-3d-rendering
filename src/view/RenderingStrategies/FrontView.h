//
// Created by Morrowind3 on 02/01/2022.
//

#ifndef THREEDEE_FRONTVIEW_H
#define THREEDEE_FRONTVIEW_H

#include <utility>
#include "RenderingStrategy.h"
#include "../../algebra/Matrix.h"

class FrontView : public RenderingStrategy {
public:
    explicit FrontView(SDL_Renderer* _renderer, MathsVector defaultCenter): RenderingStrategy(_renderer, defaultCenter){};
    void drawMesh(const Mesh& mesh, const MathsVector& origin) override;
    void drawVector(const MathsVector& vector, const MathsVector& origin) override;
    void drawAxis(float width, float height, float guideMarkDistance) override;
};
#endif //THREEDEE_FRONTVIEW_H
