#pragma once

struct vec3 {
  double x, y, z;
  void rotate(vec3 centroid, float A, float B, float C);
};
