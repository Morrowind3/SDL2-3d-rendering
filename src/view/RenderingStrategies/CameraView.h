#ifndef THREEDEE_CAMERAVIEW_H
#define THREEDEE_CAMERAVIEW_H


#include "RenderingStrategy.h"
#include "../Camera.hpp"

class CameraView : public RenderingStrategy {
public:
    explicit CameraView(SDL_Renderer* _renderer, MathsVector defaultCenter): RenderingStrategy(_renderer, defaultCenter){};
    void drawMesh(const Mesh& mesh, const MathsVector& origin) override;
    void drawVector(const MathsVector& vector, const MathsVector& origin) override {}; //unsupported
    void drawAxis(float width, float height, float guideMarkDistance) override {}; // unsupported
private:
    float postCalculationsXAxis(const Matrix& matrix);
    float postCalculationsYAxis(const Matrix& matrix);
    Camera camera {{10,-30,400}, {9,15,0}};

    bool pointIsInFrustrum(double point) const;
};


#endif //THREEDEE_CAMERAVIEW_H
