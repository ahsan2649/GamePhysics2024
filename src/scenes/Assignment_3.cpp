#include "Assignment_3.h"

#include "imgui.h"
#include "core/Draw.h"

void Assignment_3::OnEnable() {
    circle.center = glm::vec2(0, 2);
}

void Assignment_3::OnDisable() {}

void Assignment_3::Update(float deltaTime) {
    circle.totalForce = glm::vec2(0);
    circle.AddForce(glm::vec2(0, -9.81f) * circle.mass);
    circle.acceleration = circle.totalForce / circle.mass;
    circle.velocity += circle.acceleration * deltaTime;
    circle.center += circle.velocity * deltaTime;



    glm::vec2 groundVec = ground.end - ground.start;
    glm::vec2 groundOrth = glm::normalize(glm::vec2(-groundVec.y, groundVec.x));
    float originDist = glm::dot(groundOrth, ground.end);
    float centerDist = glm::dot(groundOrth, circle.center);

    if (originDist - centerDist < circle.radius) {
        float resDist = circle.radius + (originDist - centerDist);
        circle.center += groundOrth * resDist;
    }
}

void Assignment_3::Draw() {
    
    ground.Draw();
    circle.Draw();
    Draw::Circle(glm::vec2(0), 0.05, true);
    
    glm::vec2 groundVec = ground.end - ground.start;
    glm::vec2 groundOrth = glm::normalize(glm::vec2(-groundVec.y, groundVec.x));
    float originDist = glm::dot(groundOrth, ground.end);
    float centerDist = glm::dot(groundOrth, circle.center);
    Draw::Line(circle.center, circle.center + groundOrth * (originDist - centerDist));
    
}

void Assignment_3::DrawGUI() {
    ImGui::Begin("Inspector");
    ImGui::DragFloat2("Ground Start", &ground.start[0]);
    ImGui::DragFloat2("Ground End", &ground.end[0]);
    ImGui::DragFloat2("Circle Center", &circle.center[0]);


    ImGui::End();
}
