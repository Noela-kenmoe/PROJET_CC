#include <iostream>
#include <SDL3/SDL.h> 
#include "Game.h"  
#include <vector>    
 int main(){ 
//Initialisation de SDL
if (!SDL_Init(SDL_INIT_VIDEO)) { 
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

bool running = true; 
    SDL_Event event; 
while (running) { 
// Gestion des événements 
while (SDL_PollEvent(&event)) { 
if (event.type == SDL_EVENT_QUIT) { 
                running = false; 
            } 
        } 
// Dessine un fond bleu magnifique 
        SDL_SetRenderDrawColor(renderer, 55, 255, 145, 70); 
        SDL_RenderClear(renderer); 
// Affiche le tout 
    std::vector<int> values = {10,40,25,60,35};
    Game game;
    game.Render(renderer,values,50,50,400,300); 
        SDL_RenderPresent(renderer); 
// Petite pause (pour ne pas cramer le CPU) 
        SDL_Delay(16); // ~60 FPS 
    } 
//Nettoyage (on est bien élevés) 
 
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
std::cout << "Au revoir ! 👋" << std::endl; 
        
return 0;
}