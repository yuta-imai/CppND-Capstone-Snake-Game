#ifndef FOOD_H
#define FOOD_H

#include <random>
#include <vector>
#include "SDL.h"
#include "snake.h"

class Food {
 public:
  Food(int grid_width, int grid_height, Snake *snake_)
    : snake(snake_),
      engine(dev()),
      random_w(0, grid_width),
      random_h(0, grid_height){}
  void UpdateLocation();
  bool IsAt(int, int);
  SDL_Point GetLocation();

private:
  SDL_Point location;
  Snake *snake;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};
#endif