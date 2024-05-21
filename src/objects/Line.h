#pragma once
#include "Object.h"
class Line : public Object {
public:
    glm::vec2 start{-2,0};
    glm::vec2 end{2, 0};

    Line(glm::vec2 start, glm::vec2 end);
    virtual void Draw() override;

};
