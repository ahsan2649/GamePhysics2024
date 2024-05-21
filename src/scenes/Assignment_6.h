#pragma once

#include <vector>
#include "core/Simple2DScene.h"
#include "objects/AABB.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_6 : public Simple2DScene {
public:
    virtual void OnEnable() override;
    virtual void OnDisable() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void DrawGUI() override;

    virtual const char* GetName() override { return "Assignment 6"; };

    std::vector<AABB> boxes;
    std::vector<Line> walls;
    Circle circle{1, glm::vec2(0,-0.5), 0.25};
    float speed = 5;
};
