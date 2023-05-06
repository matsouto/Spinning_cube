#include "include/screen.h"
#include <cstring>
#include <iostream>

int main() {

  auto myScreen = new Screen();

  while (true) {
    myScreen->input();
  }

  return 0;
}
