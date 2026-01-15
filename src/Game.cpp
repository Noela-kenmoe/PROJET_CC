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

   float userdata[barcount]= {140, 90, 340, 540,280,480,50,230};//valeurs d'entrée
   float dat[pie] = {120,80,230,430,330,270};//pour l'animation
   float current [barcount]= {0,0,0,0,0,0,0,0};
   float currentbar[pie]= {0,0,0,0,0,0};
  const double PI=3.14159265358979323846;
  float maxval [barcount]={0,0,0,0,0,0,0,0};
  std::string lab[barcount]={"A","B","C","D","E","F","G","H"};
  
static Uint32 now = SDL_GetTicks();
Uint32 lastime = SDL_GetTicks();
float  deltatime = (now- lastime)/1000.0f;
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
        IM_COL32(139, 20, 147, 255),
        IM_COL32(123 , 255, 0, 293)
       };  
       std::vector<ImU32> couleurs = {
        IM_COL32(255, 0, 0, 255),
        IM_COL32(0, 0, 255, 255),
        IM_COL32(0, 255, 0, 255),
        IM_COL32(255,165,0,255),
        IM_COL32(255, 255, 0, 255),
        IM_COL32(128, 0, 128, 255),
        IM_COL32(255 , 20,147, 255),
        IM_COL32(139,69,19,255)
        
       };  
std::vector<std::string> labels={"A","B","C","D","E","F","G","H"};

void Game::DrawDiagramme(SDL_Renderer* renderer){

  //donnees fixes
    

  
  int Xstart =  330; //pour definir la position de depart sur X
  int Ystart = 700;//pour definir la position de depart sur Y
  int i;
  int barWidth = 60; // la largeur des barres
  int spacing= 40; //espace entre les barres
  int maxHeight = 600; //pour definir la auteur maximale du graphique
   //float* current;
   float Deltatime = 100.0f;
   
   float textX=600;
   float  textY= 400;
   float spacetext = 30;
  
   
    //gestion de l'animation
    float speed = 3.1f;
    
    for(int i = 0; i<pie;i++){
      if(current[i]<userdata[i]){
        currentbar[i] += speed;
      }
      if(current[i]>userdata[i]){
        current[i] = userdata[i];
      }
     }
     //trouver la valeur maximale pour normaliser les hauteurs des barres
    const float* data;
    float maxvalues = 1.0f;
      for(float v : userdata){
        if(v >maxvalues){
          maxvalues= v;
        }
        int barw = (barWidth-spacing*(barcount+1))/barcount;
      }
      
      SDL_SetRenderDrawColor(renderer,0,0,0,255);
      
      
      SDL_FRect bakc= {20,20,11500,850};
       SDL_RenderFillRect(renderer, &bakc);
      
   //Dessin des axes
    SDL_SetRenderDrawColor(renderer,0,0,255,255);
    //AXE x
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
      {255,20,147,255} ,  //couleur rose
      {139,69,19,255}     //couleur orange
    };
    
    
    //Dessin des barres avec les coordonnées 
      for (size_t i=0; i < barcount;i++){
        //mise a l'echelle ^pour eviter que les barres dépassent la fentre
        float echelle =userdata[i]/maxvalues;
        int barh = (userdata[i]/maxvalues)*maxHeight;
         
        SDL_FRect bar;
         bar.x = Xstart + spacing + i * (barWidth + spacing);
         bar.w = barWidth;
         bar.h = static_cast<int>(echelle*maxHeight);
         bar.y = Ystart - bar.h;//pour monter depuis l'axe X
         //description sur chaque bar
         
         SDL_SetRenderDrawColor(renderer,colors[i].r,colors[i].g,colors[i].b,colors[i].a);
         SDL_RenderFillRect(renderer, &bar);
          
         }


      SDL_SetRenderDrawColor(renderer,255,255,255,255);
 //SDL_Delay(2000);
  
 }
  

  void Game::Render(SDL_Renderer* renderer){
    
    float radius = 220.0f;
    std::vector<std::string> label={"A","B","C","D","E","F"};
    float startangle = 0.0f;
     float endangle;
     float step =   0.1f;

    ImDrawList* draw = ImGui::GetWindowDrawList();
    ImVec2 windowposition = ImGui::GetCursorScreenPos();//position de la fenetre
      ImVec2 center = ImGui::GetCursorScreenPos();
      center.x +=350; //pour determiner la position du diagramme dans la fenetre
      center.y += 150;

    //gestion de l'animation
    for(int i = 0; i<pie;i++){
      if(currentbar[i]<dat[i]){
        currentbar[i] += step;
      }
      if(currentbar[i]>dat[i]){
        current[i] = dat[i];
      }
    }

   float total = 0.0f;
      for(int i = 0;i<pie;i++){
        total +=currentbar[i] ;
      }
      //pour eviter la division par zero
    if(total == 0){
      total=1;
    }
    
     
;      //calcul la somme des valeurs afin de determiner les angles
      
       startangle = 0; //angle de depart pour la premiere part
      for(int i = 0; i< 6; i++){
        float scileangle = (currentbar[i]/total)*2.0f*PI;//afin d'obtenir les protions en degres
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
 
  void Game::Update(SDL_Renderer* renderer){
    /*ImVec2 mouseposition;
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
      float radius = (radius*1.1f);*/
  const float* values;
    const ImU32* colors;
    int count;
    ImVec2 center;
    float baseRadius;
    ImDrawList* draw = ImGui::GetWindowDrawList();
    ImVec2 mouse = ImGui::GetIO().MousePos;

    float total = 0.0f;
    for (int i = 0; i < count; i++)
        total += dat[i];

    std::vector<float> currentRadius;
    if ((int)currentRadius.size() != count)
        currentRadius.assign(count, baseRadius);

    float startAngle = 0.0f;
    float hoverRadius = baseRadius * 1.15f;
    float speed = 8.0f;

    for (int i = 0; i < count; i++)
    {
        float sliceAngle = (values[i] / total) * PI * 2.0f;
        float endAngle = startAngle + sliceAngle;

        // --- Détection souris ---
        float dx = mouse.x - center.x;
        float dy = mouse.y - center.y;
        float dist = sqrtf(dx * dx + dy * dy);

        float angle = atan2f(dy, dx);
        if (angle < 0) angle += PI * 2.0f;

        bool hovered =
            dist <= hoverRadius &&
            angle >= startAngle &&
            angle <= endAngle;

        // --- Animation rayon ---
        float target = hovered ? hoverRadius : baseRadius;
        currentRadius[i] += (target - currentRadius[i]) *
                            speed * ImGui::GetIO().DeltaTime;

        // --- Dessin ---
        draw->PathArcTo(center,
                        currentRadius[i],
                        startAngle,
                        endAngle,
                        40);

        draw->PathLineTo(center);
        draw->PathFillConvex(couleur[i]);

        // Tooltip optionnel
        if (hovered)
            ImGui::SetTooltip("Valeur : %.2f", values[i]);

        startAngle = endAngle;
    }
}
  void Game::Run(SDL_Renderer* renderer){

    ImGui::BeginGroup();//afin de garder les elements alignés
    ImGui::Text("LEGENDE");
    ImGui::Separator();
    for(int i = 0; i< barcount;i++){
      ImU32 u32_col = couleurs[i];// on recupere la couleur de la part
    ImVec4 car = ImGui::ColorConvertU32ToFloat4(u32_col);//conversion de la couleur de ImU32 pour obtenir un ImVec4
        ImGui::ColorButton(labels[i].c_str(),car,ImGuiColorEditFlags_NoTooltip,ImVec2(14,14));
        ImGui::SameLine();//pour mettre le texte sur la meme ligne que le carré
        //affichage label
        ImGui::Text("%s:%.1f",labels[i].c_str(),userdata[i]);
        }
        ImGui::EndGroup();
        ImGui::Separator();
        //AFFICHAGE DE LA DESCRIPTION
        //ImGui::TextWrapped("");
        
  }
 