#include "Spaceship.h"
#include "../../input/Input.hpp"

#include <utility>
#include <iostream>

Spaceship::Spaceship(const MathsVector& pos, std::string _colour): Entity(std::move(_colour)) {
    std::vector<MathsVector> noseLeft, noseRight, noseBottom;
    std::vector<MathsVector> bodyLeft, bodyRight, bodyBottom;
    std::vector<MathsVector> tailLeft, tailRight, tailBottom, tailFin, rear;

    noseLeft = std::vector<MathsVector> {{0,0,50}, {25,25,50},{25,0,-10}};
    noseRight = std::vector<MathsVector> {{25,25,50}, {25,0,-10},{50,0,50}};
    noseBottom = std::vector<MathsVector> {{25,0,-10}, {0,0,50},{50,0,50}};

    bodyLeft = std::vector<MathsVector> {{0,0,50}, {0,0,100},{25,25,100},{25,25,50}};
    bodyRight = std::vector<MathsVector> {{50,0,50}, {50,0,100},{25,25,100},{25,25,50}};
    bodyBottom = std::vector<MathsVector> {{0,0,50}, {50,0,50}, {50, 0, 100}, {0,0,100}};

    tailLeft = std::vector<MathsVector> {{0,0,100}, {25,25,100},{-25,0,125}};
    tailRight = std::vector<MathsVector> {{50,0,100}, {25,25,100},{75,0,125}};
    tailBottom = std::vector<MathsVector> {{0,0,100}, {-25,0,125}, {75,0,125},{50,0,100}};
    rear = std::vector<MathsVector> {{-25,0,125}, {25,25,100}, {75,0,125}};
    tailFin = std::vector<MathsVector> {{25,25,100}, {25,50,100},{25,25,80}};

    mesh.addPane(noseLeft);
    mesh.addPane(noseRight);
    mesh.addPane(noseBottom);
    mesh.addPane(bodyLeft);
    mesh.addPane(bodyRight);
    mesh.addPane(bodyBottom);
    mesh.addPane(tailLeft);
    mesh.addPane(tailRight);
    mesh.addPane(tailBottom);
    mesh.addPane(rear);
    mesh.addPane(tailFin);
    mesh.r = 5;
    mesh.g = 195;
    mesh.b = 222;
    mesh.a = 150;

    Transform t;
    t.translate(pos);
    t.scale({3,3,3},pos);
    mesh.transform(t);
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

    if(moveUp)  t.translate({0, -1, 0});
    if(moveDown) t.translate({0,1,0});
    if(moveLeft) t.translate({-1,0,0});
    if(moveRight) t.translate({1,0,0});
    if(moveForward) t.translate({0,0, 1});
    if(moveBackward) t.translate({0,0,-1});

    float rotationSpeed = 1;
    if(inverseRotation) rotationSpeed *= -1;
    if(rotateX)  t.rotateX(rotationSpeed, mesh.center);
    if(rotateY) t.rotateY(rotationSpeed, mesh.center);
    if(rotateZ) t.rotateZ(rotationSpeed, mesh.center);

    mesh.transform(t);
    mesh.recalculateCentrepoint();
}

