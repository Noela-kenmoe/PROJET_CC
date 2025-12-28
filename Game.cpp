#include <SDL3/SDL.h>
#include <vector>
#include "Game.h"
#include <iostream>
#include "libs/imgui/imgui.h"
#include "libs/imgui/backends/imgui_impl_sdl3.h"
#include "libs/imgui/backends/imgui_impl_sdlrenderer3.h"
#include "UI.h"
#include "Renderer.h"


//constructeur
Game::Game() :Title("DIAGRAMME A BARRE"),Width(1200),Height(900),window(nullptr){}
//Destructeur
Game::~Game(){}

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
  std::vector<int> data = {150, 220, 280, 200};
  std::vector<int> dat = {123,45,250,300};
  int Xstart = 300; //pour definir la position de depart sur X
  int Ystart = 600;//pour definir la position de depart sur Y
  int xs = 700;
  int barWidth = 50; // la largeur des barres
  int spacing = 20; //espace entre les barres
  int maxHeight = 450; //pour definir la auteur maximale du graphique
   int space = 0;
   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,255,255);
   //AXE y
    SDL_RenderLine(renderer,Xstart,Ystart,Xstart,Ystart-maxHeight);
  //AXE x
   SDL_RenderLine(renderer,Xstart,Ystart,Xstart+450,Ystart);
  //DESSIN DES BARRES
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
    SDL_Color colors []={
      {255,0,0 ,255}, //couleur bleu
      {0,0,255,255}, //
      {0,255,0,255},
      {255,165,0,255}
    };

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

 }
  //Game game;
  
  //void Game::Run(SDL_Renderer* renderer){
    
    /* if(!ShowDiagram){
    ImGui::Begin("affichge");
       
     switch (ShowDiagram)
     {
     case DiagramType::Barres: 
     DrawDiagramme();
      
      break;
     
     default:
      break;
     }
     }

       ImGui::End();
       
    
  } */
        
  bool ShowDiagram = true;
      

  void Game::Render(DiagramType& currentDiagram){
    if(!ShowDiagram) {

    ImGui::Begin("Menu");
    ImGui::Text("veillez choisir une option:");
    ImGui::Separator();
       if(ImGui::Button("exemple de diagramme"))
       {
        currentDiagram = DiagramType::Barres;
        //ShowDiagram = false;
      
       } 
        if(ImGui::RadioButton("diagramme personnalisée",currentDiagram == DiagramType::Camembert)){
        currentDiagram =DiagramType::Camembert;
        //ShowDiagram = false;
        }
        ImGui::Separator();
       
       if(currentDiagram == DiagramType::Barres){
       ImGui::Text("option selectionnée : exemple de diagramme");
       }else if (currentDiagram == DiagramType::Camembert)
       {
        ImGui::Text("option selectionnée : diagramme personnalisée");

       }
     
    ImGui::Separator();

switch (currentDiagram)
     {
     case DiagramType::Barres: 
     DrawDiagramme(renderer);
      /* code */
      break;
     
     default:
      break;

  }
  if(ImGui::Button("retour au menu")){
    ShowDiagram = true ;
    currentDiagram = DiagramType::Rien;
  }
  ImGui::End();
}
}