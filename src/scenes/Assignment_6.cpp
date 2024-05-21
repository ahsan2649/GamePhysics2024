#include "Assignment_6.h"

#include "core/Draw.h"
#include "imgui.h"

void Assignment_6::OnEnable() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            boxes.insert(boxes.begin(),
                         AABB(glm::vec2(0 - 2.5 + 1 * i, 1 + 1 * j),
                              glm::vec2(1 - 2.5 + 1 * i, 1.625 + 1 * j)));
        }
    }

    walls.insert(walls.begin(), Line(glm::vec2(-4, 6), glm::vec2(-4, -2)));
    walls.insert(walls.begin(), Line(glm::vec2(4, 6), glm::vec2(4, -2)));
    walls.insert(walls.begin(), Line(glm::vec2(-4, 6), glm::vec2(4, 6)));
    walls.insert(walls.begin(), Line(glm::vec2(-4, -2), glm::vec2(4, -2)));

    circle.center = glm::vec2(0, -0.5);
    circle.velocity = glm::normalize(glm::vec2(1, 1)) * speed;
}

void Assignment_6::OnDisable() {
    boxes.clear();
    walls.clear();
}

void Assignment_6::Update(float deltaTime) {
    for (auto box = boxes.begin(); box != boxes.end(); box++) {
        glm::vec2 closestPoint{
            glm::clamp(circle.center.x, (*box).A.x, (*box).B.x),
            glm::clamp(circle.center.y, (*box).A.y, (*box).B.y),
        };

        if (glm::distance(circle.center, closestPoint) < circle.radius) {
            circle.center.y -= 0.001f;
            circle.velocity =
                glm::reflect(circle.velocity, glm::normalize(circle.center - closestPoint));
        }
    }

    for (Line& wall : walls) {
        glm::vec2 wallVec = wall.end - wall.start;
        glm::vec2 wallOrth = glm::normalize(glm::vec2(-wallVec.y, wallVec.x));
        float originDist = glm::dot(wallOrth, wall.end);
        float centerDist = glm::dot(wallOrth, circle.center);

        float dist =
            glm::distance(circle.center,
                          circle.center - wallOrth * (centerDist - originDist));

        if (dist < circle.radius) {
            circle.center +=
                glm::normalize(glm::reflect(circle.velocity, wallOrth)) * 0.1f;
            circle.velocity = glm::reflect(circle.velocity, wallOrth);
        }
    }

    circle.center += circle.velocity * deltaTime;
}

void Assignment_6::Draw() {
    for (auto box = boxes.begin(); box != boxes.end(); box++) {
        (*box).Draw();
        /*glm::vec2 closestPoint{
            glm::clamp(circle.center.x, (*box).A.x, (*box).B.x),
            glm::clamp(circle.center.y, (*box).A.y, (*box).B.y),
        };
        Draw::Line(circle.center, closestPoint);*/
    }

    for (Line& wall : walls) {
        wall.Draw();

        glm::vec2 wallVec = wall.end - wall.start;
        glm::vec2 wallOrth = glm::normalize(glm::vec2(-wallVec.y, wallVec.x));
        float originDist = glm::dot(wallOrth, wall.end);
        float centerDist = glm::dot(wallOrth, circle.center);

        Draw::Line(circle.center,
                   circle.center - wallOrth * (centerDist - originDist));
    }

    circle.Draw();
}

void Assignment_6::DrawGUI() {
    ImGui::Begin("Inspector");
    ImGui::End();
}
