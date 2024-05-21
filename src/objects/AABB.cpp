#include "AABB.h"
#include "core/Draw.h"

AABB::AABB(glm::vec2 A, glm::vec2 B) : Object(1), A(A), B(B) {

}

glm::vec2 AABB::GetCenter() {
    return (A + B) / 2.0f;
}

void AABB::Draw() {
    Draw::AABB(A, B);
}
