#pragma once
#include <raylib.h>
#include <deque>

class Snake {
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Snake();
    void Draw();
    void Update();
    void Reset();
};
