#pragma once
#include "Object.h"
class AABB : public Object {
public:
    glm::vec2 A{-1,-1};
    glm::vec2 B{1, 1};

    AABB(glm::vec2 A, glm::vec2 B);
    ~AABB(){};
    glm::vec2 GetCenter();
    virtual void Draw() override;
};
