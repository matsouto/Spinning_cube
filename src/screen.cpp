#include "../include/screen.h"
#include <SDL2/SDL.h>

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

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  this->renderer = SDL_CreateRenderer(this->window, -1, this->rendererFlags);

  if (!this->renderer) {
    std::cout << "Failed to create the renderer: " << SDL_GetError();
    exit(1);
  }
}
