#include "Line.h"
#include "core/Draw.h"

Line::Line(glm::vec2 start, glm::vec2 end)
    : Object(1), start(start), end(end) {}

void Line::Draw() {
    Draw::Line(start, end);
}
