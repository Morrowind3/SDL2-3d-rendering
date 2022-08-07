#include "World.h"

#include <utility>
#include "Entities/Spaceship.h"

World::World(std::shared_ptr<Rendering> _rendering): rendering(std::move(_rendering)){
    entities.push_back(std::make_shared<Spaceship>(MathsVector{200.0,-200.0,0}, "DF00FE"));
}

void World::RenderObjects() {
    for(auto& entity: entities){
        entity->render(*rendering);
    }
}

void World::transformAll(Transform& transform) {
    for(auto& entity: entities){
            entity->transform(transform);
    }
}

void World::onUpdate() {
    for(auto& entity: entities){
        entity->onUpdate();
    }
    rendering->onUpdate();
}
