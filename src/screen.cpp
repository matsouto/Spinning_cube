#include "../include/screen.h"
#include <SDL2/SDL_render.h>

Screen::Screen() {

  // Initializing SDL_VIDEO
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL coudn't be initialized: " << SDL_GetError();
    exit(1);
  }

  this->window = SDL_CreateWindow("Spinning Cube", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, this->windowFlags);

  if (!this->window) {
    std::cout << "Failed to open " << SCREEN_WIDTH << " x " << SCREEN_HEIGHT
              << " window: " << SDL_GetError() << std::endl;
    exit(1);
  }

  // Creating a renderer
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  this->renderer = SDL_CreateRenderer(this->window, -1, this->rendererFlags);

  if (!this->renderer) {
    std::cout << "Failed to create the renderer: " << SDL_GetError();
    exit(1);
  }

  SDL_RenderSetScale(this->renderer, 1, 1);
}

void Screen::drawPixel(float x, float y) {
  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
  SDL_RenderDrawPoint(this->renderer, x, y);
}

void Screen::drawLine(float x1, float y1, float x2, float y2) {
  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
  SDL_RenderDrawLineF(this->renderer, x1, y1, x2, y2);
}

void Screen::show() { SDL_RenderPresent(this->renderer); }

void Screen::eventHandler() {
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
    case SDL_QUIT:
      SDL_Quit();
      exit(0);
    }
  }
}

void Screen::clear() {
  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
  SDL_RenderClear(this->renderer);
}
