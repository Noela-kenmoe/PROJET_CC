#include <iostream>
#include <SDL3/SDL.h>


enum class TypeDiagram {
    Bar,
    Pie,
    Rien
};
 
void DrawPie(SDL_Renderer* renderer);