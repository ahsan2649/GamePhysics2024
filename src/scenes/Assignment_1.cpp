#include "Assignment_1.h"

#include "imgui.h"

void Assignment_1::OnEnable() {}

void Assignment_1::OnDisable() {}

void Assignment_1::Update(float deltaTime) {
    circle.totalForce = glm::vec2(0,0);
    circle.AddForce(glm::vec2(0, gravity) * circle.mass);
    circle.acceleration = circle.totalForce / circle.mass;
    circle.velocity += circle.acceleration * deltaTime;
    circle.center += circle.velocity * deltaTime;

    if (glm::distance(circle.center, (ground.start + ground.end) * 0.5f) <
        circle.radius) {
        circle.velocity = -circle.velocity;
    }
}

void Assignment_1::Draw() {
    circle.Draw();
    ground.Draw();
}

void Assignment_1::DrawGUI() {
    ImGui::Begin("Inspector");
    ImGui::End();
}
