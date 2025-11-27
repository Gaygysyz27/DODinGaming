#pragma once
#include <SDL.h>
#include "Vec2.h"

class GameObject {
private:
    float r, speed, angle;
    Vec2 direction, center;
    Uint8 red, green, blue;

public:
    GameObject(float xc, float yc, float r);
    void Draw(SDL_Renderer* renderer);
    void Move(float delta);
    void BorderCollision(int width, int height);
    
    Vec2 GetCenter() { return center; }
    float GetRadius() { return r; }
};