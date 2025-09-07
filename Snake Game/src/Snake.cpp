#include "Snake.h"
#include "globals.h"

Snake::Snake() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
    addSegment = false;
}

void Snake::Draw() {
    for (const auto& segment : body) {
        Rectangle rect = { offset + segment.x * cellSize, offset + segment.y * cellSize, (float)cellSize, (float)cellSize };
        DrawRectangleRounded(rect, 0.5, 6, darkGreen);
    }
}

void Snake::Update() {
    body.push_front(Vector2Add(body[0], direction));
    if (!addSegment) body.pop_back();
    else addSegment = false;
}

void Snake::Reset() {
    body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
    direction = { 1, 0 };
}
