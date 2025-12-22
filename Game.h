#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include <iostream>
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
    Game(); 
    ~Game(); 
void Run(); 
void HandleEvents(); 
void Update();
void Render(SDL_Renderer * renderer, const std::vector<int>& data, int x,int y, int width, int heigth);
void DrawDiagramme();
}; 

#endif
