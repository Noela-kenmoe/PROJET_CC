#include <iostream>
#include "UI.h"
#include <SDL3/SDL.h>
#include "../libs/imgui/imgui.h"
#include "../libs/imgui/backends/imgui_impl_sdl3.h"
#include "../libs/imgui/backends/imgui_impl_sdlrenderer3.h"
#include<vector>
#include<cmath>
#include<SDL3_ttf/SDL_ttf.h>



void DrawPie(SDL_Renderer* renderer){
    
    static float a= 30.0f;
    static float b= 25.0f;
    static float c= 20.0f;
    static float d= 25.0f;


    //fenetre ImGui
      ImGui::SliderFloat("Valeur de a",&a,0.0f,100.0f);
      ImGui::SliderFloat("Valeur de b",&b,0.0f,100.0f);
      ImGui::SliderFloat("Valeur de c",&c,0.0f,100.0f);
      ImGui::SliderFloat("Valeur de d",&d,0.0f,100.0f);
    
    float total =a + b+ c + d;
      if(total<= 0.0f){
        ImGui::Text("aucune valeurs a afficher");
        ImGui::End();
        return;
      }  

    //contruction du diagramme
    
    float radius = 100.0f;
    ImVec2 centre = ImGui::GetCursorScreenPos();
     centre.x += radius;
     centre.y += radius;

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    
      std::vector<float> values = {a ,b ,c ,d};
      std::vector<ImU32> colors = {
        IM_COL32(255,0,0,255),
        IM_COL32(0,255,0,255),
        IM_COL32(0,0,255,255),
        IM_COL32(255,255,0,255)
      };

    //dessin du camembert
   float angle_start = 0.0f;
   
   for(int i = 0; i<values.size();i++){
    constexpr float PI = 3.14159265358979323846f;
    float angle_end = angle_start + (values[i] / total)* 2.0f * PI;
     draw_list->PathClear();
     draw_list->PathLineTo(centre);

       for(float A = angle_start; A <= angle_end; A +=0.0f){
         draw_list->PathLineTo(ImVec2(centre.x + cosf(A) * radius,centre.y + sinf(A)* radius));

       }
     draw_list->PathFillConvex(colors[i]);
     angle_start = angle_end;  
   }
   ImGui::Dummy(ImVec2(radius*2,radius*2));
   ImGui::End();
   
}



