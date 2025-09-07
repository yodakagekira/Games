/*
Use this to compile: g++ src/*.cpp -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm -std=c++17
And this command to run: ./main.exe

*/




#include <iostream>
#include "Game.h"
#include "globals.h"

bool allowMove = false;
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};
int cellSize = 30;
int cellCount = 25;
int offset = 75;
double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
    for (auto& el : deque) {
        if (Vector2Equals(el, element)) return true;
    }
    return false;
}

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    std::cout << "Starting the game..." << std::endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Retro Snake");
    SetTargetFPS(120);

    Game game;

    while (!WindowShouldClose()) {
        BeginDrawing();

        if (EventTriggered(0.2)) {
            allowMove = true;
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1 && allowMove) {
            game.snake.direction = {0, -1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1 && allowMove) {
            game.snake.direction = {0, 1};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1 && allowMove) {
            game.snake.direction = {-1, 0};
            game.running = true;
            allowMove = false;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1 && allowMove) {
            game.snake.direction = {1, 0};
            game.running = true;
            allowMove = false;
        }

        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
        DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

