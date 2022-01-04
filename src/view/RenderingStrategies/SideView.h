//
// Created by Morrowind3 on 02/01/2022.
//

#include "RenderingStrategy.h"

#ifndef THREEDEE_SIDEVIEW_H
class SideView : public RenderingStrategy {
public:
    explicit SideView(SDL_Renderer* _renderer, MathsVector defaultCenter): RenderingStrategy(_renderer, defaultCenter){};
    void drawMesh(const Mesh& matrix, const MathsVector& origin) override;
    void drawVector(const MathsVector& vector, const MathsVector& origin) override;
    void drawAxis(float width, float height, float guideMarkDistance) override;
};
#define THREEDEE_SIDEVIEW_H

#endif //THREEDEE_SIDEVIEW_H
