#include <iostream>
#include "food.h"

void Food::UpdateLocation() {
  std::cout << "Updating food location!" << std::endl;
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      location.x = x;
      location.y = y;
      return;
    }
  }
}

bool Food::IsAt(int target_x, int target_y){
  return (location.x == target_x && location.y == target_y);
}

SDL_Point Food::GetLocation() {
  return location;
}