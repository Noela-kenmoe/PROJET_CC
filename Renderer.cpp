#include <iostream>
#include <SDL3/SDL.h> 
#include "Game.h"
#include"UI.h"  
#include <vector>    
#include"imgui.h"
#include"imgui_impl_sdl3.h"
#include"imgui_impl_sdlrenderer3.h"
 int main(){
//Initialisation de SDL
if (!SDL_Init(SDL_INIT_VIDEO)!=0) { 
std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl; 
return 1; 
    } 
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

Game game;
int optionchoisie;

bool running = true; 
    SDL_Event event; 
while (running) { 
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
        
        //DrawPie();
      
      game.Render( renderer);
       // game.Run(renderer);
        ImGui::Render();
// Dessine du fond de la fenetre
       SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
       //Effacer le menu precedent 
       SDL_RenderClear(renderer);
       
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(),renderer);
    
   // Affiche le tout

        SDL_RenderPresent(renderer); 

    } 
// Petite pause (pour ne pas cramer le CPU) 
        SDL_Delay(16); // ~60 FPS 
    //Nettoyage (on est bien élevés) 
   ImGui_ImplSDLRenderer3_Shutdown();
   ImGui_ImplSDL3_Shutdown();
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
std::cout << "Au revoir ! 👋" << std::endl; 
      return 0;  

}