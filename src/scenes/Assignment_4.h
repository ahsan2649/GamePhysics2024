#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/Circle.h"

class Assignment_4 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 4"; };

    Circle circle1{1, glm::vec2(-1, 0), 0.5};
    Circle circle2{1, glm::vec2(1, 0), 0.5};


};
