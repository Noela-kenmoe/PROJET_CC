 #pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <vector>

class Game {
 private: 
bool isRunning; 
    SDL_Window* window; 
    SDL_Renderer* renderer;
    float Width; 
    float Height; 
    std::string Title;  
public: 
    Game(const std::string& title, float width, float height); 
    ~Game(); 
void Run(); 
void HandleEvents(); 
void Update();
void Render(SDL_Renderer * renderer, const std::vector<int>& data, int x,int y, int width, int heigth);
}; 
