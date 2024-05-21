#include "Circle.h"
#include "core/Draw.h"

Circle::Circle(float mass, glm::vec2 center, float radius) : Object(mass), center(center), radius(radius) {

}

void Circle::Draw() {
    Draw::Circle(center, radius);
}
