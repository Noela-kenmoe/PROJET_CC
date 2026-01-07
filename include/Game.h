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
void Render(SDL_Renderer* renderer);
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
 const int barcount = 8; 
 float userdata[barcount]= {50, 130, 80, 100,69,144,97,106};//valeurs d'entrée
  float dat[barcount] = {10,20,30,40,50,60,70,80};//pour l'animation

#endif
