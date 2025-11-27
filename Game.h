#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"
#include "GameObjectsDOD.h"

class Game {
private:
    bool running;
    bool useDOD;
    int32_t width, height;
    int objectCount;
    float deltaTime;
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    std::vector<GameObject> objects;
    GameObjectsDOD objectsDOD;
    
    float fps;
    int collisions;

public:
    Game();
    void Destroy();
    void RunLoop();
    void Update();
    void SpawnObjects(int count);
};