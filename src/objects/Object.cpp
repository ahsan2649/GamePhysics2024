#include "Object.h"

Object::Object(float mass) : mass(mass) {

}

Object::~Object() {}

void Object::Draw() {}

void Object::AddForce(glm::vec2 force) {
    this->totalForce += force;
}
