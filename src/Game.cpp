#include <SDL3/SDL.h>
#include <vector>
#include "Game.h"
#include <iostream>
#include "../libs/imgui/imgui.h"
#include "../libs/imgui/backends/imgui_impl_sdl3.h"
#include "../libs/imgui/backends/imgui_impl_sdlrenderer3.h"
#include "UI.h"
#include "Renderer.h"
#include <algorithm>
#include<SDL3_ttf/SDL_ttf.h>

//constructeur
Game::Game() :Title("DIAGRAMME A BARRE"),Width(1200),Height(900),window(nullptr){}
//Destructeur
Game::~Game(){}

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
  std::vector<int> data = {250, 230, 280, 200};
  std::vector<int> dat = {223,145,250,300};
  int Xstart = 200; //pour definir la position de depart sur X
  int Ystart = 600;//pour definir la position de depart sur Y
  int xs = 700;
  int barWidth = 60; // la largeur des barres
  int spacing = 40; //espace entre les barres
  int maxHeight = 600; //pour definir la auteur maximale du graphique
   int space = 20;
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
   float scaleY = (float)maxHeight/300;

   //choix du pas
   int pas = 280/5;
    if(pas== 0) pas = 1;

    //dessin des graduations
    int ticksize = 10;
    SDL_Color white ={255,255,255,255};

    for(int v = 0 ; v<= 300; v+= pas){
      int y = Ystart -(int)(v*scaleY);
      SDL_RenderLine(renderer,Xstart-ticksize,y,Xstart,y);
    }
   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,255,255);
   //AXE y
    SDL_RenderLine(renderer,Xstart,Ystart,Xstart,Ystart-maxHeight);
  //AXE x
   SDL_RenderLine(renderer,Xstart,Ystart,Xstart+900,Ystart);
  //DESSIN DES BARRES
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
    SDL_Color colors []={
      {255,0,0 ,255}, //couleur bleu
      {0,0,255,255}, //
      {0,255,0,255},
      {255,165,0,255}
    };
    for (int i = 0; i < data.size(); i++)
    {
      data[i] = 50 + rand()%400; //pour des valeurs aleatoires comprisent entre 50 et 600
    }
    for (int i = 0; i < dat.size(); i++)
    {
      dat[i] = 50 + rand()%400; //pour des valeurs aleatoires comprisent entre 50 et 600
    }
    //Dessin des barres avec les coordonnées 
      for (size_t i=0; i < data.size();i++){
        SDL_SetRenderDrawColor(renderer,colors[i].r,colors[i].g,colors[i].b,colors[i].a);
        SDL_FRect bar;
         bar.x = Xstart + spacing + i * (barWidth + spacing);
         bar.w = barWidth;
         bar.h = data[i];
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         SDL_RenderFillRect(renderer, &bar);
         }

for (size_t i=0; i < dat.size();i++){
       SDL_SetRenderDrawColor(renderer,colors[i].r,colors[i].g,colors[i].b,colors[i].a);
        SDL_FRect bar;
         bar.x = xs+ space + i * (barWidth + space);
         bar.w = barWidth;
         bar.h = dat[i];
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         SDL_RenderFillRect(renderer, &bar);
      }
 SDL_Delay(1000);
 }
  //Game game;

  void Render(){








    static const int count = 7; // nombre de barres
    static float data[count] = {0,0,0,0,0,0,0};
    static char labels[count][32] = {"A","B","C","D","E","F","G"};
    static ImVec4 colors[count] = {
      ImVec4(0.8f,0.2f,0.2f,0.1f),
       ImVec4(0.2f,0.8f,0.2f,0.1f),
      ImVec4(0.2f,0.2f,0.2f,0.8f),
       ImVec4(0.8f,0.8f,0.2f,0.1f),
      ImVec4(0.8f,0.2f,0.8f,0.1f)};

      //interface de saisie
      if(showInput){
        ImGui::Begin("saisie des donnés");
        ImGui::Text("veuillez entrer vos données :");
      }

      for(int i = 0 ; i<count; i++){
        ImGui::InputFloat(labels[i], &data[i], 0.1f,10.0f,"%.2f");
      }
      if(ImGui::Button("VALIDER")){
        showInput = false;
        ShowBarChart = true;
      }
      ImGui::SameLine();
        if(ImGui::Button("ANNULER")){
          showInput = false;
          showMenu = true;
        }
        

  }
  
 