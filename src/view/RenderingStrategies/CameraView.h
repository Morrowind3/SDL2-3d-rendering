#ifndef THREEDEE_CAMERAVIEW_H
#define THREEDEE_CAMERAVIEW_H


#include <utility>

#include "RenderingStrategy.h"
#include "../Camera.hpp"

class CameraView : public RenderingStrategy {
public:
    explicit CameraView(SDL_Renderer* _renderer, MathsVector defaultCenter): RenderingStrategy(_renderer, defaultCenter){};
    void drawMesh(const Mesh& mesh, const MathsVector& origin) override;
    void drawVector(const MathsVector& vector, const MathsVector& origin) override {}; //unimplemented
    void drawAxis(float width, float height, float guideMarkDistance) override {}; //unimplemented
    void onUpdate() override;
private:
    static float postCalculationsXAxis(const Matrix& matrix);
    static float postCalculationsYAxis(const Matrix& matrix);
    Camera camera {{10, -30, 400}, {0, 15, 0}};
    bool pointIsInFrustrum(double point) const;
};


#endif //THREEDEE_CAMERAVIEW_H
