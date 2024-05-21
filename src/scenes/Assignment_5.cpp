#include "Assignment_5.h"

#include "imgui.h"
#include "core/Draw.h"
#include <iostream>

void Assignment_5::OnEnable() {}

void Assignment_5::OnDisable() {}

void Assignment_5::Update(float deltaTime) {
    glm::vec2 closestPoint{
        glm::clamp(circle.center.x, box.A.x, box.B.x),
        glm::clamp(circle.center.y, box.A.y, box.B.y),
    };
}

void Assignment_5::Draw() {
    circle.Draw();

    glm::vec2 closestPoint{glm::clamp(circle.center.x, box.A.x, box.B.x),
           glm::clamp(circle.center.y, box.A.y, box.B.y),
    };

    if (!(glm::distance(circle.center, closestPoint) < circle.radius)) {
       box.Draw();
        
    }

    Draw::Circle(closestPoint, 0.05, true);
    Draw::PositionHandle(circle.center);
    Draw::Arrow(circle.center, closestPoint);

}

void Assignment_5::DrawGUI() {
    ImGui::Begin("Inspector");
    
    ImGui::End();
}
