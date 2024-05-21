#pragma once
#include "Object.h"

class Circle : public Object {
public:
    float radius{1};
    glm::vec2 center{0, 0};

    Circle(float mass, glm::vec2 center, float radius);

    virtual void Draw() override;
};
