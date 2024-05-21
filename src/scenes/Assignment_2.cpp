#include "Assignment_2.h"
#include "core/Draw.h"
#include "imgui.h"

void Assignment_2::OnEnable() {
    circles.insert(circles.begin(), Circle(1, glm::vec2(0, 0), 0.5));
    circles.insert(circles.begin(), Circle(2, glm::vec2(3, 0), 0.5));
    circles.insert(circles.begin(), Circle(3, glm::vec2(-4, 0), 0.5));
}

void Assignment_2::OnDisable() {
    circles.clear();
}

void Assignment_2::Update(float deltaTime) {
    if (Input::IsMouseClicked(0)) {
        mouseStart = Input::GetMousePos();
    }

    if (Input::IsMouseDown(0)) {
        mouseEnd = Input::GetMousePos();
    }

    if (Input::IsMouseReleased(0)) {
        mouseEnd = Input::GetMousePos();
    }

    for (auto& circle : circles) {
        circle.totalForce = glm::vec2(0, 0);
        circle.AddForce(glm::vec2(0, -9.81f) * circle.mass);
        if (Input::IsMouseReleased(0) &&
            glm::distance(mouseStart, circle.center) < circle.radius) {
            circle.AddForce((mouseEnd - mouseStart) * 1000.0f);
        }
        circle.acceleration = circle.totalForce / circle.mass;
        circle.velocity += circle.acceleration * deltaTime;
        if (glm::distance(circle.center,
                          glm::vec2(circle.center.x, ground.end.y)) <
            circle.radius) {
            circle.velocity = glm::vec2(0, 0);
            circle.center += glm::vec2(0, 0.01f);
        }
        circle.center += circle.velocity * deltaTime;
    }
}

void Assignment_2::Draw() {
    ground.Draw();
    for (auto& circle : circles) {
        circle.Draw();

        if (Input::IsMouseDown(0) &&
            glm::distance(mouseStart, circle.center) < circle.radius) {
            
            glm::vec2 u = mouseEnd - mouseStart;
            u = u ;
            
            
            for (int i = 0; i < 10; i++) {
                float step = i * 0.1;
                glm::vec2 pos = circle.center + u * float(step) +
                                0.5f * glm::vec2(0, -9.81f) * float(step * step);

                Draw::Circle(pos, circle.radius);
            }
            

        }
    }

    if (Input::IsMouseDown(0)) {
        Draw::Arrow(mouseStart, mouseEnd);
    }
}

void Assignment_2::DrawGUI() {
    ImGui::Begin("Inspector");
    ImGui::End();
}
