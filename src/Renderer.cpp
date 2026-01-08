#include <iostream>
#include <SDL3/SDL.h> 
#include "Game.h"
#include"UI.h"  
#include <vector>    
#include"imgui.h"
#include"imgui_impl_sdl3.h"
#include"imgui_impl_sdlrenderer3.h"
#include <SDL3_image/SDL_image.h>



 int main(){
//Initialisation de SDL
if (!SDL_Init(SDL_INIT_VIDEO)!=0) { 
std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl; 
return 1; 
    } 
  //if(!IMG_Init)
std::cout << "SDL3 initialise avec succes ! 🎉" << std::endl; 
// Création de la fenêtre 
    SDL_Window* window = SDL_CreateWindow( 
"VISUALISEUR DE DONNEES SIMPLE",  // Titre 
1600, 900,                    // Largeur, Hauteur 
        SDL_WINDOW_RESIZABLE   // Options    
    ); 

if (!window) { 
std::cerr << "Erreur création fenêtre: " << SDL_GetError() << 
std::endl; 
        SDL_Quit(); 
return 1; 
    } 
// Création du renderer (pour dessiner) 
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr); 
if (!renderer) { 
std::cerr << "Erreur création renderer: " << SDL_GetError() << 
std::endl; 
        SDL_DestroyWindow(window); 
        SDL_Quit(); 
return 1; 
    } 
//  Boucle principale (le cœur qui bat !) 
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGui::StyleColorsDark();

ImGui_ImplSDL3_InitForSDLRenderer(window,renderer);
ImGui_ImplSDLRenderer3_Init(renderer);
 


//creation de la texture
SDL_Texture* texture = IMG_LoadTexture(renderer,"assets/OIP.png");

Game game;
   int optionchoisie;
   bool showBarChart = false;
   bool showMenu = true;
   bool showPieChart = false;
   bool running = true; 
   bool showBackground = true;
   bool showinput = false;
   static bool showInput = true;
   static bool showmenu = true;
   static bool showChart = false;
   bool choixval = false;

    SDL_Event event; 
    Uint64 lastime = SDL_GetTicks();
while (running) { 
  Uint64 now = SDL_GetTicks();
  float deltatime = (now - lastime)/ 1000.0f;
// Gestion des événements 
while (SDL_PollEvent(&event)) { 
    ImGui_ImplSDL3_ProcessEvent(&event);
if (event.type == SDL_EVENT_QUIT) { 
                running = false; 
            } 
        } 

       ImGui_ImplSDLRenderer3_NewFrame();
       ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
        
       
      
      static DiagramType currentDiagram = DiagramType::Rien;

    ImGui::Begin("Menu");
    ImGui::Text("veillez choisir une option:");
    ImGui::Separator();
   
       if(ImGui::Button("DIAGRAMME A BARRES")) //bouton pour l'affichage du diagramme a barre
       {
        currentDiagram = DiagramType::Barres;
        
      showBarChart = false;
      showPieChart = false;
      showMenu = false;
      showBackground = false;
      choixval = false;
       }
        if(ImGui::Button("DIAGRAMME EN CAMEMBERT")){
        currentDiagram =DiagramType::Camembert;
        showBarChart = false;
      showPieChart = false;
      showMenu = false;
      choixval = false; 
        }
       
        ImGui::Separator();
       
       if(currentDiagram == DiagramType::Barres){
       ImGui::Text("option selectionnée :  diagramme a barre");
       }else if (currentDiagram == DiagramType::Camembert)
       {
        ImGui::Text("option selectionnée : diagramme en camembert");

       }
     
    ImGui::End();

       if(currentDiagram == DiagramType::Barres){
          ImGui::Begin("veuillez entrer vos différents scores ");
            //interface de sdaisie utilisateur pour le diagramme à barres
           for(int i = 0;i< barcount;i++){
               ImGui::InputFloat(("valeurs" + std::to_string(i+1)).c_str(),&userdata[i]);
             }
             if(ImGui::Button("VALIDER")){
               showBarChart = true;
               showPieChart = false;
               showMenu = false;
               showBackground = false;
             }
  
          ImGui::End();
        }
      if(currentDiagram == DiagramType::Camembert){
          ImGui::Begin("veuillez entrer vos différents scores");
            //interface de sdaisie utilisateur pour le diagramme en camembert
           for(int i = 0;i< pie;i++){
               ImGui::InputFloat(("valeurs" + std::to_string(i+1)).c_str(),&dat[i]);
             }
             if(ImGui::Button("VALIDER")){
               showBarChart = false;
               showPieChart = true;
               showMenu = false;
               showBackground = false;
             }
  
          ImGui::End();
        }
    
       if(showPieChart){
       
        game.HandleEvents(renderer);
        //game.Render(renderer);
      
       }
      
        ImGui::Render();
// Dessine du fond de la fenetre
       SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
       //Effacer le menu precedent 
       SDL_RenderClear(renderer);

       SDL_RenderTexture(renderer,texture,NULL,NULL);
       SDL_SetRenderDrawColor(renderer,255,255,255,255);
       
       if(showBarChart){
        
        game.DrawDiagramme(renderer);
        
       }
       
       if(showMenu){
       
        showBarChart = false;
        showMenu = true;
      }
      
       
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(),renderer);
    
   // Affiche le tout

        SDL_RenderPresent(renderer); 

    } 
// Petite pause (pour ne pas cramer le CPU) 
        SDL_Delay(16); // ~60 FPS 
    //Nettoyage (on est bien élevés) 
   ImGui_ImplSDLRenderer3_Shutdown();
   ImGui_ImplSDL3_Shutdown();
   SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
std::cout << "Au revoir ! 👋" << std::endl; 
      return 0;  

}