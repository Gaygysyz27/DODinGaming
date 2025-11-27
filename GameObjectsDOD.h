#pragma once
#include <SDL.h>
#include <vector>

class GameObjectsDOD {
private:
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> dirX;
    std::vector<float> dirY;
    std::vector<float> r;
    std::vector<Uint8> red;
    std::vector<Uint8> green;
    std::vector<Uint8> blue;
    int count;

public:
    GameObjectsDOD() { count = 0; }
    void Resize(int size);
    void Initialize(int width, int height, float radius);
    void Draw(SDL_Renderer* renderer);
    void Move(float delta);
    void BorderCollision(int width, int height);
    int CheckCollisions();
};