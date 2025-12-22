#include <SDL3/SDL.h>
#include <vector>
#include "Game.h"
#include <iostream>


//constructeur
Game::Game() :Title("DIAGRAMME A BARRE"),Width(1200),Height(900),window(nullptr),renderer(nullptr){}
//Destructeur
Game::~Game(){}

void Game::DrawDiagramme(){

  //donnees fixes
  std::vector<int> data = {150, 220, 280, 200};
  int Xstart = 100; //pour definir la position de depart sur X
  int Ystart = 400;//pour definir la position de depart sur Y

  int barWidth = 50; // la largeur des barres
  int spacing = 20; //espace entre les barres
  int maxHeight = 300; //pour definir la auteur maximale du graphique

   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
   //AXE y
    SDL_RenderLine(renderer,Xstart,Ystart,Xstart,Ystart-maxHeight);
  //AXE x
  //DESSIN DES BARRES
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

      for (size_t i=0; i < data.size();i++){
        SDL_FRect bar;
         bar.x = Xstart + spacing + i * (barWidth + spacing);
         bar.w = barWidth;
         bar.h = data[i];
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         SDL_RenderFillRect(renderer, &bar);
      }
 }
  