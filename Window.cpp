#include <Window.h>

tl::Window::Window(const std::string& title, int width, int height, int x, int y)
    : title(title), width(width), height(height), x(x), y(y)
{
}

tl::Window::~Window()
{
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
}

bool tl::Window::init()
{
  this->window = SDL_CreateWindow(this->title.c_str(), this->x, this->y, this->width, this->height, this->windowFlags);

  if(this->window != nullptr)
  {
    this->renderer = SDL_CreateRenderer(this->window, -1, this->rendererFlags);

    return this->renderer != nullptr;
  }

  return false;
}

void tl::Window::frameBegin()
{
  this->renderDrawColor();
}

void tl::Window::frameEnd()
{
  SDL_RenderPresent(this->renderer);
}

void tl::Window::renderDrawColor()
{
  auto getUint8 = [](float x) { return static_cast<Uint8>(x * 255); };
  SDL_SetRenderDrawColor(this->renderer, getUint8(this->clearColor[0]), getUint8(this->clearColor[1]),
                         getUint8(this->clearColor[2]), getUint8(this->clearColor[3]));
  SDL_RenderClear(this->renderer);
}

SDL_Window* tl::Window::getWindow() const
{
  return this->window;
}

SDL_Renderer* tl::Window::getRenderer() const
{
  return this->renderer;
}

void tl::Window::setClearColor(std::array<float, 4> x)
{
  this->clearColor = x;
}

void tl::Window::setWindowFlags(SDL_WindowFlags x)
{
  this->windowFlags = x;
}

void tl::Window::setRendererFlags(SDL_RendererFlags x)
{
  this->rendererFlags = x;
}
