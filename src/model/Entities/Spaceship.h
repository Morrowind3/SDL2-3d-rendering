#ifndef THREEDEE_SPACESHIP_H
#define THREEDEE_SPACESHIP_H


#include "Entity.h"
#include "../../view/Rendering.h"

class Spaceship : public Entity {
public:
    Spaceship(const MathsVector& pos, std::string _colour);
    void onUpdate() override;
private:
    void handleInput();
};


#endif //THREEDEE_SPACESHIP_H
