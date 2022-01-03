//
// Created by Morrowind3 on 03/01/2022.
//

#ifndef THREEDEE_SPACESHIP_H
#define THREEDEE_SPACESHIP_H


#include "Entity.h"
#include "../Rendering.h"

class Spaceship : public Entity {
public:
    Spaceship(const MathsVector& pos, std::string _colour);
private:
};


#endif //THREEDEE_SPACESHIP_H
