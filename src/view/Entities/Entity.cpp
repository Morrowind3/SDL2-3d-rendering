#include "Entity.h"

void Entity::render(Rendering& rendering) {
        rendering.setColour(colour);
        rendering.setCenter(mesh.center);
        rendering.drawMatrix(mesh.matrix);
}

void Entity::transform(Transform& transform) {
    transform.apply(mesh.matrix);
}

