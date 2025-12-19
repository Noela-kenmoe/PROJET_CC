#include <iostream>
#include "Game.h"
#include <vector>

//constructeur
Game::Game(): Title("zero"), Width(800),Height(600),window(nullptr),renderer(nullptr){}
Game::Game(const std::string& title, float width, float height)
: Title(title), Width(width), Height(height),  
      window(nullptr), renderer(nullptr) {}
Game::~Game(){}

void Game::Render(SDL_Renderer * renderer, const std::vector<int>& data, int x,int y, int width, int height){
  //Dessin des axes
  SDL_SetRenderDrawColor(renderer,0,0,0,255);
  //AXE y
  SDL_RenderLine(renderer,x,y,x,y+height);
  //AXE x
  SDL_RenderLine(renderer,x,y+height,x+width,y+height);
  int barCount = data.size();
  int barWidth = width/ barCount;
  int maxValue = 0;
for (int value : data){
  if (value>maxValue){
    maxValue = value;
  }
}
  //dessin des barres
    SDL_SetRenderDrawColor(renderer,0,100,255,255);
      for (int i = 0; i< barCount;i++){
        int barHeight = ( data[i]*height);
            SDL_FRect bar;
            bar.x = x + i *barWidth ;
            bar.y = y + (height - barHeight) ; // largeur
            bar.w = barWidth - 5; //pour creer de l'espace entre les barres
            bar.h = barHeight; //qui permet a la barre de monter vers le haut
      
            SDL_RenderFillRect(renderer, &bar);

       }
}
