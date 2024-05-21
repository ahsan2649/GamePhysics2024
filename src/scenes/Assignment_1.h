#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_1 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 1"; };

    Circle circle{1, glm::vec2(0,0), 0.5};
    Line ground{glm::vec2(-2, -2), glm::vec2(2, -2)};
    float gravity{-9.81f};
};
