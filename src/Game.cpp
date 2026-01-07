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
#include<cmath>

//constructeur
Game::Game() :Title("DIAGRAMME A BARRE"),Width(1200),Height(900),window(nullptr){}
//Destructeur
Game::~Game(){}

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
    for(int i = 0;i< barcount;i++){
        ImGui::InputFloat(("valeurs" + std::to_string(i+1)).c_str(),&userdata[i]);
      }
  int Xstart = 200; //pour definir la position de depart sur X
  int Ystart = 600;//pour definir la position de depart sur Y
  int xs = 700;
  int barWidth = 60; // la largeur des barres
  int spacing = 40; //espace entre les barres
  int maxHeight = 600; //pour definir la auteur maximale du graphique
   int space = 20;
   float* current;
   const float* target;
   float speed = 5.0f; 
   float Deltatime;
  
   //interface ImGui pôur la saisie
    
    for(int i = 0; i<barcount ; i++){//calcul de la difference entre la valeur entréé par l'utilisateur et la valeur actuelle
      float diff = target[i] - current[i];
       if(fabs(diff)>0.01f){/*si la différence est significative on avance doucement vers la 
                              valeur entrée par l'utlisateur*/
        current[i] += diff*speed*Deltatime; //inter^polation lineaire
       }else
       current[i] = target[i];
    }
     //trouver la valeur maximale pour normalisé les hauteurs des barres
    const float* data;
    float maxvalues = 1.0f;
      for(int i = 0 ; i<barcount; i++){
        if(data[i]>maxvalues){
          maxvalues= data[i];
        }
        float barw = (float)barWidth/barcount;
      }
   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,255,255);
   //AXE y
    SDL_RenderLine(renderer,Xstart,Ystart,Xstart,Ystart-maxHeight);
  //AXE x
   SDL_RenderLine(renderer,Xstart,Ystart,Xstart+900,Ystart);
  //DESSIN DES BARRES
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    
    SDL_Color colors [barcount]={
      {255,0,0 ,255}, //couleur rouge
      {0,0,255,255}, //couleur bleu
      {0,255,0,255},  //couleur vert
      {255,165,0,255},  //couleur orange
      {255,255,0,255} , //couleur jaune
      {128,0,128,255},     //couleur violet
      {255,192,203,255} ,  //couleur rose
      {255,140,0,255}     //couleur orange
    };
    
    //Dessin des barres avec les coordonnées 
      for (size_t i=0; i < barcount;i++){
        
        SDL_FRect bar;
         bar.x = Xstart + spacing + i * (barWidth + spacing);
         bar.w = barWidth;
         bar.h = data[i];
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         SDL_SetRenderDrawColor(renderer,colors[i].a,colors[i].g,colors[i].b,colors[i].a);
         SDL_RenderFillRect(renderer, &bar);
         }


      SDL_SetRenderDrawColor(renderer,255,255,255,255);
 SDL_Delay(2000);
 }
  //Game game;

  void Game::Render(SDL_Renderer* renderer){

    


    static const int count = 7; // nombre de barres
    static float data[count] = {0,0,0,0,0,0,0};
    static char labels[count][32] = {"A","B","C","D","E","F","G"};
    static ImVec4 colors[count] = {
      ImVec4(0.8f,0.2f,0.2f,0.1f),
       ImVec4(0.2f,0.8f,0.2f,0.1f),
      ImVec4(0.2f,0.2f,0.2f,0.8f),
       ImVec4(0.8f,0.8f,0.2f,0.1f),
      ImVec4(0.8f,0.2f,0.8f,0.1f)};

      
      
      for(int i = 0 ; i<count; i++){
        ImGui::InputFloat(labels[i], &data[i], 0.1f,10.0f,"%.2f");
      }
      
  
  
  
    //trouver la valeur max pour les axes
    float maxValues = 0.0f;
    for(int i = 0; i< count ; i++){
    if(data[i]>maxValues) maxValues = data[i];

    
    }
    //Affichge des barres
    for(int i = 0; i< count ; i++){
      ImGui::Text("%s",labels[i]);
      ImGui::SameLine(150); //Decalagehorizontal pour aligner les barres
      ImGui::PushStyleColor(ImGuiCol_PlotHistogram,colors[i]);

      ImGui::ProgressBar(data[i]/maxValues, ImVec2(200,0));
      ImGui::PopStyleColor();
      ImGui::SameLine();
      ImGui::Text("%.2f",data[i]);
    }
    ImGui::Separator();
    ImGui::Text("Axes : 0 ->%.2f(graduation automatique)",maxValues);

    //Bouton retour au menu
    
  
  }
  
  
 