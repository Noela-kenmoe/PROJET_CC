#include <iostream>
#include <SDL3/SDL.h>
#include "libs/imgui/imgui.h"

enum class TypeDiagram {
    Bar,
    Pie,
    Rien
};
 
void DrawPie();