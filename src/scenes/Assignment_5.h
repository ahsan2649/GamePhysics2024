#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/AABB.h"

class Assignment_5 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 5"; };

    Circle circle{1, glm::vec2(0,0), 1};
    AABB box{glm::vec2(1,1), glm::vec2(2,2)};
    float boxToCircleDist{0.0f};
};
