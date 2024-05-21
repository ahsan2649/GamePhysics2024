#pragma once

#include "glm/glm.hpp"

class Object {
public:
    float mass{1.0f};
    glm::vec2 velocity{0, 0};
    glm::vec2 acceleration{0, 0};
    glm::vec2 totalForce{0, 0};

    Object(float mass);
    ~Object();

    virtual void Draw() = 0;

    void AddForce(glm::vec2 force);
};
