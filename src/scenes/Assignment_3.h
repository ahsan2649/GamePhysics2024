#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/Line.h"
#include "objects/Circle.h"

class Assignment_3 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 3"; };

    Circle circle{1, glm::vec2(0, 2), 0.5};
    Line ground{glm::vec2(-1, -3), glm::vec2(3, 4)};
    
};
