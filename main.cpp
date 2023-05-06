#include "include/defs.h"
#include "include/screen.h"
#include "include/vec3.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_timer.h>
#include <cstring>
#include <iostream>
#include <vector>

int main() {

  auto myScreen = new Screen();

  std::vector<vec3> cubeVertices = {
      {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100},

      {100, 100, 200}, {200, 100, 200}, {200, 200, 200}, {100, 200, 200},
  };

  // The centroid must be calculated in order to adjust the rotating point.
  // To do so, we must calculate the avarage of each point.
  vec3 centroid = {0,0,0};

  for (auto &point : cubeVertices) {
    centroid.x += point.x;
    centroid.y += point.y;
    centroid.z += point.z;
  }
  centroid.x /= cubeVertices.size();
  centroid.y /= cubeVertices.size();
  centroid.z /= cubeVertices.size();

  while (true) {

    myScreen->clear();

    for (auto &point : cubeVertices) {
      myScreen->drawPixel(point.x, point.y);
    }

    myScreen->drawPixel(centroid.x,centroid.y);

    for (auto &point : cubeVertices) {
      point.rotate(centroid, 0.02, 0.01, 0.03);
    }

    myScreen->show();
    myScreen->eventHandler();

    SDL_Delay(DELAY);
  }

  return 0;
}
