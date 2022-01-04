#include <utility>

#include "Mesh.h"
#include "../../view/Rendering.h"
#include "../../algebra/Transform.h"
#include "../../input/Input.hpp"

#ifndef THREEDEE_OBJECT_H
#define THREEDEE_OBJECT_H



class Entity{
public:
    explicit Entity(std::string _colour): colour(std::move(_colour)){};
    virtual void render(Rendering& renderer);
    virtual void onUpdate() = 0;
    void transform(Transform& transform);
protected:
    Mesh mesh;
    std::string colour;
};

#endif //THREEDEE_OBJECT_H