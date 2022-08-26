#include <cmath>
#include <iostream>
#include "CameraView.h"

void CameraView::drawMesh(const Mesh& mesh, const MathsVector& origin) {

}

bool CameraView::pointIsInFrustrum(double point) const{
    return point >= camera.frustrumNear && point <= camera.frustrumFar;
}

float CameraView::postCalculationsXAxis(const Matrix& matrix) {
    return 20.0f + (matrix[0][0]/ matrix[0][3]) * 20;
}

float CameraView::postCalculationsYAxis(const Matrix& matrix) {
    return 20.0f + (matrix[0][1] / matrix[0][3]) * 20;
}

void CameraView::onUpdate() {
    camera.onUpdate();
}

