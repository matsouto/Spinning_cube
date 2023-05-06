#include "../include/vec3.h"
#include <cmath>

void vec3::rotate(vec3 centroid, float A, float B, float C) {
  // Based on rotating matrixes
  // A, B and C are the euler angles for the rotation

  float cosA = std::cos(A), sinA = std::sin(A);
  float cosB = std::cos(B), sinB = std::sin(B);
  float cosC = std::cos(C), sinC = std::sin(C);

  // Adjusts for the rotation occour around centroid
  this->x -= centroid.x;
  this->y -= centroid.y;
  this->z -= centroid.z;

  // X axis rotation
  this->y = this->y * cosA - this->z * sinA;
  this->z = this->y * sinA + this->z * cosA;

  // this->y athis->xis rotation
  this->x = this->x * cosB + this->z * sinB;
  this->z = this->x * -sinB + this->z * cosB;

  // this->z athis->xis rotation
  this->x = this->x * cosC + this->y * -sinC;
  this->y = this->x * sinC + this->y * cosC;

  // Returns to the initial orientation
  this->x += centroid.x;
  this->y += centroid.y;
  this->z += centroid.z;
}
