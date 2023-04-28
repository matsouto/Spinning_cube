#pragma once

#include "global.h"
#include <SDL2/SDL.h>

class Screen {

private:
  int rendererFlags = rendererFlags = SDL_RENDERER_ACCELERATED;
  int windowFlags = 0;

public:
  SDL_Renderer *renderer;
  SDL_Window *window;
  Screen();
};
