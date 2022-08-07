#include <utility>
#include <string>
#include "../../view/Rendering.h"
#include "../../algebra/Transform.h"

#ifndef THREEDEE_OBJECT_H
#define THREEDEE_OBJECT_H

class Entity {
public:
    explicit Entity(std::string _colour): colour(std::move(_colour)){};
    virtual void render(Rendering& renderer);
    virtual void onUpdate() = 0;

    virtual void transform(Transform& transform);
protected:
    Mesh mesh;
    std::string colour;
};

#endif //THREEDEE_OBJECT_H