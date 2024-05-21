#include "Assignment_4.h"

#include "core/Draw.h"
#include "imgui.h"

void Assignment_4::OnEnable() {
    circle1.center = glm::vec2(-1, 0);
    circle2.center = glm::vec2(1, 0);
}
void Assignment_4::OnDisable() {}

void Assignment_4::Update(float deltaTime) {
    glm::vec2 dir = circle2.center - circle1.center;

    circle1.totalForce = circle2.totalForce = glm::vec2(0);
    circle1.AddForce(dir);
    circle2.AddForce(-dir);

    circle1.acceleration = circle1.totalForce / circle1.mass;
    circle2.acceleration = circle2.totalForce / circle2.mass;

    circle1.velocity += circle1.acceleration * deltaTime;
    circle2.velocity += circle2.acceleration * deltaTime;

    circle1.center += circle1.velocity * deltaTime;
    circle2.center += circle2.velocity * deltaTime;

    if (glm::distance(circle1.center, circle2.center) <
        circle1.radius + circle2.radius) {
        circle1.center -= glm::normalize(dir) *
                          (circle1.radius + circle2.radius -
                           glm::distance(circle1.center, circle2.center));

        circle2.center -= glm::normalize(-dir) *
                          (circle1.radius + circle2.radius -
                           glm::distance(circle1.center, circle2.center));

        circle1.velocity = -circle1.velocity;
        circle2.velocity = -circle2.velocity;
    }
}

void Assignment_4::Draw() {
    circle1.Draw();
    circle2.Draw();
}

void Assignment_4::DrawGUI() {
    ImGui::Begin("Inspector");
    ImGui::End();
}
