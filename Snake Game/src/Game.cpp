#include "Game.h"
#include "globals.h"

Game::Game() : food(snake.body) {
    InitAudioDevice();
    eatSound = LoadSound("assets/eat.mp3");
    wallSound = LoadSound("assets/wall.mp3");
    running = true;
    score = 0;
}

Game::~Game() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    if (running) {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);
    }
}

void Game::CheckCollisionWithEdges() {
    Vector2 head = snake.body[0];
    if (head.x >= cellCount || head.x < 0 || head.y >= cellCount || head.y < 0) {
        GameOver();
    }
}

void Game::GameOver() {
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
    PlaySound(wallSound);
}

void Game::CheckCollisionWithTail() {
    std::deque<Vector2> body = snake.body;
    body.pop_front();
    if (ElementInDeque(snake.body[0], body)) {
        GameOver();
    }
}
