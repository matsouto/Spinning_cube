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
      {SCREEN_WIDTH / 2.0 - CUBE_SIZE, SCREEN_HEIGHT / 2.0 - CUBE_SIZE, 100},
      {SCREEN_WIDTH / 2.0 + CUBE_SIZE, SCREEN_HEIGHT / 2.0 - CUBE_SIZE, 100},
      {SCREEN_WIDTH / 2.0 + CUBE_SIZE, SCREEN_HEIGHT / 2.0 + CUBE_SIZE, 100},
      {SCREEN_WIDTH / 2.0 - CUBE_SIZE, SCREEN_HEIGHT / 2.0 + CUBE_SIZE, 100},

      {SCREEN_WIDTH / 2.0 - CUBE_SIZE, SCREEN_HEIGHT / 2.0 - CUBE_SIZE, 100 + CUBE_SIZE * 2},
      {SCREEN_WIDTH / 2.0 + CUBE_SIZE, SCREEN_HEIGHT / 2.0 - CUBE_SIZE, 100 + CUBE_SIZE * 2},
      {SCREEN_WIDTH / 2.0 + CUBE_SIZE, SCREEN_HEIGHT / 2.0 + CUBE_SIZE, 100 + CUBE_SIZE * 2},
      {SCREEN_WIDTH / 2.0 - CUBE_SIZE, SCREEN_HEIGHT / 2.0 + CUBE_SIZE, 100 + CUBE_SIZE * 2},
  };

  // The centroid must be calculated in order to adjust the rotating point.
  // To do so, we must calculate the avarage of each point.
  vec3 centroid = {0, 0, 0};

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

    // myScreen->drawPixel(centroid.x, centroid.y);

    for (auto &point : cubeVertices) {
      point.rotate(centroid, 0.005, 0.01, 0.007);
    }

    // Draw the lines to create the figure
    for (int i = 0; i < 4; i++) {
      myScreen->drawLine(cubeVertices[i].x, cubeVertices[i].y,
                         cubeVertices[i + 4].x, cubeVertices[i + 4].y);

      if (i == 3) {
        myScreen->drawLine(cubeVertices[i].x, cubeVertices[i].y,
                           cubeVertices[0].x, cubeVertices[0].y);
        myScreen->drawLine(cubeVertices[i + 4].x, cubeVertices[i + 4].y,
                           cubeVertices[4].x, cubeVertices[4].y);

      } else {
        myScreen->drawLine(cubeVertices[i].x, cubeVertices[i].y,
                           cubeVertices[i + 1].x, cubeVertices[i + 1].y);
        myScreen->drawLine(cubeVertices[i + 4].x, cubeVertices[i + 4].y,
                           cubeVertices[i + 5].x, cubeVertices[i + 5].y);
      }
    }

    myScreen->show();
    myScreen->eventHandler();

    SDL_Delay(DELAY);
  }

  return 0;
}
