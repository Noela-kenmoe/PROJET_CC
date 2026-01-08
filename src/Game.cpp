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

  float userdata[barcount]= {0, 0, 0, 0,0,0,0,0};//valeurs d'entrée
  float dat[pie] = {30,49,12,77,46,35};//pour l'animation
  const double PI=3.14159265358979323846;
  struct color
  {
    int r;
    int g;
    int b;
    int a;
  };
  

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
    

  
  int Xstart =  300; //pour definir la position de depart sur X
  int Ystart = 700;//pour definir la position de depart sur Y
  int xs = 700;
  int barWidth = 60; // la largeur des barres
  int spacing= 40; //espace entre les barres
  int maxHeight = 600; //pour definir la auteur maximale du graphique
   float* current;
   std::vector<std::string> label={"A","B","C","D","E","F","G","H"};
  
   
    
   
     //trouver la valeur maximale pour normalisé les hauteurs des barres
    const float* data;
    float maxvalues = 1.0f;
      for(int i = 0 ; i<barcount; i++){
        if(userdata[i]>maxvalues){
          maxvalues= userdata[i];
        }
        int barw = (barWidth-spacing*(barcount+1))/barcount;
      }
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
 }
  //Game game;

  void Game::Render(SDL_Renderer* renderer){

    


    static const int count = 7; // nombre de barres
    //static float data[count] = {0,0,0,0,0,0,0};
    //static char labels[count][32] = {"A","B","C","D","E","F","G"};
    /*static ImVec4 colors[count] = {
      ImVec4(0.8f,0.2f,0.2f,0.1f),
       ImVec4(0.2f,0.8f,0.2f,0.1f),
      ImVec4(0.2f,0.2f,0.2f,0.8f),
       ImVec4(0.8f,0.8f,0.2f,0.1f),
      ImVec4(0.8f,0.2f,0.8f,0.1f)};*/

      
     /* SDL_Color colors [pie]={
      {255,0,0 ,255}, //couleur rouge
      {0,0,255,255}, //couleur bleu
      {0,255,0,255},  //couleur vert
      {255,165,0,255},  //couleur orange
      {255,255,0,255} , //couleur jaune
      {128,0,128,255},   //couleur violet 
      };
      int centerX,centrey,radius; // le centre et le rayon du cercle
      //calcul la somme des valeurs afin de determiner les angles
      float total = 0;
      for(auto v : dat){
        total +=v;
      }
      float startangle = 0; //angle de depart pour la premiere part
      for(int i = 0; i< 6; i++){
        float scileangle = (dat[i]/total)*360.0f;//afin d'obtenir les protions en degres

      
      //dessin des parts du camembert
      SDL_SetRenderDrawColor(renderer,colors[i].r,colors[i].g,colors[i].b,255);
      //on trace les lignes du centres vers le cercle pour remplir la part
      for(float angle=startangle; angle<startangle+scileangle;angle +=1.0f){
        float rad = angle * PI/180.0f;//conersion des angles en degres
        int x = centerX+static_cast<int>((radius/1.5)*cos(rad));
        int y = centrey +static_cast<int>(radius*sin(rad));
       SDL_RenderLine(renderer,centerX,centrey,x,y);
      }
      //affichage des labels au milieu de la part
      float midangle  = startangle + scileangle/2.0f;
      float rd = midangle*PI/180.0f;
      int labelx = centerX + static_cast<int>((radius/1.5f)*sin(rd));

      startangle += scileangle;
    }*/
   ImGui::Text("si je  ois imgui marche");
   ImDrawList* draw = ImGui::GetWindowDrawList();
   ImVec2 p = ImGui::GetCursorScreenPos();
   draw->AddRectFilled(ImVec2(p.x+20,p.y+20),ImVec2(p.x+120,p.y+120),IM_COL32(255,0,0,255));
   ImGui::Dummy(ImVec2(150,150));
    
    
  
  }
  
  void Game::HandleEvents(SDL_Renderer* renderer){
   std::vector<std::string> label={"A","B","C","D","E","F"};
   int i;
      float centx,centy;
      float radius = 100.0f;
      //std::string test;

       std::vector<ImU32> colors = {
        IM_COL32(255, 0, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(0, 0, 255, 255),
        IM_COL32(255, 255, 0, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(123 , 255, 0, 293)
       };
      
      ImDrawList* draw_list = ImGui::GetWindowDrawList();
      ImVec2 center = ImGui::GetCursorScreenPos();//position du curseur dans la fenetre
      center.x += radius;
      center.y += radius; //decalage pour centrer le cercle
      //calcul la somme des valeurs afin de determiner les angles
      float total = dat[0]+dat[1]+dat[2]+dat[3]+dat[4]+dat[5];
      /*for(i = 0; i<pie ; i++){
        total += dat[i];
      }*/
      if(total <= 0.0f) return ;
      float startangle = 0.0f;//angle de depart pour chaque ^part
      for (int i = 0; i< pie; i++){
        float scileangle = (dat[i]/total)* 2.0f*PI; //portion en radiant
        /*draw_list->PathClear();
        draw_list->PathLineTo(center);*/
        
        //dessiner les parts
        int numSegment = 40; //pour avoir un cercle plus lisse
        for(int j = 0;j<numSegment;j++){
          float t1 = startangle + scileangle*j/40.0f;//numSegment;
          float t2 = startangle + scileangle * (j+1) /40.0f;//numSegment;
           ImVec2 p1(center.x + radius* cos(t1), center.y + radius*sin(t1));
          ImVec2 p2(center.x + radius* cos(t2), center.y + radius*sin(t2));
          //draw_list->AddTriangleFilled(center,p1,p2,);
          draw_list->AddTriangleFilled(center,p1,p2,IM_COL32(100+i*50,100,255,255));
          }
          // --- Ajouter le label au milieu de la part ---
        /*float mid_angle = startangle + scileangle / 2.0f;
        ImVec2 label_pos(center.x + radius * 0.6f * cos(mid_angle),
                         center.y + radius * 0.6f * sin(mid_angle));*/
        //draw_list->AddText(label_pos, IM_COL32(0,0,0,255), label[i].c_str());
         //draw_list->PathFillConvex(colors[i]);
         

        startangle += scileangle;
 }
 ImGui::Dummy(ImVec2(radius * 2, radius * 2)); //reservation de l'espace
  
}
 
  
 