#include <cmath>
#include <iostream>
#include "CameraView.h"

void CameraView::drawMesh(const Mesh& mesh, const MathsVector& origin) {
    std::vector<MathsVector> prevVectors;
    std::vector<MathsVector> vectors;
    int zLayer = 0; //zLayer is a way of grouping vectors to connect them more cleanly.
    int layerStart = 0;
    int layerEnd = mesh.zLayers[zLayer];
    while(zLayer < mesh.zLayers.size()){
        vectors  = extractVectors(mesh.matrix, layerStart, layerEnd);

        //draw Z-layer
        for(int i = 0; i < vectors.size(); ++i){
            Matrix cameraMatrix = camera.getCameraMatrix();
            Matrix matrixPoint = cameraMatrix* vectors[i];
            Matrix nextMatrixPoint = cameraMatrix * vectors[(i+1) % vectors.size()];;

            if (!pointIsInFrustrum(matrixPoint[0][3]) && !pointIsInFrustrum(nextMatrixPoint[0][3])){
                return;
            }
            float x1 = postCalculationsXAxis(matrixPoint);
            float y1 = postCalculationsYAxis(matrixPoint);
            float x2 = postCalculationsXAxis(nextMatrixPoint);
            float y2 = postCalculationsYAxis(nextMatrixPoint);

            SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
        }
        //connect to last Z-layerW
        for(int i = 0; i < prevVectors.size() && !vectors.empty(); ++i){
            Matrix nextMatrixPoint = camera.getCameraMatrix() * vectors[i % vectors.size()];
            Matrix prevMatrixPoint = camera.getCameraMatrix() * prevVectors[i % prevVectors.size()];

            if (!pointIsInFrustrum(nextMatrixPoint[0][3]) && !pointIsInFrustrum(prevMatrixPoint[0][3])){
                return;
            }
            float x1 = postCalculationsXAxis(nextMatrixPoint);
            float y1 = postCalculationsYAxis(nextMatrixPoint);
            float x2 = postCalculationsXAxis(prevMatrixPoint);
            float y2 = postCalculationsYAxis(prevMatrixPoint);

            SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
        }
        prevVectors = vectors;
        layerStart = mesh.zLayers[zLayer++];
        layerEnd = mesh.zLayers[zLayer];
    }
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

