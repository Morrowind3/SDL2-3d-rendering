#define _USE_MATH_DEFINES

#include "Camera.hpp"
#include <cmath>
#include "../input/Input.hpp"

Matrix Camera::getTransformationMatrix() const {
    MathsVector u{0, 1, 0};
    MathsVector direction = _position - _focalPoint;
    MathsVector right = u.calculateCrossProduct(direction);
    MathsVector up = direction.calculateCrossProduct(right);

    direction = direction.getUnitVector();
    right = right.getUnitVector();
    up = up.getUnitVector();

    Matrix m1{{
                      {right.x, right.y, right.z, 0},
                      {up.x, up.y, up.z, 0},
                      {direction.x, direction.y, direction.z, 0},
                      {0, 0, 0, 1}
              }};

    Transform transform;
    transform.translate({-_position.x, -_position.y, -_position.z});
    transform.apply(m1);

    return m1;
}

void Camera::move(double x, double y, double z) {
    Transform transform;
    transform.translate({x, y, z});
    Matrix positionMatrix{_position};
    transform.apply(positionMatrix);
    _position = {positionMatrix[0][0], positionMatrix[0][1], positionMatrix[0][2]};
}

Matrix Camera::getProjectionMatrix() const {
    double rad = (_fovy * (M_PI / 180));

    double scale = 1.0 / tan(rad * 0.5);

    Matrix P{{{scale, 0, 0, 0},
              {0, scale, 0, 0},
              {0, 0, -frustrumFar / (frustrumFar - frustrumNear), -1},
              {0, 0, (-frustrumFar * frustrumNear) / (frustrumFar - frustrumNear), 0}
             }};

    return P;
}

void Camera::onUpdate(const std::vector<std::shared_ptr<Entity>>& entities) {
    Input& _input = Input::getInstance();
    //translate
    bool camLeft = _input.getKey(KeyCode::LEFT);
    bool camDown = _input.getKey(KeyCode::DOWN);
    bool camUp = _input.getKey(KeyCode::UP);
    bool camRight = _input.getKey(KeyCode::RIGHT);
    bool camRaise = _input.getKey(KeyCode::PAGE_UP);
    bool camLower = _input.getKey(KeyCode::PAGE_DOWN);
    bool any = camLeft || camDown || camUp || camRight || camRaise || camLower;

    if(camLeft) move(1,0,0);
    if(camRight) move(-1,0,0);
    if(camUp) move(0,0,-1);
    if(camDown) move(0,0,1);
    if(camRaise) move(0,-1,0);
    if(camLower) move(0,1,0);


}


