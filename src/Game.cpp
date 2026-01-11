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
#include<string>

//constructeur
Game::Game() :Title("DIAGRAMME A BARRE"),Width(1200),Height(900),window(nullptr){}
//Destructeur
Game::~Game(){}

   float userdata[barcount]= {30, 50, 60, 70,80,90,100,150};//valeurs d'entrée
   float dat[pie] = {120,80,230,430,330,270};//pour l'animation
  float current [barcount]= {0,0,0,0,0,0,0,0};
  const double PI=3.14159265358979323846;
  float maxval [barcount]={0,0,0,0,0,0,0,0};
  std::string lab[barcount]={"A","B","C","D","E","F","G","H"};
  struct color
  {
    int r;
    int g;
    int b;
    int a;
  };
std::vector<ImU32> couleur = {
        IM_COL32(255, 0, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(0, 0, 255, 255),
        IM_COL32(255, 255, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(123 , 255, 0, 293)
       };  

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
    

  
  int Xstart =  300; //pour definir la position de depart sur X
  int Ystart = 700;//pour definir la position de depart sur Y
  int xs = 700;
  int barWidth = 60; // la largeur des barres
  int spacing= 40; //espace entre les barres
  int maxHeight = 600; //pour definir la auteur maximale du graphique
   //float* current;
   float Deltatime = 100.0f;
   std::vector<std::string> label={"A","B","C","D","E","F","G","H"};
   float textX=600;
   float  textY= 400;
   float spacetext = 30;
  
   
    //gestion de l'animation
    float speed = 3.1f;
    for(int i = 0;i<barcount;i++){
      float diff = userdata[i] - current[i];
      // if(fabs(diff)>0.01f){
      current[i] += diff*speed*Deltatime;
      //}
    }
   
     //trouver la valeur maximale pour normalisé les hauteurs des barres
    const float* data;
    float maxvalues = 1.0f;
      for(int i = 0 ; i<barcount; i++){
        if(userdata[i]>maxvalues){
          maxvalues= userdata[i];
        }
        int barw = (barWidth-spacing*(barcount+1))/barcount;
      }
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
      SDL_FRect bakc= {20,20,11500,850};
      
      SDL_RenderFillRect(renderer, &bakc);
      TTF_Font* font;
      
      //Uint32 col=(255,255,255,255);
     //trouver  la valeurs max pour faire les comparaison
     maxval[0] = userdata[0];
     int index = 0;

     for(int i= 0; i<barcount ; i++){
        if(userdata[i]>maxval[i]){
          maxval[i]= userdata[i];
          index = i;
        }
     }
     //creation des textes de comparaison
     for(int i = 0; i<barcount;i++){
       std::string text;
       if(i== index) text = lab[i]+"est la plus haute barre";
       else text = lab[i]+"inferieur à"+ lab[index];
       /*SDL_Surface* surf = TTF_RenderText_Blended(font,text.c_str(),col);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surf);
       SDL_FRect RCT= {textX,textY+i*spacetext,surf->w,surf->h};
       SDL_DestroySurface(surf);
       SDL_RenderTexture(renderer,texture,nullptr,&RCT);
       SDL_DestroyTexture(texture);*/

     }
      //TTF_RenderText_Blended(font,text.c_str(),col)
   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,255,255);
    //AXE y
    SDL_RenderLine(renderer,Xstart,Ystart,Xstart,Ystart-maxHeight);
    //fleche de l'axe x
    SDL_RenderLine(renderer,Xstart+900,Ystart,Xstart+890,Ystart-5);
    SDL_RenderLine(renderer,Xstart+900,Ystart,Xstart+890,Ystart+5);
   
    //AXE y 
   SDL_RenderLine(renderer,Xstart,Ystart,Xstart+900,Ystart);
   //fleche de l'axe Y
    SDL_RenderLine(renderer,Xstart,Ystart - 600,Xstart-5,Ystart-590);
    SDL_RenderLine(renderer,Xstart,Ystart-600,Xstart-5,Ystart-590);//petit trait
    

    //graduation des axes
    int step = 50; //distance entre les graduations
    int valstep = 10; //valeur de chaque graduation
      for(int i = 0; i<barcount; i++){
        int ypos = Ystart - i*step;
        SDL_RenderLine(renderer,Xstart-5,ypos,Xstart+5,ypos);//petit trait sur les axes
        
      }
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
        int barh = (userdata[i]/maxvalues)*maxHeight;
        SDL_FRect bar;
         bar.x = Xstart + spacing + i * (barWidth + spacing);
         bar.w = barWidth;
         bar.h = userdata[i];
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         //description sur chaque bar
         
         SDL_SetRenderDrawColor(renderer,colors[i].a,colors[i].g,colors[i].b,colors[i].a);
         SDL_RenderFillRect(renderer, &bar);
          
         }


      SDL_SetRenderDrawColor(renderer,255,255,255,255);
 SDL_Delay(2000);
 TTF_CloseFont(font);
 TTF_Quit();
 }
  //Game game;

  void Game::Render(SDL_Renderer* renderer){

    


    
    float radius = 120.0f;
    std::vector<std::string> label={"A","B","C","D","E","F"};
    float startangle = 0.0f;
     float endangle;

    ImDrawList* draw = ImGui::GetWindowDrawList();
    ImVec2 windowposition = ImGui::GetCursorScreenPos();//position de la fenetre
      ImVec2 center = ImGui::GetCursorScreenPos();
      center.x +=150;
      center.y += 150;
    ImVec2 mouseposition = ImGui::GetMousePos();

   float total = 0.0f;
      for(int i = 0;i<pie;i++){
        total +=dat[i] ;
      }
    
    
     
;      //calcul la somme des valeurs afin de determiner les angles
      
       startangle = 0; //angle de depart pour la premiere part
      for(int i = 0; i< 6; i++){
        float scileangle = (dat[i]/total)*2.0f*PI;//afin d'obtenir les protions en degres
         endangle = startangle+ scileangle;
       /*ImVec2 souris = ImVec2(mouseposition.x -(windowposition.x+center.x),mouseposition.y-(windowposition.y+center.y));
   float dist = sqrt(souris.x*souris.x+souris.y*souris.y);
    //calculer l'angle de la souris par rapport au centre
    float angleSouris = atan2(souris.y,souris.x);
    if(angleSouris<0){
      angleSouris += 2.0f*PI; //on normalise la part entre 0 et 2PI
    
    }
    //boucle qui permet de verifier si la souris est sur la part
    bool verifive = (angleSouris>= startangle && angleSouris <= endangle);
    
      float radius = verifive ? (radius*1.1f) : radius;*/
    
     
;      //calcul la somme des valeurs afin de determiner les angles
      
      //angle de depart pour la premiere part
      //dessin des parts du camembert
      draw->PathClear();
      draw->PathLineTo(center);
      draw->PathArcTo(center,radius,startangle,startangle+scileangle);
      
      
       //affichage des labels au milieu de la part
       
      float midangle  = (startangle + endangle)/2.0f;
      ImVec2 labelpos;
      labelpos.x = center.x +cos(midangle)*(radius*1.2f);
      labelpos.y = center.y + sin(midangle)*(radius*1.2f);
      char buf[64];
      snprintf(buf,sizeof(buf),"%s",label[i].c_str());
      draw->AddText(labelpos,IM_COL32(255,255,255,255),buf);
      draw->PathFillConvex(couleur[i]);
      //(dat[i]/total*100.0f);
      
      
     
      startangle+=scileangle;
    }
  
  ImGui::Dummy(ImVec2(radius * 2, radius * 2));
  }
  
  
  void Game::HandleEvents(SDL_Renderer* renderer){
   std::vector<std::string> label={"A","B","C","D","E","F"};
   int i;
      
           float total = 0.0f;
      for(int i = 0;i<pie;i++){
        total +=dat[i] ;
      }
       std::vector<ImU32> colors = {
        IM_COL32(255, 0, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(0, 0, 255, 255),
        IM_COL32(255, 255, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(123 , 255, 0, 293)
       };
      float windowwidth = ImGui::GetWindowWidth();
      ImGui::SetCursorPos(ImVec2(windowwidth-150.0f,30.0f));

      ImGui::BeginGroup();//afin de garder les elements alignés
      ImGui::Text("LEGENDE:");
      ImGui::Separator();

      //boucle qui permet de creer la legende en fonction des parts et du total
      for(int i = 0; i<6; i++){
        //calcul des pourcentages
        float pourcentage = (total>0) ? (dat[i]/total)*100.0f:0.0f;
        //affichage d'un petit carré en couleur
        ImU32 u32_color = couleur[i];// on recupere la couleur de la part
        ImVec4 car = ImGui::ColorConvertU32ToFloat4(u32_color);//conversion de la couleur de ImU32 pour obtenir un ImVec4
        ImGui::ColorButton(label[i].c_str(),car,ImGuiColorEditFlags_NoTooltip,ImVec2(12,12));
        ImGui::SameLine();//pour mettre le texte sur la meme ligne que le carré
        //affichage label:(00.0%)
        ImGui::Text("%s:%.1f%%",label[i].c_str(),pourcentage);
      }
  ImGui::EndGroup();
}
 
  /*void Update(){
    ImVec2 mouseposition;
    ImGui::GetMousePos();
    ImVec2 souris = (ImVec2(mouseposition.x -windowpos.x+Center.x),mouseposition.y-(windowpos.y+center.y));

    //calculer l'angle de la souris par rapport au centre
    float angleSouris = atan2(souris.y,souris.x);
    if(angleSouris<0){
      angleSouris += 2.0f*PI; //on normalise la part entre 0 et 2PI
    
    }
    //boucle qui permet de verifier si la souris est sur la part
    bool verifive = (angleSouris>= startangle && angleSouris <= endanle);
    if(verifive){
      float radius = (radius*1.1f);
    }
  }*/
 