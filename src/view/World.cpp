#include "World.h"

#include <utility>
#include "Entities/Spaceship.h"

World::World(std::shared_ptr<Rendering> _rendering): rendering(std::move(_rendering)){
    Entity ship = Spaceship{{40.0,40.0,40.0}, "DF00FE"};

    entities.push_back(ship);
}

void World::RenderObjects() {
    for(auto& entity: entities){
        entity.render(*rendering);
    }
}

void World::transformAll(Transform& transform) {
        for(auto& entity: entities){
            entity.transform(transform);
        }
}
