#pragma once
#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>

class Game {
 private: 
bool running; 
    SDL_Window* window; 
    float Width; 
    float Height; 
    std::string Title;  
public: 
    Game(); 
    ~Game(); 
void Run(SDL_Renderer* renderer); 
void HandleEvents(); 
void Update();
bool Render(SDL_Renderer* renderer);
void DrawDiagramme(SDL_Renderer* renderer);
bool showBarChart = false;
bool showPieChart = false;
bool quit = false;

}; 

enum class DiagramType{
    Barres,
    Camembert,
    Rien
};
static DiagramType currentDiagram = DiagramType::Rien;
#endif
