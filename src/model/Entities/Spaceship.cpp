#include "Spaceship.h"

#include <utility>
#include <iostream>

Spaceship::Spaceship(const MathsVector& pos, std::string _colour): Entity(std::move(_colour)) {
    Matrix matrix { {
                       {30, 50, 50, 30, 30, 50, 50, 30, 45, 35},
                       {50, 50, 30, 30, 50, 50, 30, 30, 30, 30},
                       {10, 10, 10, 10, 40, 40, 40, 40, 70, 70},
                       {1,   1,  1,  1,  1,  1,  1, 1, 1, 1}}};

    mesh.setMatrix(std::move(matrix));
    mesh.zLayers = {4, 8, 10};

    Transform t;
    t.translate(pos);
    t.apply(mesh.matrix);
}

void Spaceship::onUpdate() {
    handleInput();
}

void Spaceship::handleInput(){
    Input& _input = Input::getInstance();
    Transform t;

    //translate
    bool moveUp = _input.getKey(KeyCode::W);
    bool moveLeft =_input.getKey(KeyCode::A);
    bool moveDown = _input.getKey(KeyCode::S);
    bool moveRight = _input.getKey(KeyCode::D);
    bool moveForward = _input.getKey(KeyCode::E);
    bool moveBackward = _input.getKey(KeyCode::Q);

    //scale
    bool biggerX = _input.getKey(KeyCode::NUMPAD_6);
    bool smallerX =_input.getKey(KeyCode::NUMPAD_4);
    bool biggerY = _input.getKey(KeyCode::NUMPAD_8);
    bool smallerY = _input.getKey(KeyCode::NUMPAD_2);
    bool biggerZ = _input.getKey(KeyCode::NUMPAD_9);
    bool smallerZ = _input.getKey(KeyCode::NUMPAD_7);

    //rotate
    bool rotateX = _input.getKey(KeyCode::X);
    bool rotateY = _input.getKey(KeyCode::C);
    bool rotateZ = _input.getKey(KeyCode::Z);
    bool inverseRotation = _input.getKey(KeyCode::LSHIFT);

    if(biggerX)  t.scale({1.1,1,1});
    if(smallerX) t.scale({0.9,1,1});
    if(biggerY) t.scale({1,1.1,1});
    if(smallerY) t.scale({1,0.9,1});
    if(biggerZ) t.scale({1,1, 1.1});
    if(smallerZ) t.scale({1,1,0.9});

    if(moveUp)  t.translate({0, 1, 0});
    if(moveDown) t.translate({0,-1,0});
    if(moveLeft) t.translate({-1,0,0});
    if(moveRight) t.translate({1,0,0});
    if(moveForward) t.translate({0,0, 1});
    if(moveBackward) t.translate({0,0,-1});

    int rotationSpeed = 1;
    if(inverseRotation) rotationSpeed *= -1;
    if(rotateX)  t.rotateX(rotationSpeed, mesh.center);
    if(rotateY) t.rotateY(rotationSpeed, mesh.center);
    if(rotateZ) t.rotateZ(rotationSpeed, mesh.center);

    t.apply(mesh.matrix);
    mesh.recalculateCentrepoint();
}

