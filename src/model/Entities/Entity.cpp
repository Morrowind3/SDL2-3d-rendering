#include "Entity.h"

void Entity::render(Rendering& rendering) {
    rendering.setColour(colour);
    rendering.drawMesh(mesh);
}

void Entity::transform(Transform& transform) {
    transform.apply(mesh.matrix);
}

