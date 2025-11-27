#include "Game.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

Game::Game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log(SDL_GetError());
        return;
    }
    
    width = 1600;
    height = 900;
    useDOD = false;
    objectCount = 50000;
    fps = 0;
    collisions = 0;
    
    window = SDL_CreateWindow("DOD Project", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    
    if (!window) {
        SDL_Log(SDL_GetError());
        return;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!renderer) {
        SDL_Log(SDL_GetError());
        return;
    }
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
    running = true;
    
    std::cout << "\n=== DOD PROJECT ===\n";
    std::cout << "Objects: " << objectCount << "\n";
    std::cout << "Mode: " << (useDOD ? "DOD" : "OOP") << "\n\n";
    
    SpawnObjects(objectCount);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::RunLoop() {
    Uint64 Current = SDL_GetPerformanceCounter();
    Uint64 Last;
    SDL_Event currentEvent;
    
    int frameCount = 0;
    Uint64 fpsTimer = SDL_GetPerformanceCounter();
    
    while (running) {
        Last = Current;
        Current = SDL_GetPerformanceCounter();
        deltaTime = (float)((float)(Current - Last) / SDL_GetPerformanceFrequency());
        
        while (SDL_PollEvent(&currentEvent)) {
            if (currentEvent.type == SDL_QUIT) {
                SDL_Log("Closed the window");
                running = false;
            }
            
            if (currentEvent.type == SDL_KEYDOWN) {
                if (currentEvent.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                if (currentEvent.key.keysym.sym == SDLK_SPACE) {
                    useDOD = !useDOD;
                    std::cout << "\nMode: " << (useDOD ? "DOD" : "OOP") << "\n";
                }
                if (currentEvent.key.keysym.sym == SDLK_PLUS || 
                    currentEvent.key.keysym.sym == SDLK_EQUALS) {
                    if (objectCount < 100000) {
                        SpawnObjects(objectCount + 1000);
                    }
                }
                if (currentEvent.key.keysym.sym == SDLK_MINUS) {
                    if (objectCount > 100) {
                        SpawnObjects(objectCount - 1000);
                    }
                }
                if (currentEvent.key.keysym.sym == SDLK_1) SpawnObjects(1000);
                if (currentEvent.key.keysym.sym == SDLK_2) SpawnObjects(5000);
                if (currentEvent.key.keysym.sym == SDLK_3) SpawnObjects(10000);
                if (currentEvent.key.keysym.sym == SDLK_4) SpawnObjects(25000);
                if (currentEvent.key.keysym.sym == SDLK_5) SpawnObjects(50000);
                if (currentEvent.key.keysym.sym == SDLK_6) SpawnObjects(75000);
                if (currentEvent.key.keysym.sym == SDLK_7) SpawnObjects(100000);
            }
        }
        
        Update();
        
        frameCount++;
        Uint64 fpsElapsed = Current - fpsTimer;
        float fpsTime = (float)fpsElapsed / SDL_GetPerformanceFrequency();
        if (fpsTime >= 1.0f) {
            fps = frameCount / fpsTime;
            
#ifdef _WIN32
            PROCESS_MEMORY_COUNTERS_EX pmc;
            GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
            size_t memoryMB = pmc.WorkingSetSize / (1024 * 1024);
#else
            size_t memoryMB = 0;
#endif
            
            std::cout << "FPS: " << fps << " | Objects: " << objectCount 
                      << " | Mode: " << (useDOD ? "DOD" : "OOP") 
                      << " | Collisions: " << collisions
                      << " | Memory: " << memoryMB << " MB\n";
            
            frameCount = 0;
            fpsTimer = Current;
        }
    }
}

void Game::Update() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    if (useDOD) {
        objectsDOD.Move(deltaTime);
        objectsDOD.BorderCollision(width, height);
        objectsDOD.Draw(renderer);
        collisions = objectsDOD.CheckCollisions();
    } else {
        for (GameObject& obj : objects) {
            obj.Move(deltaTime);
            obj.BorderCollision(width, height);
        }
        
        for (GameObject& obj : objects) {
            obj.Draw(renderer);
        }
        
        collisions = 0;
        for (size_t i = 0; i < objects.size() - 1; i++) {
            for (size_t j = i + 1; j < objects.size(); j++) {
                Vec2 c1 = objects[i].GetCenter();
                Vec2 c2 = objects[j].GetCenter();
                float dx = c1.x - c2.x;
                float dy = c1.y - c2.y;
                float dist = dx * dx + dy * dy;
                float minDist = objects[i].GetRadius() + objects[j].GetRadius();
                if (dist < minDist * minDist) {
                    collisions++;
                }
            }
        }
    }
    
    SDL_RenderPresent(renderer);
}

void Game::SpawnObjects(int count) {
    objectCount = count;
    
    objects.clear();
    for (int i = 0; i < count; i++) {
        GameObject obj(rand() % width, rand() % height, 5.f);
        objects.push_back(obj);
    }
    
    objectsDOD.Resize(count);
    objectsDOD.Initialize(width, height, 5.f);
    
    std::cout << "Spawned " << count << " objects\n";
}