//
// Created by Morrowind3 on 03/01/2022.
//

#ifndef THREEDEE_WORLD_H
#define THREEDEE_WORLD_H


#include <utility>

#include "Entities/Entity.h"

class World {
public:
    explicit World(std::shared_ptr<Rendering> _rendering);
    void RenderObjects();
    void transformAll(Transform& transform);
private:
    std::vector<Entity> entities;
    std::shared_ptr<Rendering> rendering;
};


#endif //THREEDEE_WORLD_H
