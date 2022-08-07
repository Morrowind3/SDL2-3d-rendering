#ifndef THREEDEE_WORLD_H
#define THREEDEE_WORLD_H


#include <utility>

#include "Entities/Entity.h"
#include "../view/Camera.hpp"

class World {
public:
    explicit World(std::shared_ptr<Rendering> _rendering);
    void onUpdate();
    void RenderObjects();
    void transformAll(Transform& transform);
private:
    Camera camera {{1,-30,-100}, {0,0,0}};
    std::vector<std::shared_ptr<Entity>> entities;
    std::shared_ptr<Rendering> rendering;
};


#endif //THREEDEE_WORLD_H
