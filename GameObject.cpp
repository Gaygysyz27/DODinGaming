#include "GameObject.h"
#include <iostream>
#include <cmath>

GameObject::GameObject(float xc, float yc, float r) {
    center = Vec2(xc, yc);
    this->r = r;
    speed = 100.f;
    
    red = rand() % 256;
    green = rand() % 256;
    blue = rand() % 256;
    
    angle = 360 * ((float)rand() / RAND_MAX);
    float dirx = cos(angle * 3.14159f / 180.0f);
    float diry = sin(angle * 3.14159f / 180.0f);
    direction = Vec2(dirx * speed, diry * speed);
}

void GameObject::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, SDL_ALPHA_OPAQUE);
    
    float x = r;
    float y = 0;
    
    while (x >= y) {
        SDL_RenderDrawPoint(renderer, center.x + x, center.y + y);
        SDL_RenderDrawPoint(renderer, center.x + x, center.y - y);
        SDL_RenderDrawPoint(renderer, center.x - x, center.y + y);
        SDL_RenderDrawPoint(renderer, center.x - x, center.y - y);
        SDL_RenderDrawPoint(renderer, center.x + y, center.y + x);
        SDL_RenderDrawPoint(renderer, center.x + y, center.y - x);
        SDL_RenderDrawPoint(renderer, center.x - y, center.y + x);
        SDL_RenderDrawPoint(renderer, center.x - y, center.y - x);
        
        y++;
        float xMid = x - 0.5f;
        if (xMid * xMid + y * y >= r * r)
            x--;
    }
}

void GameObject::Move(float delta) {
    center.Addvf2(direction.Multiplyf(delta));
}

void GameObject::BorderCollision(int width, int height) {
    if (center.x + r >= width || center.x - r <= 0) {
        direction.x = -direction.x;
    }
    if (center.y + r >= height || center.y - r <= 0) {
        direction.y = -direction.y;
    }
}