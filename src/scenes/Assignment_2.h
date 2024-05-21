#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_2 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 2"; };

    std::vector<Circle> circles;
    Line ground{glm::vec2(-5, -2), glm::vec2(5, -2)};
    
    glm::vec2 mouseStart, mouseEnd;
};
