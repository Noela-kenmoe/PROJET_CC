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
void Render(DiagramType& currentDiagram);
void DrawDiagramme(SDL_Renderer* renderer);
bool showBarChart = false;
bool showPieChart = false;
bool quit = false;

}; 

enum  DiagramType{
    Barres,
    Camembert,
    Rien
};
 DiagramType currentDiagram = DiagramType::Rien;
#endif
