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
void Run(); 
void HandleEvents(); 
void Update();
void Render();
void DrawDiagramme(SDL_Renderer* renderer);

bool quit = false;

}; 

enum  DiagramType{
    Barres,
    Camembert,
    Rien
};
 //DiagramType currentDiagram = DiagramType::Rien;

 //structure pour gerer les donnees et les labels
 struct DiagramData{
    std::vector<std::string> labels;
    std::vector<float> values;
 };


 enum class View{
    Menu,
    BarDiagram,
    PieDiagram
 };
 //View currentView = View::Menu;

#endif
