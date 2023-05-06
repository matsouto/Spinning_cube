#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <vector>
#include <iostream>
#include "defs.h"

class Screen {

private:
  int rendererFlags = rendererFlags = SDL_RENDERER_ACCELERATED;
  int windowFlags = 0;
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Event e;

public:
  Screen();
  void drawPixel(float x, float y);
  void drawLine(float x1, float y1, float x2, float y2);
  void eventHandler();
  void show();
  void clear();
};
