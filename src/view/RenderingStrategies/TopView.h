//
// Created by Morrowind3 on 02/01/2022.
//

#ifndef THREEDEE_TOPVIEW_H
#define THREEDEE_TOPVIEW_H

#include <utility>
#include "RenderingStrategy.h"
#include "../../algebra/Matrix.h"

class TopView : public RenderingStrategy {
public:
    explicit TopView(SDL_Renderer* _renderer, MathsVector defaultCenter): RenderingStrategy(_renderer, defaultCenter){};
    void drawMatrix(const Matrix& matrix, const MathsVector& origin) override;
    void drawVector(const MathsVector& vector, const MathsVector& origin) override;
    void drawAxis(float width, float height, float guideMarkDistance) override;
};
#endif //THREEDEE_FRONTVIEW_H

