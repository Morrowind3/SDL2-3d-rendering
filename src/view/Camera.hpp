#ifndef THREEDEE_CAMERA_H
#define THREEDEE_CAMERA_H

#include "../algebra/MathsVector.h"
#include "../algebra/Matrix.h"

class Camera {
public:
    Camera(MathsVector eye, MathsVector lookat) :  _position(eye),
                                                                      _focalPoint(lookat) {};
    Matrix getTransformationMatrix() const;
    Matrix getProjectionMatrix() const;
    Matrix getCameraMatrix() const { return getProjectionMatrix() * getTransformationMatrix();};
    double frustrumNear = 0.1;
    double frustrumFar = 1000;

    void onUpdate();
    void move(double x, double y, double z);
private:
    MathsVector _position;
    MathsVector _focalPoint;


    double _fovy = 100;
};


#endif //THREEDEE_CAMERA_H
