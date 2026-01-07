#include<iostream>
#include "libs/imgui/imgui.h"
#include "libs/imgui/backends/imgui_impl_sdl3.h"
#include "libs/imgui/backends/imgui_impl_sdlrenderer3.h"
#include <SDL3/SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("yityecuy", 800, 600,SDL_WINDOW_RESIZABLE);
    SDL_Renderer* rendrerer = SDL_CreateRenderer(window, nullptr);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsClassic();

    ImGui_ImplSDL3_InitForSDLRenderer(window, rendrerer);
    ImGui_ImplSDLRenderer3_Init(rendrerer);

    bool runnig = true;
    bool show_demo = true;
    SDL_Event event;

    while (runnig)
    {
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
            {
                runnig = false;
            }
            
        }
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow(&show_demo);
        
        ImGui::Render();
    SDL_SetRenderDrawColor(rendrerer, 255, 60, 56, 255);
    SDL_RenderClear(rendrerer);

    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), rendrerer);
    SDL_RenderPresent(rendrerer);
    }
    ImGui_ImplSDLRenderer3_Shutdown(); 
    ImGui_ImplSDL3_Shutdown(); 
    ImGui::DestroyContext();
    
     SDL_DestroyRenderer(rendrerer); 
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
}