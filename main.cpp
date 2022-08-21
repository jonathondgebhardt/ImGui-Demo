#include <GuiWindow.h>
#include <SDL.h>
#include <Window.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_sdlrenderer.h>
#include <imgui.h>
#include <iostream>
#include <sstream>

double ParseForumla(std::string x)
{
  double result = 0.0;

  // while(x.empty() == false)
  // {
  double lhs = 0.0;
  double rhs = 0.0;

  auto plusIdx = x.find('+');
  auto minusIdx = x.find('-');

  if(plusIdx != std::string::npos || minusIdx != std::string::npos)
  {
    if(plusIdx != std::string::npos)
    {
      std::istringstream(x.substr(0, plusIdx)) >> lhs;
      x = x.substr(plusIdx + 1);

      std::istringstream(x.substr(0, x.size())) >> rhs;

      result = rhs + lhs;
    }
    else if(minusIdx != std::string::npos)
    {
      std::istringstream(x.substr(0, plusIdx)) >> lhs;
      x = x.substr(plusIdx + 1);

      std::istringstream(x.substr(0, x.size())) >> rhs;

      result = rhs - lhs;
    }
  }
  // }

  return result;
}

int main(int, char**)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cerr << "Could not init SDL\n";
    std::exit(EXIT_FAILURE);
  }

  auto window = tl::Window("TimerList", 1280, 720);

  auto windowFlags = static_cast<SDL_WindowFlags>(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  window.setWindowFlags(windowFlags);

  auto rendererFlags = static_cast<SDL_RendererFlags>(SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  window.setRendererFlags(rendererFlags);

  window.setClearColor({0.45f, 0.55f, 0.60f, 1.00f});

  if(window.init() == false)
  {
    std::cerr << "Could not create window\n";
    std::exit(EXIT_FAILURE);
  }

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();
  ImGui_ImplSDL2_InitForSDLRenderer(window.getWindow(), window.getRenderer());
  ImGui_ImplSDLRenderer_Init(window.getRenderer());

  double result = 0;
  std::string formula;

  auto done = false;
  while(done == false)
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if(event.type == SDL_QUIT)
        done = true;
      if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE &&
         event.window.windowID == SDL_GetWindowID(window.getWindow()))
        done = true;
    }

    ImGui_ImplSDLRenderer_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    {
      ImGui::Begin("Calcutor");

      ImGui::Text("Formula: ");
      ImGui::SameLine();
      ImGui::Text(formula.c_str());

      ImGui::Text("Result: ");
      ImGui::SameLine();

      result = ParseForumla(formula);
      ImGui::Text("%.5f", result);

      if(ImGui::Button("7"))
      {
        formula += "7";
      }

      ImGui::SameLine();

      if(ImGui::Button("8"))
      {

        formula += "8";
      }

      ImGui::SameLine();

      if(ImGui::Button("9"))
      {
        formula += "9";
      }

      if(ImGui::Button("4"))
      {
        formula += "4";
      }

      ImGui::SameLine();

      if(ImGui::Button("5"))
      {
        formula += "5";
      }

      ImGui::SameLine();

      if(ImGui::Button("6"))
      {
        formula += "6";
      }

      if(ImGui::Button("1"))
      {
        formula += "1";
      }

      ImGui::SameLine();

      if(ImGui::Button("2"))
      {
        formula += "2";
      }

      ImGui::SameLine();

      if(ImGui::Button("3"))
      {
        formula += "3";
      }

      if(ImGui::Button("+"))
      {
        formula += "+";
      }

      ImGui::SameLine();

      if(ImGui::Button("-"))
      {
        formula += "-";
      }

      ImGui::SameLine();

      if(ImGui::Button("Clear"))
      {
        formula.clear();
      }

      ImGui::End();
    }

    ImGui::Render();
    window.frameBegin();
    ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    window.frameEnd();
  }

  ImGui_ImplSDLRenderer_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_Quit();

  std::exit(EXIT_SUCCESS);
}
