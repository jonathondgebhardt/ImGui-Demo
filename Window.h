#pragma once

#include <SDL.h>
#include <array>
#include <string>

namespace tl
{
  class Window
  {
  public:
    Window(const std::string& title, int width, int height, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);
    virtual ~Window();

    bool init();

    void frameBegin();
    void frameEnd();
    void renderDrawColor();

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

    void setClearColor(std::array<float, 4> x);

    void setWindowFlags(SDL_WindowFlags x);
    void setRendererFlags(SDL_RendererFlags x);

  private:
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::string title;
    std::array<float, 4> clearColor = {0.0f, 0.0f, 0.0f, 0.0f};
    SDL_WindowFlags windowFlags;
    SDL_RendererFlags rendererFlags;
    int width = 0;
    int height = 0;
    int x = 0;
    int y = 0;
  };
} // namespace tl
