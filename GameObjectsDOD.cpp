#include "GameObjectsDOD.h"
#include <iostream>
#include <cmath>

void GameObjectsDOD::Resize(int size) {
    x.resize(size);
    y.resize(size);
    dirX.resize(size);
    dirY.resize(size);
    r.resize(size);
    red.resize(size);
    green.resize(size);
    blue.resize(size);
    count = size;
}

void GameObjectsDOD::Initialize(int width, int height, float radius) {
    for (int i = 0; i < count; i++) {
        x[i] = rand() % width;
        y[i] = rand() % height;
        r[i] = radius;
        
        red[i] = rand() % 256;
        green[i] = rand() % 256;
        blue[i] = rand() % 256;
        
        float speed = 100.f;
        float angle = 360 * ((float)rand() / RAND_MAX);
        dirX[i] = cos(angle * 3.14159f / 180.0f) * speed;
        dirY[i] = sin(angle * 3.14159f / 180.0f) * speed;
    }
}

void GameObjectsDOD::Draw(SDL_Renderer* renderer) {
    for (int i = 0; i < count; i++) {
        SDL_SetRenderDrawColor(renderer, red[i], green[i], blue[i], SDL_ALPHA_OPAQUE);
        
        float px = r[i];
        float py = 0;
        
        while (px >= py) {
            SDL_RenderDrawPoint(renderer, x[i] + px, y[i] + py);
            SDL_RenderDrawPoint(renderer, x[i] + px, y[i] - py);
            SDL_RenderDrawPoint(renderer, x[i] - px, y[i] + py);
            SDL_RenderDrawPoint(renderer, x[i] - px, y[i] - py);
            SDL_RenderDrawPoint(renderer, x[i] + py, y[i] + px);
            SDL_RenderDrawPoint(renderer, x[i] + py, y[i] - px);
            SDL_RenderDrawPoint(renderer, x[i] - py, y[i] + px);
            SDL_RenderDrawPoint(renderer, x[i] - py, y[i] - px);
            
            py++;
            float pxMid = px - 0.5f;
            if (pxMid * pxMid + py * py >= r[i] * r[i])
                px--;
        }
    }
}

void GameObjectsDOD::Move(float delta) {
    for (int i = 0; i < count; i++) {
        x[i] += dirX[i] * delta;
        y[i] += dirY[i] * delta;
    }
}

void GameObjectsDOD::BorderCollision(int width, int height) {
    for (int i = 0; i < count; i++) {
        if (x[i] + r[i] >= width || x[i] - r[i] <= 0) {
            dirX[i] = -dirX[i];
        }
        if (y[i] + r[i] >= height || y[i] - r[i] <= 0) {
            dirY[i] = -dirY[i];
        }
    }
}

int GameObjectsDOD::CheckCollisions() {
    int collisions = 0;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            float dx = x[i] - x[j];
            float dy = y[i] - y[j];
            float dist = dx * dx + dy * dy;
            float minDist = r[i] + r[j];
            if (dist < minDist * minDist) {
                collisions++;
            }
        }
    }
    return collisions;
}