#pragma once
#include <raylib.h>
#include <raymath.h>
#include <deque>

extern int cellSize;
extern int cellCount;
extern int offset;
extern double lastUpdateTime;
extern Color green;
extern Color darkGreen;

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
bool EventTriggered(double interval);
